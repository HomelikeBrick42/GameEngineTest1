#include "brickpch.hpp"
#include "BrickEngine/Renderer/GraphicsContext.hpp"

#include "BrickEngine/Renderer/Renderer.hpp"

#include "Platform/Windows/WindowsOpenGLGraphicsContext.hpp"

namespace BrickEngine {

	Scope<GraphicsContext> GraphicsContext::Create(void* windowHandle)
	{
		switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
            BRICKENGINE_CORE_ASSERT(false, "RendererAPI::None is not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return CreateScope<WindowsOpenGLGraphicsContext>((GLFWwindow*)windowHandle);
        }

        BRICKENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
	}

}
