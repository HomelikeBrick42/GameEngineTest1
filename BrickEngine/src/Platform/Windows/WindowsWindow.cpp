#include "brickpch.hpp"
#include "Platform/Windows/WindowsWindow.hpp"

#include "BrickEngine/Events/KeyEvent.hpp"
#include "BrickEngine/Events/MouseEvent.hpp"
#include "BrickEngine/Events/WindowEvent.hpp"

#ifdef BRICKENGINE_PLATFORM_WINDOWS

namespace BrickEngine {

	static uint32_t s_WindowCount = 0;

	static void GLFWErrorCallback(int32_t error, const char* description)
	{
		Log::CoreError("GLFW Error ({0}): {1}", error, description);
	}

	Ref<Window> Window::Create(const WindowProps& props)
	{
		return CreateRef<WindowsWindow>(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		Log::CoreTrace("Creating window '{0}' ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height); 

		if (s_WindowCount == 0)
		{
			int32_t success = glfwInit();
			BRICKENGINE_CORE_ASSERT(success, "Could not initalize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
		}
		s_WindowCount++;

		m_WindowHandle = glfwCreateWindow((int32_t)m_Data.Width, (int32_t)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_WindowHandle);
		m_Context = GraphicsContext::Create(m_WindowHandle);
		m_Context->Bind();
		SetVSync(true);
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(m_WindowHandle);
		s_WindowCount--;
		if (s_WindowCount == 0)
			glfwTerminate();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void WindowsWindow::SetEventCallback(const EventCallbackFn& eventCallback)
	{
		m_Data.EventCallback = eventCallback;
		glfwSetWindowUserPointer(m_WindowHandle, &m_Data);

		glfwSetWindowSizeCallback(m_WindowHandle, [](GLFWwindow* window, int32_t width, int32_t height) -> void
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;
				data.EventCallback(WindowResizeEvent((uint32_t)width, (uint32_t)height));
			});

		glfwSetWindowPosCallback(m_WindowHandle, [](GLFWwindow* window, int32_t xPos, int32_t yPos) -> void
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.EventCallback(WindowMovedEvent(xPos, yPos));
			});

		glfwSetWindowFocusCallback(m_WindowHandle, [](GLFWwindow* window, int32_t focused) -> void
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (focused)
				{
				case GLFW_TRUE:
					data.EventCallback(WindowFocusEvent());
					break;
				case GLFW_FALSE:
					data.EventCallback(WindowLostFocusEvent());
					break;
				}
			});

		glfwSetWindowCloseCallback(m_WindowHandle, [](GLFWwindow* window) -> void
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.EventCallback(WindowCloseEvent());
			});

		glfwSetKeyCallback(m_WindowHandle, [](GLFWwindow* window, int32_t key, int32_t scancode, int32_t action, int32_t mods) -> void
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
					data.EventCallback(KeyPressedEvent((KeyCode)key, 0));
					break;
				case GLFW_REPEAT:
					data.EventCallback(KeyPressedEvent((KeyCode)key, 1));
					break;
				case GLFW_RELEASE:
					data.EventCallback(KeyReleasedEvent((KeyCode)key));
					break;
				}
			});

		glfwSetMouseButtonCallback(m_WindowHandle, [](GLFWwindow* window, int32_t button, int32_t action, int32_t mods) -> void
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
					data.EventCallback(MouseButtonPressedEvent((MouseButton)button));
					break;
				case GLFW_RELEASE:
					data.EventCallback(MouseButtonReleasedEvent((MouseButton)button));
					break;
				}
			});

		glfwSetCursorPosCallback(m_WindowHandle, [](GLFWwindow* window, double xPos, double yPos) -> void
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.EventCallback(MouseMovedEvent((float)xPos, (float)yPos));
			});

		glfwSetScrollCallback(m_WindowHandle, [](GLFWwindow* window, double xOffset, double yOffset) -> void
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.EventCallback(MouseScrolledEvent((float)xOffset, (float)yOffset));
			});
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled ? 1 : 0);
	}

}

#endif
