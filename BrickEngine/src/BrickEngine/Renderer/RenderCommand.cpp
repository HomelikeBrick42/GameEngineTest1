#include "brickpch.hpp"
#include "BrickEngine/Renderer/RenderCommand.hpp"

namespace BrickEngine {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}
