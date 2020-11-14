#include "brickpch.hpp"
#include "BrickEngine/Scene/Scene.hpp"

#include "BrickEngine/Scene/Entity.hpp"
#include "BrickEngine/Scene/Components.hpp"

#include "BrickEngine/Renderer/Renderer.hpp"

#pragma warning(push)
#pragma warning(disable : 4267)

namespace BrickEngine {

    Scene::Scene()
    {
    }

    Scene::~Scene()
    {
    }

    Entity Scene::CreateEntity(const std::string& name)
    {
        Entity entity(m_Registry.create(), this);
        entity.AddComponent<TagComponent>(name);
        entity.AddComponent<TransformComponent>();
        return entity;
    }

    void Scene::DestroyEntity(Entity entity)
    {
        if (entity.m_Scene == this)
            m_Registry.destroy(entity);
        else
            Log::Error("Attemped to destroy entity that is not of this scene!");
    }

    void Scene::OnUpdate(float dt)
    {
        m_Registry.view<NativeScriptComponent>().each([&](entt::entity id, NativeScriptComponent& nsc) -> void
            {
                if (!nsc.Instance)
                    nsc.InstantiateScript(Entity(id, this));
                nsc.Instance->OnUpdate(dt);
            });
    }

    void Scene::OnRender()
    {
        glm::mat4 viewProjection = glm::mat4(0.0f);
        auto cameras = m_Registry.view<TransformComponent, CameraComponent>();
        for (auto& id : cameras)
        {
            auto& tc = cameras.get<TransformComponent>(id);
            auto& cc = cameras.get<CameraComponent>(id);
            viewProjection = cc.ToMatrix() * glm::inverse(tc.ToMatrix());
            break;
        }

        if (viewProjection != glm::mat4(0.0f))
        {
            Renderer::Begin(viewProjection);
            auto objects = m_Registry.group<TransformComponent, MeshRendererComponent>();
            for (auto& id : objects)
            {
                auto& tc = objects.get<TransformComponent>(id);
                auto& msc = objects.get<MeshRendererComponent>(id);
                if (msc)
                    Renderer::Submit(msc.Mesh, msc.Shader, msc.Color, tc);
            }
            Renderer::End();
        }
    }

    void Scene::OnViewportResize(uint32_t width, uint32_t height)
    {
        m_Registry.view<CameraComponent>().each([&](entt::entity id, CameraComponent& cc) -> void
            {
                cc.Aspect = (float)width / (float)height;
            });
    }

}

#pragma warning(pop)
