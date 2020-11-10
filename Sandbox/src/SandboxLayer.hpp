#pragma once

#include <BrickEngine.hpp>

using namespace BrickEngine;

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

	virtual void OnEvent(Event& e) override
	{
	}
private:
};
