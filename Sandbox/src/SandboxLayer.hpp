#pragma once

#include <BrickEngine.hpp>

using namespace BrickEngine;

#include <imgui.h>

class SandboxLayer : public Layer
{
public:
	SandboxLayer()
		: Layer("SandboxLayer")
	{
	}

	~SandboxLayer()
	{
	}

	void OnUpdate() override
	{
	}

	void OnImGuiRender() override
	{
	}

	void OnEvent(Event& e) override
	{
	}
private:
};
