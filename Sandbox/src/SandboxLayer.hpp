#pragma once

#include <BrickEngine.hpp>

using namespace BrickEngine;

#include <imgui.h>

class SandboxLayer : public Layer
{
public:
	SandboxLayer()
		: Layer("Sandbox Layer")
	{
	}

	~SandboxLayer()
	{
	}

	virtual void OnUpdate() override
	{
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::End();
	}

	virtual void OnEvent(Event& e) override
	{
	}
private:
};
