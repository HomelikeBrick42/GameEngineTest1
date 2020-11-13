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

		m_Shader->SetFloat4("u_Color", glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
		m_Shader->Bind();
		m_VertexBuffer->Bind();
		RenderCommand::Draw(0, 3);
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Info");
		ImGui::Text("FPS: %g", m_FPS);
		ImGui::End();
	}

	void OnEvent(Event& e) override
	{
	}
private:
	Scene m_Scene;
	Entity m_Triangle;
	Ref<Shader> m_Shader;
	Ref<VertexBuffer> m_VertexBuffer;
private:
	float m_FPS = 0.0f;
};
