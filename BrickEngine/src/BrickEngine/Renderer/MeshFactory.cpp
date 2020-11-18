#include "brickpch.hpp"
#include "BrickEngine/Renderer/MeshFactory.hpp"

namespace BrickEngine {

    Ref<Mesh> MeshFactory::GenerateCube(const glm::vec3& size)
    {
        std::vector<Vertex> vertices = {
            // Front
            { glm::vec3(-0.5f * size.x,  0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec2(0.0f, 0.0f) },
            { glm::vec3( 0.5f * size.x,  0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec2(1.0f, 0.0f) },
            { glm::vec3( 0.5f * size.x, -0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec2(1.0f, 1.0f) },
            { glm::vec3(-0.5f * size.x, -0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec2(0.0f, 1.0f) },

            // Back
            { glm::vec3(-0.5f * size.x,  0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec2(1.0f, 0.0f) },
            { glm::vec3( 0.5f * size.x,  0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec2(0.0f, 0.0f) },
            { glm::vec3( 0.5f * size.x, -0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec2(0.0f, 1.0f) },
            { glm::vec3(-0.5f * size.x, -0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec2(1.0f, 1.0f) },

            // Left
            { glm::vec3(-0.5f * size.x,  0.5f * size.y, -0.5f * size.z), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
            { glm::vec3(-0.5f * size.x,  0.5f * size.y,  0.5f * size.z), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 0.0f) },
            { glm::vec3(-0.5f * size.x, -0.5f * size.y,  0.5f * size.z), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 1.0f) },
            { glm::vec3(-0.5f * size.x, -0.5f * size.y, -0.5f * size.z), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 1.0f) },

            // Right
            { glm::vec3( 0.5f * size.x,  0.5f * size.y, -0.5f * size.z), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 0.0f) },
            { glm::vec3( 0.5f * size.x,  0.5f * size.y,  0.5f * size.z), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
            { glm::vec3( 0.5f * size.x, -0.5f * size.y,  0.5f * size.z), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
            { glm::vec3( 0.5f * size.x, -0.5f * size.y, -0.5f * size.z), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 1.0f) },

            // Top
            { glm::vec3(-0.5f * size.x,  0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(0.0f, 0.0f) },
            { glm::vec3( 0.5f * size.x,  0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
            { glm::vec3( 0.5f * size.x,  0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
            { glm::vec3(-0.5f * size.x,  0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(0.0f, 1.0f) },

            // Bottom
            { glm::vec3(-0.5f * size.x, -0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
            { glm::vec3( 0.5f * size.x, -0.5f * size.y,  0.5f * size.z), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(0.0f, 0.0f) },
            { glm::vec3( 0.5f * size.x, -0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(0.0f, 1.0f) },
            { glm::vec3(-0.5f * size.x, -0.5f * size.y, -0.5f * size.z), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(1.0f, 1.0f) }
        };

        std::vector<uint32_t> indices = {
             0,  1,  2,  0,  2,  3, // Front
             7,  6,  4,  6,  5,  4, // Back
            11, 10,  8, 10,  9,  8, // Left
            12, 13, 14, 12, 14, 15, // Right
            16, 17, 18, 16, 18, 19, // Top
            23, 22, 20, 22, 21, 20, // Bottom
        };

        return CreateRef<Mesh>(vertices, indices);
    }

}
