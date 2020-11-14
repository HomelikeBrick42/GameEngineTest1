#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Scene/EntityScript.hpp"

namespace BrickEngine {

	struct TagComponent
	{
		std::string Name;

		TagComponent(const std::string& name = "Unamed TagComponent")
			: Name(name) {}
	};

	struct TransformComponent
	{
		glm::vec3 Position;
		glm::vec3 Rotation;
		glm::vec3 Scale;

		TransformComponent(const glm::vec3& position = glm::vec3(0.0f))
			: Position(position), Rotation(0.0f), Scale(1.0f) {}

		glm::mat4 ToMatrix() const
		{
			glm::mat4 rotationMatrix =
				glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)) *
				glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)) *
				glm::rotate(glm::mat4(1.0f), glm::radians(Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

			return
				glm::translate(glm::mat4(1.0f), Position) *
				rotationMatrix *
				glm::scale(glm::mat4(1.0f), Scale);
		}

		operator glm::mat4() const { return ToMatrix(); }
	};

	struct NativeScriptComponent
	{
		NativeScriptComponent() = default;
		~NativeScriptComponent()
		{
			if (Instance)
				DestroyScript();
		}

		EntityScript* Instance = nullptr;
		std::function<void(Entity)> InstantiateScript = nullptr;
		std::function<void()> DestroyScript = nullptr;

		template<typename T, typename... Args>
		void Bind(Args&&... args)
		{
			if (Instance)
				DestroyScript();
			InstantiateScript = [&](Entity entity)
			{
				Instance = new T(args...);
				Instance->m_Entity = entity;
				Instance->OnCreate();
			};
			DestroyScript = [&]()
			{
				Instance->OnDestroy();
				delete Instance;
				Instance = nullptr;
			};
		}
	};

}