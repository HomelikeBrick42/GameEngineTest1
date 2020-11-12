#include "brickpch.hpp"
#include "BrickEngine/Scene/Scene.hpp"

#include "BrickEngine/Scene/Entity.hpp"
#include "BrickEngine/Scene/Components.hpp"

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
        m_Registry.view<NativeScriptComponent>().each([&](entt::entity id, NativeScriptComponent& nsc)
            {
                if (!nsc.Instance)
                    nsc.InstantiateScript(Entity(id, this));
                nsc.Instance->OnUpdate(dt);
            });
    }

}

#pragma warning(pop)
