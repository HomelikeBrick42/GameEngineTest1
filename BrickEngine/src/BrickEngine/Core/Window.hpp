#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Events/Event.hpp"

namespace BrickEngine {

	struct WindowProps
	{
		std::string Title;
		uint32_t Width, Height;

		WindowProps(const std::string& title = "BrickEngine Window", uint32_t width = 1280, uint32_t height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void* GetNativeWindowHandle() = 0;

		virtual void SetEventCallback(const EventCallbackFn& eventCallback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		virtual void LockMouse(bool enabled) = 0;
		virtual bool GetMouseLocked() = 0;

		static Ref<Window> Create(const WindowProps& props = WindowProps());
	protected:
		Window() = default;
	};

}
