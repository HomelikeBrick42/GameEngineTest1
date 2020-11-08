#pragma once

#ifdef BRICKENGINE_PLATFORM_WINDOWS

extern BrickEngine::Application* BrickEngine::CreateApplication();

int main(int argc, char** argv)
{
	BrickEngine::Application* app = BrickEngine::CreateApplication();
	app->Run();
	delete app;
}

#else
#error BrickEngine only supports Windows!
#endif
