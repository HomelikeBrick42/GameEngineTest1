#pragma once

#include <BrickEngine.hpp>

using namespace BrickEngine;

#include <imgui.h>

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

class CameraControllerScript : public EntityScript
{
public:
	void OnCreate() override
	{
		m_Transform = &GetComponent<TransformComponent>();
	}

	void OnUpdate(float dt) override
	{
		float speed = Input::GetKey(KeyCode::LeftShift) ? 25.0f : 5.0f;

		glm::vec3 forward = glm::normalize(glm::vec3(glm::sin(glm::radians(m_Transform->Rotation.y)), 0.0f, glm::cos(glm::radians(m_Transform->Rotation.y))));
		glm::vec3 right = glm::normalize(glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));

		if (Input::GetKey(KeyCode::W))
			m_Transform->Position -= forward * speed * dt;
		if (Input::GetKey(KeyCode::S))
			m_Transform->Position += forward * speed * dt;
		if (Input::GetKey(KeyCode::A))
			m_Transform->Position += right * speed * dt;
		if (Input::GetKey(KeyCode::D))
			m_Transform->Position -= right * speed * dt;
		if (Input::GetKey(KeyCode::E))
			m_Transform->Position.y += speed * dt;
		if (Input::GetKey(KeyCode::Q))
			m_Transform->Position.y -= speed * dt;

		if (Input::GetKey(KeyCode::Up))
			m_Transform->Rotation.x += 75.0f * dt;
		if (Input::GetKey(KeyCode::Down))
			m_Transform->Rotation.x -= 75.0f * dt;
		if (Input::GetKey(KeyCode::Left))
			m_Transform->Rotation.y += 75.0f * dt;
		if (Input::GetKey(KeyCode::Right))
			m_Transform->Rotation.y -= 75.0f * dt;

		m_Transform->Rotation.x = glm::max(glm::min(m_Transform->Rotation.x, 90.0f), -90.0f);
	}
private:
	TransformComponent* m_Transform = nullptr;
};

class SandboxLayer : public Layer
{
public:
	SandboxLayer()
		: Layer("SandboxLayer") {}

	void OnAttach() override
	{
		m_Shader = Shader::Create("assets/shaders/FlatColor.vert.glsl", "assets/shaders/FlatColor.frag.glsl");
		m_Mesh = MeshFactory::GenerateCube(glm::vec3(1.0f, 1.0f, 1.0f));

		Entity cube = m_Scene.CreateEntity("Cube");
		cube.AddComponent<MeshRendererComponent>(m_Shader, m_Mesh, glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
		cube.AddComponent<NativeScriptComponent>().Bind<RotateScript>();

		Entity camera = m_Scene.CreateEntity("Camera");
		camera.GetComponent<TransformComponent>().Position.z = 3.0f;
		camera.AddComponent<CameraComponent>();
		camera.AddComponent<NativeScriptComponent>().Bind<CameraControllerScript>();
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
