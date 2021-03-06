#pragma once

#include "BrickEngine/Core/Window.hpp"

#ifdef BRICKENGINE_PLATFORM_WINDOWS

#include <GLFW/glfw3.h>

#include "Platform/Windows/WindowsOpenGLGraphicsContext.hpp"

namespace BrickEngine {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		~WindowsWindow();

		virtual void OnUpdate() override;

		virtual uint32_t GetWidth() const override { return m_Data.Width; }
		virtual uint32_t GetHeight() const override { return m_Data.Height; }

		virtual void* GetNativeWindowHandle() override { return m_WindowHandle; }

		virtual void SetEventCallback(const EventCallbackFn& eventCallback) override;
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override { return m_Data.VSync; }
		virtual void LockMouse(bool enabled) override;
		virtual bool GetMouseLocked() override { return m_MouseLocked; }
	private:
		GLFWwindow* m_WindowHandle = nullptr;
		Scope<GraphicsContext> m_Context = nullptr;
		bool m_MouseLocked = false;

		struct WindowData
		{
			std::string Title;
			uint32_t Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}

#endif
