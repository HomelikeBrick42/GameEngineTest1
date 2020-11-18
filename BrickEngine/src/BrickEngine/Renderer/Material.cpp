#include "brickpch.hpp"
#include "BrickEngine/Renderer/Material.hpp"

namespace BrickEngine {

	void Material::Bind(uint32_t slot)
	{
		m_Shader->Bind();
		m_Shader->SetFloat4("u_Color", m_Color);
		if (m_Texture)
		{
			m_Texture->Bind(slot);
			m_Shader->SetInt("u_Texture", slot);
		}
	}

	void Material::UnBind()
	{
		m_Shader->SetFloat4("u_Color", glm::vec4(1.0f));
		m_Shader->UnBind();
	}

}
