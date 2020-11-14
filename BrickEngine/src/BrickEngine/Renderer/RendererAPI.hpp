#pragma once

#include "BrickEngine/Core/Base.hpp"

namespace BrickEngine {

	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0,
			OpenGL = 1
		};
	public:
		virtual ~RendererAPI() = default;

		virtual void Init() = 0;
		virtual void SetClearColor(const glm::vec3& color) = 0;
		virtual void Clear() = 0;
		virtual void SetViewport(int32_t x, int32_t y, int32_t width, int32_t height) = 0;
		virtual void Draw(uint32_t first, uint32_t count) = 0;
		virtual void DrawIndexed(uint32_t count) = 0;

		static API GetAPI() { return s_API; }
		static Scope<RendererAPI> Create();
	protected:
		RendererAPI() = default;
	private:
		static API s_API;
	};

}
