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

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void WindowsOpenGLGraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}

}
