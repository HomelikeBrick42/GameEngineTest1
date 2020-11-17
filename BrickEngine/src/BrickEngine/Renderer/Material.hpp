#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Renderer/Shader.hpp"

namespace BrickEngine {

	class Material
	{
	public:
		Material(const Ref<Shader>& shader, const glm::vec4& color)
			: m_Shader(shader), m_Color(color) {}

		void Bind();
		void UnBind();

		Ref<Shader> GetShader() const { return m_Shader; }
		const glm::vec4& GetColor() const { return m_Color; }
		glm::vec4& GetColor() { return m_Color; }
	private:
		Ref<Shader> m_Shader;
		glm::vec4 m_Color;
	};

}
