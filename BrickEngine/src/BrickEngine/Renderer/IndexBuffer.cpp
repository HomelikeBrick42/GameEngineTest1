#include "brickpch.hpp"
#include "BrickEngine/Renderer/IndexBuffer.hpp"

#include "BrickEngine/Renderer/Renderer.hpp"

#include "Platform/OpenGL/OpenGLIndexBuffer.hpp"

namespace BrickEngine {

    Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
            BRICKENGINE_CORE_ASSERT(false, "RendererAPI::None is not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return CreateRef<OpenGLIndexBuffer>(indices, count);
        }

        BRICKENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}
