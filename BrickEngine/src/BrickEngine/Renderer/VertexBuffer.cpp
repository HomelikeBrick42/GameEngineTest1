#include "brickpch.hpp"
#include "BrickEngine/Renderer/VertexBuffer.hpp"

#include "BrickEngine/Renderer/Renderer.hpp"

#include "Platform/OpenGL/OpenGLVertexBuffer.hpp"

namespace BrickEngine {

    Ref<VertexBuffer> VertexBuffer::Create(void* data, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
            BRICKENGINE_CORE_ASSERT(false, "RendererAPI::None is not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return CreateRef<OpenGLVertexBuffer>(data, size);
        }

        BRICKENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}
