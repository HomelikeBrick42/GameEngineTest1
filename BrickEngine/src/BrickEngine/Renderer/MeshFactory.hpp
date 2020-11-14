#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Renderer/VertexBuffer.hpp"
#include "BrickEngine/Renderer/IndexBuffer.hpp"

namespace BrickEngine {

	class MeshFactory
	{
	public:
		static std::pair<Ref<VertexBuffer>, Ref<IndexBuffer>> GenerateCube(const glm::vec3& size);
	private:
		MeshFactory() = default;
	};

}
