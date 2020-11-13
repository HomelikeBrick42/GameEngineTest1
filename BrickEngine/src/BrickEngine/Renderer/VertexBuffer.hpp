#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "ShaderDataTypes.hpp"

namespace BrickEngine {

	struct VertexBufferLayoutElement
	{
		ShaderDataType Type;
		std::string Name;
		bool Normalized;
		uint32_t Size;
		uint32_t Offset;

		VertexBufferLayoutElement()
			: Type(ShaderDataType::Unknown), Name(""), Normalized(false), Size(0), Offset(0) {}
		VertexBufferLayoutElement(ShaderDataType type, const std::string& name, bool normalized = false)
			: Type(type), Name(name), Normalized(normalized), Size(GetShaderDataTypeSize(type)), Offset(0) {}
	};

	class VertexBufferLayout
	{
	public:
		VertexBufferLayout() = default;
		VertexBufferLayout(const std::vector<VertexBufferLayoutElement>& elements)
			: m_Elements(elements) { CalculateOffsetAndStride(); }
		VertexBufferLayout(std::initializer_list<VertexBufferLayoutElement> elements)
			: m_Elements(elements) { CalculateOffsetAndStride(); }

		uint32_t GetStride() const { return m_Stride; }

		const std::vector<VertexBufferLayoutElement>& GetElements() const { return m_Elements; }
	private:
		void CalculateOffsetAndStride()
		{
			uint32_t offset = 0;
			m_Stride = 0;
			for (auto& element : m_Elements)
			{
				element.Offset = offset;
				offset += element.Size;
				m_Stride += element.Size;
			}
		}
	private:
		std::vector<VertexBufferLayoutElement> m_Elements;
		uint32_t m_Stride;
	};

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void SetLayout(const VertexBufferLayout& layout) = 0;
		virtual const VertexBufferLayout& GetLayout() const = 0;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetData(void* data, uint32_t size) = 0;

		static Ref<VertexBuffer> Create(void* data, uint32_t size);
	protected:
		VertexBuffer() = default;
	};

}
