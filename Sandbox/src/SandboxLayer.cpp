#include "pch.hpp"
#include "SandboxLayer.hpp"

#include "Scripts.hpp"

void SandboxLayer::OnAttach()
{
	m_Shader = Shader::Create("assets/shaders/FlatColor.vert.glsl", "assets/shaders/FlatColor.frag.glsl");
	m_Mesh = MeshFactory::GenerateCube(glm::vec3(1.0f, 1.0f, 1.0f));
	m_Texture = Texture2D::Create("assets/textures/Checkerboard.png");

	Ref<Material> material = CreateRef<Material>(m_Shader, m_Texture, glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));

	Entity cube = m_Scene.CreateEntity("Cube");
	cube.AddComponent<MeshRendererComponent>(material, m_Mesh);
	cube.AddComponent<NativeScriptComponent>().Bind<RotateScript>();

	Entity camera = m_Scene.CreateEntity("Camera");
	camera.GetComponent<TransformComponent>().Position.z = 3.0f;
	camera.AddComponent<CameraComponent>();
	camera.AddComponent<NativeScriptComponent>().Bind<CameraControllerScript>();
}

void SandboxLayer::OnDetach()
{
}

void SandboxLayer::OnUpdate(float dt)
{
	if (Input::GetKeyDown(KeyCode::Escape))
		Application::Get().GetWindow()->LockMouse(m_CursorLocked = !m_CursorLocked);

	m_FPS = 1.0f / dt;
	m_Scene.OnUpdate(dt);

	RenderCommand::SetClearColor(glm::vec3(0.1f, 0.1f, 0.1f));
	RenderCommand::Clear();
	m_Scene.OnRender();
}

void SandboxLayer::OnImGuiRender()
{
	ImGui::Begin("Info");
	ImGui::Text("FPS: %g", m_FPS);
	ImGui::End();
}

void SandboxLayer::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowResizeEvent>([&](WindowResizeEvent& e) -> bool
		{
			RenderCommand::SetViewport(0, 0, e.GetWidth(), e.GetHeight());
			m_Scene.OnViewportResize(e.GetWidth(), e.GetHeight());
			return false;
		});
}
