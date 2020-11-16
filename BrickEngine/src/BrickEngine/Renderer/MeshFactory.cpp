#include "brickpch.hpp"
#include "BrickEngine/Renderer/MeshFactory.hpp"

namespace BrickEngine {

    Ref<Mesh> MeshFactory::GenerateCube(const glm::vec3& size)
    {
        std::vector<Vertex> vertices = {
            // Front
            { glm::vec3(-0.5f * size.x,  0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec2(0.0f, 1.0f) },
            { glm::vec3( 0.5f * size.x,  0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec2(1.0f, 1.0f) },
            { glm::vec3( 0.5f * size.x, -0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec2(1.0f, 0.0f) },
            { glm::vec3(-0.5f * size.x, -0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec2(0.0f, 0.0f) },

            // Back
            { glm::vec3(-0.5f * size.x,  0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec2(0.0f, 1.0f) },
            { glm::vec3( 0.5f * size.x,  0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec2(1.0f, 1.0f) },
            { glm::vec3( 0.5f * size.x, -0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec2(1.0f, 0.0f) },
            { glm::vec3(-0.5f * size.x, -0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec2(0.0f, 0.0f) },

            // Top
            { glm::vec3(-0.5f * size.x,  0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(0.0f, 1.0f) },
            { glm::vec3( 0.5f * size.x,  0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
            { glm::vec3( 0.5f * size.x,  0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
            { glm::vec3(-0.5f * size.x,  0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(0.0f, 0.0f) },

            // Bottom
            { glm::vec3(-0.5f * size.x, -0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(0.0f, 1.0f) },
            { glm::vec3( 0.5f * size.x, -0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
            { glm::vec3( 0.5f * size.x, -0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
            { glm::vec3(-0.5f * size.x, -0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(0.0f, 0.0f) },

            // Right
            { glm::vec3( 0.5f * size.x,  0.5f * size.y, -0.5f * size.z), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 1.0f) },
            { glm::vec3( 0.5f * size.x,  0.5f * size.y,  0.5f * size.z), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
            { glm::vec3( 0.5f * size.x, -0.5f * size.y,  0.5f * size.z), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
            { glm::vec3( 0.5f * size.x, -0.5f * size.y, -0.5f * size.z), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 0.0f) },

            // Left
            { glm::vec3(-0.5f * size.x,  0.5f * size.y, -0.5f * size.z), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 1.0f) },
            { glm::vec3(-0.5f * size.x,  0.5f * size.y,  0.5f * size.z), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
            { glm::vec3(-0.5f * size.x, -0.5f * size.y,  0.5f * size.z), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
            { glm::vec3(-0.5f * size.x, -0.5f * size.y, -0.5f * size.z), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 0.0f) }
        };

        std::vector<uint32_t> indices = {
             0,  1,  2,  0,  2,  3, // Front
             6,  5,  4,  7,  6,  4, // Back
             8,  9, 10,  8, 10, 11, // Top
            12, 13, 14, 12, 14, 15, // Bottom
            16, 17, 18, 16, 18, 19, // Right
            22, 21, 20, 23, 22, 20, // Left
        };

        return CreateRef<Mesh>(vertices, indices);
    }

}
