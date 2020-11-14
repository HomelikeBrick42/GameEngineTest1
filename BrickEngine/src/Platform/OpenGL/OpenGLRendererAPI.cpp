#include "brickpch.hpp"
#include "Platform/OpenGL/OpenGLRendererAPI.hpp"

#include <glad/glad.h>

namespace BrickEngine {

	void OpenGLMessageCallback(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char* message,
		const void* userParam)
	{
		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:         Log::CoreFatal(message); return;
		case GL_DEBUG_SEVERITY_MEDIUM:       Log::CoreError(message); return;
		case GL_DEBUG_SEVERITY_LOW:          Log::CoreWarn(message); return;
		case GL_DEBUG_SEVERITY_NOTIFICATION: Log::CoreTrace(message); return;
		}

		Log::CoreTrace(message);
	}

	void OpenGLRendererAPI::Init()
	{
#ifdef BRICKENGINE_DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
	}

	void OpenGLRendererAPI::SetClearColor(const glm::vec3& color)
	{
		glClearColor(color.r, color.g, color.b, 1.0f);
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::SetViewport(int32_t x, int32_t y, int32_t width, int32_t height)
	{
		glViewport(x, y, width, height);
	}

	void OpenGLRendererAPI::Draw(uint32_t first, uint32_t count)
	{
		glDrawArrays(GL_TRIANGLES, first, count);
	}

	void OpenGLRendererAPI::DrawIndexed(uint32_t count)
	{
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
	}

}
