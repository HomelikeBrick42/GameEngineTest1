#include "brickpch.hpp"
#include "BrickEngine/Renderer/Mesh.hpp"

namespace BrickEngine {

	Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<uint32_t>& indices)
		: m_VertexBuffer(nullptr), m_IndexBuffer(nullptr), m_Vertices(vertices), m_Indices(indices)
	{
		m_VertexBuffer = VertexBuffer::Create(m_Vertices.data(), static_cast<uint32_t>(m_Vertices.size() * sizeof(Vertex)));
		m_VertexBuffer->SetLayout(Vertex::GetLayout());
		m_IndexBuffer = IndexBuffer::Create(m_Indices.data(), static_cast<uint32_t>(m_Indices.size()));
	}

	void Mesh::Bind()
	{
		m_VertexBuffer->Bind();
		m_IndexBuffer->Bind();
		if (m_ToUpdateVertexData)
		{
			m_VertexBuffer->SetData(m_Vertices.data(), static_cast<uint32_t>(m_Vertices.size() * sizeof(Vertex)));
			m_ToUpdateVertexData = false;
		}
		if (m_ToUpdateIndexData)
		{
			m_VertexBuffer->SetData(m_Indices.data(), static_cast<uint32_t>(m_Indices.size()));
			m_ToUpdateIndexData = false;
		}
	}

	void Mesh::UnBind()
	{
		m_VertexBuffer->UnBind();
		m_IndexBuffer->UnBind();
	}

}
