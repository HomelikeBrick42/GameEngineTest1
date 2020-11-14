#pragma once

#include <BrickEngine.hpp>

using namespace BrickEngine;

#include <imgui.h>

class SandboxLayer : public Layer
{
public:
	SandboxLayer()
		: Layer("SandboxLayer") {}

	void OnAttach() override
	{
		m_Triangle = m_Scene.CreateEntity("Triangle");

		m_Shader = Shader::Create("assets/shaders/FlatColor.vert.glsl", "assets/shaders/FlatColor.frag.glsl");

		float vertices[] = {
			 0.0f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f
		};
		m_VertexBuffer = VertexBuffer::Create(vertices, sizeof(vertices));
		m_VertexBuffer->SetLayout({
			{ ShaderDataType::Float3, "a_Position" }
		});

		uint32_t indices[] = {
			0, 1, 2
		};
		m_IndexBuffer = IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
	}

	void OnDetach() override
	{
	}

	void OnUpdate(float dt) override
	{
		m_FPS = 1.0f / dt;
		m_Scene.OnUpdate(dt);

		RenderCommand::SetClearColor(glm::vec3(0.1f, 0.1f, 0.1f));
		RenderCommand::Clear();

		m_Shader->Bind();
		m_Shader->SetFloat4("u_Color", glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
		m_VertexBuffer->Bind();
		m_IndexBuffer->Bind();
		RenderCommand::DrawIndexed(m_IndexBuffer->GetCount());
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Info");
		ImGui::Text("FPS: %g", m_FPS);
		ImGui::End();
	}

	void OnEvent(Event& e) override
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowResizeEvent>([&](WindowResizeEvent& e) -> bool
			{
				RenderCommand::SetViewport(0, 0, e.GetWidth(), e.GetHeight());
				return false;
			});
	}
private:
	Scene m_Scene;
	Entity m_Triangle;
	Ref<Shader> m_Shader;
	Ref<VertexBuffer> m_VertexBuffer;
	Ref<IndexBuffer> m_IndexBuffer;
private:
	float m_FPS = 0.0f;
};
