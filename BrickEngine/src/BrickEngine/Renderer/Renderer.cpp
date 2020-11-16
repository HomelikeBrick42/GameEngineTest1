#include "brickpch.hpp"
#include "BrickEngine/Renderer/Renderer.hpp"

namespace BrickEngine {

	struct RendererData
	{
		glm::mat4 ViewProjection;
	};
	static Scope<RendererData> s_Data = nullptr;

	void Renderer::Init()
	{
		s_Data = CreateScope<RendererData>();
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
		shader->SetFloatMatrix4x4("u_Model", transform);
		mesh->Bind();
		RenderCommand::DrawIndexed(mesh->GetIndexCount());
	}

	void Renderer::End()
	{
	}

}
