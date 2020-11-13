#pragma once

#include "BrickEngine/Renderer/VertexBuffer.hpp"

namespace BrickEngine {

	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(void* data, uint32_t size);
		~OpenGLVertexBuffer();

		virtual void SetLayout(const VertexBufferLayout& layout) override;
		virtual const VertexBufferLayout& GetLayout() const override { return m_Layout; }

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void SetData(void* data, uint32_t size) override;
	private:
		uint32_t m_RendererID, m_VertexArrayID;
		VertexBufferLayout m_Layout;
	};

}
