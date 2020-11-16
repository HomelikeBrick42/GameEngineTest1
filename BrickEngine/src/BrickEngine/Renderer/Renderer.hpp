#pragma once

#include "BrickEngine/Core/Base.hpp"
#include "BrickEngine/Renderer/RendererAPI.hpp"
#include "BrickEngine/Renderer/RenderCommand.hpp"

#include "BrickEngine/Renderer/Shader.hpp"
#include "BrickEngine/Renderer/Mesh.hpp"

namespace BrickEngine {

	class Renderer
	{
	public:
		Renderer() = delete;
		static void Init();
		static void Shutdown();

		static void Begin(const glm::mat4& viewProjection);
		static void Submit(const Ref<Mesh> mesh, const Ref<Shader> shader, const glm::vec4& color, const glm::mat4& transform = glm::mat4(1.0f));
		static void End();

		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};

}
