#pragma once

#include "BrickEngine/Core/Base.hpp"

#include "BrickEngine/Core/Application.hpp"

#include "BrickEngine/Scene/EntityScript.hpp"

#include "BrickEngine/Renderer/Shader.hpp"
#include "BrickEngine/Renderer/Mesh.hpp"

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
			return
				glm::translate(glm::mat4(1.0f), Position) *
				(glm::mat4)glm::quat(glm::radians(Rotation)) *
				glm::scale(glm::mat4(1.0f), Scale);
		}

		operator glm::mat4() const { return ToMatrix(); }
	};

	struct CameraComponent
	{
		float Fov;
		float Aspect;
		float Near;
		float Far;

		CameraComponent()
			: Fov(glm::radians(45.0f)), Aspect((float)Application::Get().GetWindow()->GetWidth() / (float)Application::Get().GetWindow()->GetHeight()), Near(0.001f), Far(1000.0f) {}
		CameraComponent(float fov, float aspect, float _near, float _far)
			: Fov(fov), Aspect(aspect), Near(_near), Far(_far) {}

		glm::mat4 ToMatrix() const
		{
			return glm::perspective(Fov, Aspect, Near, Far);
		}

		operator glm::mat4() const { return ToMatrix(); }
	};

	struct MeshRendererComponent
	{
		Ref<Shader> Shader;
		Ref<Mesh> Mesh;
		glm::vec4 Color;
		
		MeshRendererComponent()
			: Shader(nullptr), Mesh(nullptr), Color(1.0f) {}
		MeshRendererComponent(const Ref<BrickEngine::Shader>& shader, const Ref<BrickEngine::Mesh>& mesh, const glm::vec4& color)
			: Shader(shader), Mesh(mesh), Color(color) {}

		operator bool() const { return Shader != nullptr && Mesh != nullptr; }
	};

	struct NativeScriptComponent
	{
		EntityScript* Instance = nullptr;
		void(*InstantiateScript)(EntityScript*&, Entity) = nullptr;
		void(*DestroyScript)(EntityScript*&) = nullptr;

		template<typename T, typename... Args>
		void Bind(Args&&... args)
		{
			if (Instance)
				DestroyScript(Instance);
			InstantiateScript = [](EntityScript*& script, Entity entity)
			{
				script = new T(args...);
				script->m_Entity = entity;
				script->OnCreate();
			};
			DestroyScript = [](EntityScript*& script)
			{
				script->OnDestroy();
				delete script;
			};
		}
	};

}
