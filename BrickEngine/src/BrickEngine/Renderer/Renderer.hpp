#pragma once

#include "BrickEngine/Core/Base.hpp"
#include "BrickEngine/Renderer/RendererAPI.hpp"
#include "BrickEngine/Renderer/RenderCommand.hpp"

namespace BrickEngine {

	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();

		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};

}
