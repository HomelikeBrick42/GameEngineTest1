#include "brickpch.hpp"
#include "BrickEngine/Core/Application.hpp"

#include "BrickEngine/Events/WindowEvent.hpp"
#include "BrickEngine/Core/Input.hpp"

#include <glad/glad.h>

namespace BrickEngine {

	Application* Application::s_Application = nullptr;

	Application::Application(const WindowProps& props)
	{
		Log::Init();
		Input::Init();

		BRICKENGINE_CORE_ASSERT(!s_Application, "Application already exists!");
		s_Application = this;

		m_Window = Window::Create(props);
		m_Window->SetEventCallback(BRICKENGINE_BIND_FN(OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		auto lastFrame = std::chrono::high_resolution_clock::now();
		auto time = std::chrono::high_resolution_clock::now();
		float delta;
		while (m_Running)
		{
			time = std::chrono::high_resolution_clock::now();
			delta = std::chrono::duration<float>(time - lastFrame).count();
			lastFrame = time;

			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(delta);

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->End();

			Input::EndFrame();
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>([&](WindowCloseEvent& e) -> bool
			{
				m_Running = false;
				return false;
			});

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}
		
		Input::OnEvent(e);
	}

}
