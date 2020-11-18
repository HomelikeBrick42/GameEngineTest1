#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Renderer/Shader.hpp"
#include "BrickEngine/Renderer/Texture2D.hpp"

namespace BrickEngine {

	class Material
	{
	public:
		Material(const Ref<Shader>& shader, const glm::vec4& color)
			: m_Shader(shader), m_Texture(nullptr), m_Color(color) {}
		Material(const Ref<Shader>& shader, const Ref<Texture2D>& texture, const glm::vec4& color)
			: m_Shader(shader), m_Texture(texture), m_Color(color) {}

		void Bind(uint32_t slot = 0);
		void UnBind();

		Ref<Texture2D> GetTexture() const { return m_Texture; }
		Ref<Shader> GetShader() const { return m_Shader; }
		const glm::vec4& GetColor() const { return m_Color; }
		glm::vec4& GetColor() { return m_Color; }
	private:
		Ref<Shader> m_Shader;
		Ref<Texture2D> m_Texture;
		glm::vec4 m_Color;
	};

}
