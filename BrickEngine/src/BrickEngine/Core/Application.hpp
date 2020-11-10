#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Core/Window.hpp"
#include "BrickEngine/Core/LayerStack.hpp"
#include "BrickEngine/ImGui/ImGuiLayer.hpp"

namespace BrickEngine {

	class Application
	{
	public:
		Application(const WindowProps& props = WindowProps());
		virtual ~Application();

		void Run();

		static Application& Get() { return *s_Application; }
		Ref<Window> GetWindow() const { return m_Window; }

		void PushLayer(Layer* layer) { m_LayerStack.PushLayer(layer); }
		void PushOverlay(Layer* overlay) { m_LayerStack.PushOverlay(overlay); }
		void PopLayer(Layer* layer) { m_LayerStack.PopLayer(layer); }
		void PopOverlay(Layer* overlay) { m_LayerStack.PopOverlay(overlay); }
	private:
		void OnEvent(Event& e);
	private:
		Ref<Window> m_Window = nullptr;
		bool m_Running = true;
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer = nullptr;
	private:
		static Application* s_Application;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
