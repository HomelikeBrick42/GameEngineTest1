#pragma once

#include "BrickEngine/Renderer/GraphicsContext.hpp"

#include <GLFW/glfw3.h>

namespace BrickEngine {

	class OpenGLGraphicsContext : public GraphicsContext
	{
	public:
		OpenGLGraphicsContext(GLFWwindow* window);

		virtual void Bind() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_Window = nullptr;
 	};

}
