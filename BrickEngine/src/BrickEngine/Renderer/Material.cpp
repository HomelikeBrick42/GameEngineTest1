#include "brickpch.hpp"
#include "BrickEngine/Renderer/Material.hpp"

namespace BrickEngine {

	void Material::Bind()
	{
		m_Shader->Bind();
		m_Shader->SetFloat4("u_Color", m_Color);
	}

	void Material::UnBind()
	{
		m_Shader->SetFloat4("u_Color", glm::vec4(1.0f));
		m_Shader->UnBind();
	}

}
