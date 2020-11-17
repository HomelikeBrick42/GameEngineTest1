#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Renderer/Vertex.hpp"
#include "BrickEngine/Renderer/VertexBuffer.hpp"
#include "BrickEngine/Renderer/IndexBuffer.hpp"

namespace BrickEngine {

	class Mesh
	{
	public:
		Mesh(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices);

		void Bind();
		void UnBind();

		uint32_t GetIndexCount() const { return static_cast<uint32_t>(m_Indices.size()); }

		std::vector<Vertex>& GetVertices() { return m_Vertices; }
		std::vector<uint32_t>& GetIndices() { return m_Indices; }
		const std::vector<Vertex>& GetVertices() const { return m_Vertices; }
		const std::vector<uint32_t>& GetIndices() const { return m_Indices; }
	private:
		Ref<VertexBuffer> m_VertexBuffer;
		Ref<IndexBuffer> m_IndexBuffer;
		std::vector<Vertex> m_Vertices;
		std::vector<uint32_t> m_Indices;
		bool m_ToUpdateVertexData = false;
		bool m_ToUpdateIndexData = false;
	};

}
