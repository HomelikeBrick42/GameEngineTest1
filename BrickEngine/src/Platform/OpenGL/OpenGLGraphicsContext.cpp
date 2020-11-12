#include "brickpch.hpp"
#include "Platform/OpenGL/OpenGLGraphicsContext.hpp"

#include <glad/glad.h>

namespace BrickEngine {

	OpenGLGraphicsContext::OpenGLGraphicsContext(GLFWwindow* window)
		: m_Window(window)
	{
	}

	void OpenGLGraphicsContext::Bind()
	{
		glfwMakeContextCurrent(m_Window);
		int32_t success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BRICKENGINE_CORE_ASSERT(success, "Failed to initalize GLAD!");
	}

	void OpenGLGraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}

}
