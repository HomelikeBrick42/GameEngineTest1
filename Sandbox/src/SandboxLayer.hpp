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
		class RotateScript : public EntityScript
		{
		public:
			void OnCreate() override
			{
				m_Transform = &GetComponent<TransformComponent>();
			}

			void OnUpdate(float dt) override
			{
				m_Transform->Rotation.x += 45.0f * dt;
				m_Transform->Rotation.y += 30.0f * dt;
			}
		private:
			TransformComponent* m_Transform = nullptr;
		};
		m_Triangle = m_Scene.CreateEntity("Triangle");
		m_Triangle.AddComponent<NativeScriptComponent>().Bind<RotateScript>();

		m_Shader = Shader::Create("assets/shaders/FlatColor.vert.glsl", "assets/shaders/FlatColor.frag.glsl");

		m_Mesh = MeshFactory::GenerateCube(glm::vec3(1.0f, 1.0f, 1.0f));
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

		Renderer::Begin(m_ViewProjection);
		Renderer::Submit(m_Mesh, m_Shader, glm::vec4(1.0f, 1.0f, 0.0f, 1.0f), m_Triangle.GetComponent<TransformComponent>());
		Renderer::End();
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
				m_ViewProjection =
					glm::perspective(
						glm::radians(45.0f),
						(float)Application::Get().GetWindow()->GetWidth() / (float)Application::Get().GetWindow()->GetHeight(),
						0.001f,
						1000.0f
					) *
					glm::inverse(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 3.0f)));
				return false;
			});
	}
private:
	Scene m_Scene;
	Entity m_Triangle;
	Ref<Shader> m_Shader;
	Ref<Mesh> m_Mesh;
	glm::mat4 m_ViewProjection =
		glm::perspective(
			glm::radians(45.0f),
			(float)Application::Get().GetWindow()->GetWidth() / (float)Application::Get().GetWindow()->GetHeight(),
			0.001f,
			1000.0f
		) *
		glm::inverse(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 3.0f)));
private:
	float m_FPS = 0.0f;
};
