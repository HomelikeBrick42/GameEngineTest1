#pragma once

#include "BrickEngine/Core/Base.hpp"
#include "BrickEngine/Renderer/RendererAPI.hpp"

namespace BrickEngine {

	class RenderCommand
	{
	public:
		static void Init() { s_RendererAPI->Init(); }
		static void SetClearColor(const glm::vec3& color) { s_RendererAPI->SetClearColor(color); }
		static void Clear() { s_RendererAPI->Clear(); }
	private:
		static Scope<RendererAPI> s_RendererAPI;
	};

}
