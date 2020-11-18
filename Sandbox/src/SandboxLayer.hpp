#pragma once

#include "pch.hpp"

class SandboxLayer : public Layer
{
public:
	SandboxLayer()
		: Layer("SandboxLayer") {}

	void OnAttach() override;
	void OnDetach() override;
	void OnUpdate(float dt) override;
	void OnImGuiRender() override;
	void OnEvent(Event& e) override;
private:
	Scene m_Scene;
	Ref<Shader> m_Shader;
	Ref<Mesh> m_Mesh;
	Ref<Texture2D> m_Texture;
	bool m_CursorLocked = false;
private:
	float m_FPS = 0.0f;
};
