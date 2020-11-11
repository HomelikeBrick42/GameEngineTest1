#include "brickpch.hpp"
#include "BrickEngine/Core/Input.hpp"

#include "BrickEngine/Events/WindowEvent.hpp"
#include "BrickEngine/Events/KeyEvent.hpp"
#include "BrickEngine/Events/MouseEvent.hpp"

namespace BrickEngine {

    struct InputData
    {
        std::array<bool, 350> Keys;
        std::array<bool, 350> KeysDown;
        std::array<bool, 350> KeysUp;

        std::array<bool, 8> MouseButtons;
        std::array<bool, 8> MouseButtonsDown;
        std::array<bool, 8> MouseButtonsUp;
    };
    static Scope<InputData> s_Data = nullptr;

    void Input::Init()
    {
        s_Data = CreateScope<InputData>();
        for (uint32_t i = 0; i < 350; i++)
        {
            s_Data->Keys[i] = false;
            s_Data->KeysDown[i] = false;
            s_Data->KeysUp[i] = false;
        }
        for (uint32_t i = 0; i < 8; i++)
        {
            s_Data->MouseButtons[i] = false;
            s_Data->MouseButtonsDown[i] = false;
            s_Data->MouseButtonsUp[i] = false;
        }
    }

    void Input::EndFrame()
    {
        for (uint32_t i = 0; i < 350; i++)
        {
            s_Data->KeysDown[i] = false;
            s_Data->KeysUp[i] = false;
        }
        for (uint32_t i = 0; i < 8; i++)
        {
            s_Data->MouseButtonsDown[i] = false;
            s_Data->MouseButtonsUp[i] = false;
        }
    }

    bool Input::GetKey(KeyCode key)
    {
        BRICKENGINE_CORE_ASSERT((int32_t)key < 0 && (int32_t)key > 348, "Attempted to get invalid key: {0}", (int32_t)key);
        return s_Data->Keys[(int32_t)key];
    }

    bool Input::GetKeyDown(KeyCode key)
    {
        BRICKENGINE_CORE_ASSERT((int32_t)key < 0 && (int32_t)key > 348, "Attempted to get invalid key: {0}", (int32_t)key);
        return s_Data->KeysDown[(int32_t)key];
    }

    bool Input::GetKeyUp(KeyCode key)
    {
        BRICKENGINE_CORE_ASSERT((int32_t)key < 0 && (int32_t)key > 348, "Attempted to get invalid key: {0}", (int32_t)key);
        return s_Data->KeysUp[(int32_t)key];
    }

    bool Input::GetMouseButton(MouseButton button)
    {
        BRICKENGINE_CORE_ASSERT((int32_t)button < 0 && (int32_t)button > 8, "Attempted to get invalid mouse button: {0}", (int32_t)button);
        return s_Data->MouseButtons[(int32_t)button];
    }

    bool Input::GetMouseButtonDown(MouseButton button)
    {
        BRICKENGINE_CORE_ASSERT((int32_t)button < 0 && (int32_t)button > 8, "Attempted to get invalid mouse button: {0}", (int32_t)button);
        return s_Data->MouseButtonsDown[(int32_t)button];
    }

    bool Input::GetMouseButtonUp(MouseButton button)
    {
        BRICKENGINE_CORE_ASSERT((int32_t)button < 0 && (int32_t)button > 8, "Attempted to get invalid mouse button: {0}", (int32_t)button);
        return s_Data->MouseButtonsUp[(int32_t)button];
    }

    void Input::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<KeyPressedEvent>([](KeyPressedEvent& e) -> bool
            {
                if (!s_Data->Keys[(int32_t)e.GetKeyCode()])
                    s_Data->KeysDown[(int32_t)e.GetKeyCode()] = true;
                s_Data->Keys[(int32_t)e.GetKeyCode()] = true;
                return false;
            });
        dispatcher.Dispatch<KeyReleasedEvent>([](KeyReleasedEvent& e) -> bool
            {
                if (s_Data->Keys[(int32_t)e.GetKeyCode()])
                    s_Data->KeysUp[(int32_t)e.GetKeyCode()] = true;
                s_Data->Keys[(int32_t)e.GetKeyCode()] = false;
                return false;
            });

        dispatcher.Dispatch<MouseButtonPressedEvent>([](MouseButtonPressedEvent& e) -> bool
            {
                if (!s_Data->MouseButtons[(int32_t)e.GetMouseButton()])
                    s_Data->MouseButtonsDown[(int32_t)e.GetMouseButton()] = true;
                s_Data->MouseButtons[(int32_t)e.GetMouseButton()] = true;
                return false;
            });
        dispatcher.Dispatch<MouseButtonReleasedEvent>([](MouseButtonReleasedEvent& e) -> bool
            {
                if (s_Data->MouseButtons[(int32_t)e.GetMouseButton()])
                    s_Data->MouseButtonsUp[(int32_t)e.GetMouseButton()] = true;
                s_Data->MouseButtons[(int32_t)e.GetMouseButton()] = false;
                return false;
            });

        dispatcher.Dispatch<WindowLostFocusEvent>([](WindowLostFocusEvent& e) -> bool
            {
                for (uint32_t i = 0; i < 350; i++)
                {
                    s_Data->Keys[i] = false;
                    s_Data->KeysDown[i] = false;
                    s_Data->KeysUp[i] = false;
                }
                for (uint32_t i = 0; i < 8; i++)
                {
                    s_Data->MouseButtons[i] = false;
                    s_Data->MouseButtonsDown[i] = false;
                    s_Data->MouseButtonsUp[i] = false;
                }
                return false;
            });
    }

}
