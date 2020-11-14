#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Renderer/Mesh.hpp"

namespace BrickEngine {

	class MeshFactory
	{
	public:
		static Ref<Mesh> GenerateCube(const glm::vec3& size);
	private:
		MeshFactory() = default;
	};

}
