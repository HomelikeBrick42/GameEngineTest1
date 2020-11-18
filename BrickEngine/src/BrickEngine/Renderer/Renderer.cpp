#include "brickpch.hpp"
#include "BrickEngine/Renderer/Renderer.hpp"

namespace BrickEngine {

	struct RendererData
	{
		glm::mat4 ViewProjection;
		Ref<Texture2D> WhitePixelTexture;
	};
	static Scope<RendererData> s_Data = nullptr;

	void Renderer::Init()
	{
		s_Data = CreateScope<RendererData>();
		s_Data->WhitePixelTexture = Texture2D::Create(1, 1);
		uint32_t whitePixel = 0xffffffff;
		s_Data->WhitePixelTexture->SetData(&whitePixel, sizeof(uint32_t));
		RenderCommand::Init();
	}

	void Renderer::Shutdown()
	{
	}

	void Renderer::Begin(const glm::mat4& viewProjection)
	{
		s_Data->ViewProjection = viewProjection;
	}

	void Renderer::Submit(const Ref<Mesh> mesh, const Ref<Shader> shader, const glm::vec4& color, const glm::mat4& transform)
	{
		shader->Bind();
		shader->SetFloatMatrix4x4("u_ViewProjection", s_Data->ViewProjection);
		shader->SetFloatMatrix4x4("u_Model", transform);
		shader->SetFloat4("u_Color", color);
		mesh->Bind();
		s_Data->WhitePixelTexture->Bind(16);
		shader->SetInt("u_Texture", 16);
		RenderCommand::DrawIndexed(mesh->GetIndexCount());
	}

	void Renderer::Submit(const Ref<Mesh> mesh, const Ref<Material> material, const glm::mat4& transform)
	{
		Ref<Shader> shader = material->GetShader();
		shader->SetFloatMatrix4x4("u_ViewProjection", s_Data->ViewProjection);
		shader->SetFloatMatrix4x4("u_Model", transform);
		mesh->Bind();
		material->Bind(0);
		if (!material->GetTexture())
		{
			s_Data->WhitePixelTexture->Bind(16);
			shader->SetInt("u_Texture", 16);
		}
		RenderCommand::DrawIndexed(mesh->GetIndexCount());
	}

	void Renderer::End()
	{
	}

}
