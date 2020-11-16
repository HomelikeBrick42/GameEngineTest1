#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Renderer/VertexBuffer.hpp"

namespace BrickEngine {

	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoord;

		Vertex()
			: Position(0.0f), Normal(0.0f), TexCoord(0.0f) {}
		Vertex(const glm::vec3& position)
			: Position(position), Normal(0.0f), TexCoord(0.0f) {}
		Vertex(const glm::vec3& position, const glm::vec3& normal)
			: Position(position), Normal(normal), TexCoord(0.0f) {}
		Vertex(const glm::vec3& position, const glm::vec3& normal, const glm::vec2& texcoord)
			: Position(position), Normal(normal), TexCoord(texcoord) {}

		static VertexBufferLayout GetLayout()
		{
			return VertexBufferLayout{
				{ ShaderDataType::Float3, "a_Position" },
				{ ShaderDataType::Float3, "a_Normal"   },
				{ ShaderDataType::Float2, "a_TexCoord" }
			};
		}
	};

}
