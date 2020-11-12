#include "brickpch.hpp"
#include "Platform/Windows/WindowsOpenGLGraphicsContext.hpp"

#include <glad/glad.h>

namespace BrickEngine {

	WindowsOpenGLGraphicsContext::WindowsOpenGLGraphicsContext(GLFWwindow* window)
		: m_Window(window)
	{
	}

	void WindowsOpenGLGraphicsContext::Bind()
	{
		glfwMakeContextCurrent(m_Window);
		int32_t success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BRICKENGINE_CORE_ASSERT(success, "Failed to initalize GLAD!");
	}

	void WindowsOpenGLGraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}

}
