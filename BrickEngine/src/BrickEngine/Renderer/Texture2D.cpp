#include "brickpch.hpp"
#include "BrickEngine/Renderer/Texture2D.hpp"

#include "BrickEngine/Renderer/Renderer.hpp"

#include "Platform/OpenGL/OpenGLTexture2D.hpp"

namespace BrickEngine {

    Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
            BRICKENGINE_CORE_ASSERT(false, "RendererAPI::None is not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return CreateRef<OpenGLTexture2D>(width, height);
        }

        BRICKENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<Texture2D> Texture2D::Create(const std::string& path)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
            BRICKENGINE_CORE_ASSERT(false, "RendererAPI::None is not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return CreateRef<OpenGLTexture2D>(path);
        }

        BRICKENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}
