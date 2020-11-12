#pragma once

#include <BrickEngine.hpp>

using namespace BrickEngine;

#include <imgui.h>

class SandboxLayer : public Layer
{
public:
	SandboxLayer()
		: Layer("SandboxLayer") {}

	void OnAttach() override
	{
		m_Triangle = m_Scene.CreateEntity("Triangle");
	}

	void OnDetach() override
	{
	}

	void OnUpdate(float dt) override
	{
		m_Scene.OnUpdate(dt);
	}

	void OnImGuiRender() override
	{
	}

	void OnEvent(Event& e) override
	{
	}
private:
	Scene m_Scene;
	Entity m_Triangle;
};
