#pragma once

#include "BrickEngine/Renderer/GraphicsContext.hpp"

#include <GLFW/glfw3.h>

namespace BrickEngine {

	class WindowsOpenGLGraphicsContext : public GraphicsContext
	{
	public:
		WindowsOpenGLGraphicsContext(GLFWwindow* window);

		virtual void Bind() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_Window = nullptr;
 	};

}
