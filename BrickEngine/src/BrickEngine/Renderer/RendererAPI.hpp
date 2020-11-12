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

		static API GetAPI() { return s_API; }
		static Scope<RendererAPI> Create();
	protected:
		RendererAPI() = default;
	private:
		static API s_API;
	};

}
