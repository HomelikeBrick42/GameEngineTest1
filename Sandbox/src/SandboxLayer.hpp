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
		m_Shader = Shader::Create("assets/shaders/FlatColor.vert.glsl", "assets/shaders/FlatColor.frag.glsl");
		m_Mesh = MeshFactory::GenerateCube(glm::vec3(1.0f, 1.0f, 1.0f));

		class RotateScript : public EntityScript
		{
		public:
			void OnCreate() override
			{
				m_Transform = &GetComponent<TransformComponent>();
			}

			void OnUpdate(float dt) override
			{
				m_Transform->Rotation.x += 35.0f * dt;
				m_Transform->Rotation.y += 25.0f * dt;
			}
		private:
			TransformComponent* m_Transform = nullptr;
		};

		Entity cube = m_Scene.CreateEntity("Cube");
		cube.AddComponent<NativeScriptComponent>().Bind<RotateScript>();
		cube.AddComponent<MeshRendererComponent>(m_Shader, m_Mesh, glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));

		Entity camera = m_Scene.CreateEntity("Camera");
		camera.GetComponent<TransformComponent>().Position.z = 3.0f;
		camera.AddComponent<CameraComponent>();
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
		m_Scene.OnRender();
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
				m_Scene.OnViewportResize(e.GetWidth(), e.GetHeight());
				return false;
			});
	}
private:
	Scene m_Scene;
	Ref<Shader> m_Shader;
	Ref<Mesh> m_Mesh;
private:
	float m_FPS = 0.0f;
};
