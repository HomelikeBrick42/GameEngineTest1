#pragma once

#include "BrickEngine/Core/Base.hpp"

namespace BrickEngine {

	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void SetFloatMatrix2x2Array(const std::string& name, const glm::mat2x2* matrix, uint32_t count) = 0;
		virtual void SetFloatMatrix2x2(const std::string& name, const glm::mat2x2& matrix) = 0;
		virtual void SetFloatMatrix2x3Array(const std::string& name, const glm::mat2x3* matrix, uint32_t count) = 0;
		virtual void SetFloatMatrix2x3(const std::string& name, const glm::mat2x3& matrix) = 0;
		virtual void SetFloatMatrix2x4Array(const std::string& name, const glm::mat2x4* matrix, uint32_t count) = 0;
		virtual void SetFloatMatrix2x4(const std::string& name, const glm::mat2x4& matrix) = 0;
		virtual void SetFloatMatrix3x2Array(const std::string& name, const glm::mat3x2* matrix, uint32_t count) = 0;
		virtual void SetFloatMatrix3x2(const std::string& name, const glm::mat3x2& matrix) = 0;
		virtual void SetFloatMatrix3x3Array(const std::string& name, const glm::mat3x3* matrix, uint32_t count) = 0;
		virtual void SetFloatMatrix3x3(const std::string& name, const glm::mat3x3& matrix) = 0;
		virtual void SetFloatMatrix3x4Array(const std::string& name, const glm::mat3x4* matrix, uint32_t count) = 0;
		virtual void SetFloatMatrix3x4(const std::string& name, const glm::mat3x4& matrix) = 0;
		virtual void SetFloatMatrix4x2Array(const std::string& name, const glm::mat4x2* matrix, uint32_t count) = 0;
		virtual void SetFloatMatrix4x2(const std::string& name, const glm::mat4x2& matrix) = 0;
		virtual void SetFloatMatrix4x3Array(const std::string& name, const glm::mat4x3* matrix, uint32_t count) = 0;
		virtual void SetFloatMatrix4x3(const std::string& name, const glm::mat4x3& matrix) = 0;
		virtual void SetFloatMatrix4x4Array(const std::string& name, const glm::mat4x4* matrix, uint32_t count) = 0;
		virtual void SetFloatMatrix4x4(const std::string& name, const glm::mat4x4& matrix) = 0;

		virtual void SetIntArray(const std::string& name, const int32_t* values, uint32_t count) = 0;
		virtual void SetInt(const std::string& name, int32_t value) = 0;
		virtual void SetInt2Array(const std::string& name, const glm::ivec2* values, uint32_t count) = 0;
		virtual void SetInt2(const std::string& name, const glm::ivec2& value) = 0;
		virtual void SetInt3Array(const std::string& name, const glm::ivec3* values, uint32_t count) = 0;
		virtual void SetInt3(const std::string& name, const glm::ivec3& value) = 0;
		virtual void SetInt4Array(const std::string& name, const glm::ivec4* values, uint32_t count) = 0;
		virtual void SetInt4(const std::string& name, const glm::ivec4& value) = 0;

		virtual void SetUIntArray(const std::string& name, const uint32_t* values, uint32_t count) = 0;
		virtual void SetUInt(const std::string& name, uint32_t value) = 0;
		virtual void SetUInt2Array(const std::string& name, const glm::uvec2* values, uint32_t count) = 0;
		virtual void SetUInt2(const std::string& name, const glm::uvec2& value) = 0;
		virtual void SetUInt3Array(const std::string& name, const glm::uvec3* values, uint32_t count) = 0;
		virtual void SetUInt3(const std::string& name, const glm::uvec3& value) = 0;
		virtual void SetUInt4Array(const std::string& name, const glm::uvec4* values, uint32_t count) = 0;
		virtual void SetUInt4(const std::string& name, const glm::uvec4& value) = 0;

		virtual void SetFloatArray(const std::string& name, const float* values, uint32_t count) = 0;
		virtual void SetFloat(const std::string& name, float value) = 0;
		virtual void SetFloat2Array(const std::string& name, const glm::vec2* values, uint32_t count) = 0;
		virtual void SetFloat2(const std::string& name, const glm::vec2& value) = 0;
		virtual void SetFloat3Array(const std::string& name, const glm::vec3* values, uint32_t count) = 0;
		virtual void SetFloat3(const std::string& name, const glm::vec3& value) = 0;
		virtual void SetFloat4Array(const std::string& name, const glm::vec4* values, uint32_t count) = 0;
		virtual void SetFloat4(const std::string& name, const glm::vec4& value) = 0;

		static Ref<Shader> Create(const std::string& vertexPath, const std::string& fragmentPath);
	protected:
		Shader() = default;
	};

}
