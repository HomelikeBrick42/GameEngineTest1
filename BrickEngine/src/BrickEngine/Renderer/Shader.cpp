#include "brickpch.hpp"
#include "BrickEngine/Renderer/Shader.hpp"

#include "BrickEngine/Renderer/Renderer.hpp"

#include "Platform/OpenGL/OpenGLShader.hpp"

namespace BrickEngine {

    Ref<Shader> Shader::Create(const std::string& vertexPath, const std::string& fragmentPath)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
            BRICKENGINE_CORE_ASSERT(false, "RendererAPI::None is not supported!");
            return nullptr;
        case RendererAPI::API::OpenGL:
            return CreateRef<OpenGLShader>(vertexPath, fragmentPath);
        }

        BRICKENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}
