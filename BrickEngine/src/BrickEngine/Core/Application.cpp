#include "brickpch.hpp"
#include "BrickEngine/Core/Application.hpp"

#include "BrickEngine/Events/WindowEvent.hpp"

namespace BrickEngine {

	Application::Application(const WindowProps& props)
	{
		Log::Init();

		m_Window = Window::Create(props);
		m_Window->SetEventCallback(BRICKENGINE_BIND_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
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
	}

}
