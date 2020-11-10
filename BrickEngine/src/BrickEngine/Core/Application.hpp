#pragma once

#include "BrickEngine/Core/Base.hpp"
#include "BrickEngine/Core/Window.hpp"
#include "BrickEngine/Events/Event.hpp"

namespace BrickEngine {

	class Application
	{
	public:
		Application(const WindowProps& props = WindowProps());
		virtual ~Application();

		void Run();
	private:
		void OnEvent(Event& e);
	private:
		Ref<Window> m_Window = nullptr;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
