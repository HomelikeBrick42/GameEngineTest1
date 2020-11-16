#include "brickpch.hpp"
#include "Platform/OpenGL/OpenGLVertexBuffer.hpp"

#include <glad/glad.h>

namespace BrickEngine {

	inline uint32_t ShaderDataTypeToOpenGLType(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Bool:
		case ShaderDataType::Bool2:
		case ShaderDataType::Bool3:
		case ShaderDataType::Bool4:
			return GL_BOOL;
		case ShaderDataType::Byte:
		case ShaderDataType::Byte2:
		case ShaderDataType::Byte3:
		case ShaderDataType::Byte4:
			return GL_BYTE;
		case ShaderDataType::UByte:
		case ShaderDataType::UByte2:
		case ShaderDataType::UByte3:
		case ShaderDataType::UByte4:
			return GL_UNSIGNED_BYTE;
		case ShaderDataType::Short:
		case ShaderDataType::Short2:
		case ShaderDataType::Short3:
		case ShaderDataType::Short4:
			return GL_SHORT;
		case ShaderDataType::UShort:
		case ShaderDataType::UShort2:
		case ShaderDataType::UShort3:
		case ShaderDataType::UShort4:
			return GL_UNSIGNED_SHORT;
		case ShaderDataType::Int:
		case ShaderDataType::Int2:
		case ShaderDataType::Int3:
		case ShaderDataType::Int4:
			return GL_INT;
		case ShaderDataType::UInt:
		case ShaderDataType::UInt2:
		case ShaderDataType::UInt3:
		case ShaderDataType::UInt4:
			return GL_UNSIGNED_INT;
		case ShaderDataType::Float:
		case ShaderDataType::Float2:
		case ShaderDataType::Float3:
		case ShaderDataType::Float4:
			return GL_FLOAT;
		}

		BRICKENGINE_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(void* data, uint32_t size)
	{
		glGenVertexArrays(1, &m_VertexArrayID);
		glBindVertexArray(m_VertexArrayID);

		glGenBuffers(1, &m_RendererID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteVertexArrays(1, &m_VertexArrayID);
		glDeleteBuffers(1, &m_RendererID);
	}

	void OpenGLVertexBuffer::SetLayout(const VertexBufferLayout& layout)
	{
		m_Layout = layout;
		glBindVertexArray(m_VertexArrayID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);

		uint32_t index = 0;
		for (const auto& element : m_Layout.GetElements())
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index,
				GetShaderDataTypeCount(element.Type),
				ShaderDataTypeToOpenGLType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				m_Layout.GetStride(),
				(const void*)(size_t)element.Offset
			);
			index++;
		}
	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindVertexArray(m_VertexArrayID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void OpenGLVertexBuffer::UnBind() const
	{
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void OpenGLVertexBuffer::SetData(void* data, uint32_t size)
	{
		glBindVertexArray(m_VertexArrayID);
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
	}

}
