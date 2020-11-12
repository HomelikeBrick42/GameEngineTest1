#pragma once

#include "BrickEngine/Renderer/RendererAPI.hpp"

namespace BrickEngine {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;
		virtual void SetClearColor(const glm::vec3& color) override;
		virtual void Clear() override;
		virtual void Draw(uint32_t first, uint32_t count) override;
		virtual void DrawIndexed(uint32_t count) override;
	};

}
