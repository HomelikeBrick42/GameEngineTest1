#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Renderer/VertexBuffer.hpp"
#include "BrickEngine/Renderer/IndexBuffer.hpp"

namespace BrickEngine {

	class Mesh
	{
	public:
		Mesh(const Ref<VertexBuffer>& vertexBuffer, const Ref<IndexBuffer>& indexBuffer)
			: m_VertexBuffer(vertexBuffer), m_IndexBuffer(indexBuffer) {}

		void Bind() { if (m_VertexBuffer) m_VertexBuffer->Bind(); if (m_IndexBuffer) m_IndexBuffer->Bind(); }
		void UnBind() { if (m_VertexBuffer) m_VertexBuffer->UnBind(); if (m_IndexBuffer) m_IndexBuffer->UnBind(); }

		void SetVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) { m_VertexBuffer = vertexBuffer; }
		void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) { m_IndexBuffer = indexBuffer; }
		Ref<VertexBuffer> GetVertexBuffer() const { return m_VertexBuffer; }
		Ref<IndexBuffer> GetIndexBuffer() const { return m_IndexBuffer; }
	private:
		Ref<VertexBuffer> m_VertexBuffer;
		Ref<IndexBuffer> m_IndexBuffer;
	};

}
