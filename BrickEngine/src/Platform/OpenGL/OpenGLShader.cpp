#include "brickpch.hpp"
#include "Platform/OpenGL/OpenGLShader.hpp"

#include <glad/glad.h>

namespace BrickEngine {

    OpenGLShader::OpenGLShader(const std::string& vertexPath, const std::string& fragmentPath)
    {
        std::ifstream vertexIn(vertexPath);
        std::stringstream vertexFile;
        vertexFile << vertexIn.rdbuf();
        std::string vertexSource = vertexFile.str();
        uint32_t vertexShader = CreateShader(GL_VERTEX_SHADER, vertexSource.c_str());

        std::ifstream fragmentIn(fragmentPath);
        std::stringstream fragmentFile;
        fragmentFile << fragmentIn.rdbuf();
        std::string fragmentSource = fragmentFile.str();
        uint32_t fragmentShader = CreateShader(GL_FRAGMENT_SHADER, fragmentSource.c_str());

        m_RendererID = glCreateProgram();
        glAttachShader(m_RendererID, vertexShader);
        glAttachShader(m_RendererID, fragmentShader);
        glLinkProgram(m_RendererID);

        int32_t success = 0;
        glGetProgramiv(m_RendererID, GL_LINK_STATUS, &success);
        if (success == GL_FALSE)
        {
            int32_t maxLength = 0;
            glGetProgramiv(m_RendererID, GL_INFO_LOG_LENGTH, &maxLength);
            char* buffer = new char[maxLength];
            glGetProgramInfoLog(m_RendererID, maxLength, &maxLength, &buffer[0]);
            Log::CoreError("Failed to link shader:\n{0}", buffer);
            delete[] buffer;
        }

        glDetachShader(m_RendererID, vertexShader);
        glDeleteShader(vertexShader);
        glDetachShader(m_RendererID, fragmentShader);
        glDeleteShader(fragmentShader);
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(m_RendererID);
    }

    void OpenGLShader::Bind() const
    {
        glUseProgram(m_RendererID);
    }

    void OpenGLShader::UnBind() const
    {
        glUseProgram(0);
    }

    uint32_t OpenGLShader::CreateShader(uint32_t type, const char* source)
    {
        uint32_t shader = glCreateShader(type);
        glShaderSource(shader, 1, &source, nullptr);
        glCompileShader(shader);

        int32_t success = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (success == GL_FALSE)
        {
            int32_t maxLength = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
            char* buffer = new char[maxLength];
            glGetShaderInfoLog(shader, maxLength, &maxLength, &buffer[0]);
            Log::CoreError("Failed to compile shader:\n{0}", buffer);
            delete[] buffer;
        }

        return shader;
    }

    void OpenGLShader::SetFloatMatrix2x2Array(const std::string& name, const glm::mat2x2* matrix, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix2fv(m_RendererID, location, count, GL_FALSE, glm::value_ptr(*matrix));
    }

    void OpenGLShader::SetFloatMatrix2x2(const std::string& name, const glm::mat2x2& matrix)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix2fv(m_RendererID, location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::SetFloatMatrix2x3Array(const std::string& name, const glm::mat2x3* matrix, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix2x3fv(m_RendererID, location, count, GL_FALSE, glm::value_ptr(*matrix));
    }

    void OpenGLShader::SetFloatMatrix2x3(const std::string& name, const glm::mat2x3& matrix)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix2x3fv(m_RendererID, location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::SetFloatMatrix2x4Array(const std::string& name, const glm::mat2x4* matrix, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix2x4fv(m_RendererID, location, count, GL_FALSE, glm::value_ptr(*matrix));
    }

    void OpenGLShader::SetFloatMatrix2x4(const std::string& name, const glm::mat2x4& matrix)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix2x4fv(m_RendererID, location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::SetFloatMatrix3x2Array(const std::string& name, const glm::mat3x2* matrix, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix3x2fv(m_RendererID, location, count, GL_FALSE, glm::value_ptr(*matrix));
    }

    void OpenGLShader::SetFloatMatrix3x2(const std::string& name, const glm::mat3x2& matrix)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix3x2fv(m_RendererID, location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::SetFloatMatrix3x3Array(const std::string& name, const glm::mat3x3* matrix, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix3fv(m_RendererID, location, count, GL_FALSE, glm::value_ptr(*matrix));
    }

    void OpenGLShader::SetFloatMatrix3x3(const std::string& name, const glm::mat3x3& matrix)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix3fv(m_RendererID, location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::SetFloatMatrix3x4Array(const std::string& name, const glm::mat3x4* matrix, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix3x4fv(m_RendererID, location, count, GL_FALSE, glm::value_ptr(*matrix));
    }

    void OpenGLShader::SetFloatMatrix3x4(const std::string& name, const glm::mat3x4& matrix)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix3x4fv(m_RendererID, location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::SetFloatMatrix4x2Array(const std::string& name, const glm::mat4x2* matrix, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix4x2fv(m_RendererID, location, count, GL_FALSE, glm::value_ptr(*matrix));
    }

    void OpenGLShader::SetFloatMatrix4x2(const std::string& name, const glm::mat4x2& matrix)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix4x2fv(m_RendererID, location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::SetFloatMatrix4x3Array(const std::string& name, const glm::mat4x3* matrix, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix4x3fv(m_RendererID, location, count, GL_FALSE, glm::value_ptr(*matrix));
    }

    void OpenGLShader::SetFloatMatrix4x3(const std::string& name, const glm::mat4x3& matrix)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix4x3fv(m_RendererID, location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::SetFloatMatrix4x4Array(const std::string& name, const glm::mat4x4* matrix, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix4fv(m_RendererID, location, count, GL_FALSE, glm::value_ptr(*matrix));
    }

    void OpenGLShader::SetFloatMatrix4x4(const std::string& name, const glm::mat4x4& matrix)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniformMatrix4fv(m_RendererID, location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::SetIntArray(const std::string& name, const int32_t* values, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform1iv(m_RendererID, location, count, values);
    }

    void OpenGLShader::SetInt(const std::string& name, int32_t value)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform1i(m_RendererID, location, value);
    }

    void OpenGLShader::SetInt2Array(const std::string& name, const glm::ivec2* values, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform2iv(m_RendererID, location, count, glm::value_ptr(*values));
    }

    void OpenGLShader::SetInt2(const std::string& name, const glm::ivec2& value)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform2i(m_RendererID, location, value.x, value.y);
    }

    void OpenGLShader::SetInt3Array(const std::string& name, const glm::ivec3* values, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform3iv(m_RendererID, location, count, glm::value_ptr(*values));
    }

    void OpenGLShader::SetInt3(const std::string& name, const glm::ivec3& value)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform3i(m_RendererID, location, value.x, value.y, value.z);
    }

    void OpenGLShader::SetInt4Array(const std::string& name, const glm::ivec4* values, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform4iv(m_RendererID, location, count, glm::value_ptr(*values));
    }

    void OpenGLShader::SetInt4(const std::string& name, const glm::ivec4& value)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform4i(m_RendererID, location, value.x, value.y, value.z, value.w);
    }

    void OpenGLShader::SetUIntArray(const std::string& name, const uint32_t* values, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform1uiv(m_RendererID, location, count, values);
    }

    void OpenGLShader::SetUInt(const std::string& name, uint32_t value)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform1ui(m_RendererID, location, value);
    }

    void OpenGLShader::SetUInt2Array(const std::string& name, const glm::uvec2* values, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform2uiv(m_RendererID, location, count, glm::value_ptr(*values));
    }

    void OpenGLShader::SetUInt2(const std::string& name, const glm::uvec2& value)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform2ui(m_RendererID, location, value.x, value.y);
    }

    void OpenGLShader::SetUInt3Array(const std::string& name, const glm::uvec3* values, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform3uiv(m_RendererID, location, count, glm::value_ptr(*values));
    }

    void OpenGLShader::SetUInt3(const std::string& name, const glm::uvec3& value)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform3ui(m_RendererID, location, value.x, value.y, value.z);
    }

    void OpenGLShader::SetUInt4Array(const std::string& name, const glm::uvec4* values, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform4uiv(m_RendererID, location, count, glm::value_ptr(*values));
    }

    void OpenGLShader::SetUInt4(const std::string& name, const glm::uvec4& value)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform4ui(m_RendererID, location, value.x, value.y, value.z, value.w);
    }

    void OpenGLShader::SetFloatArray(const std::string& name, const float* values, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform1fv(m_RendererID, location, count, values);
    }

    void OpenGLShader::SetFloat(const std::string& name, float value)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform1f(m_RendererID, location, value);
    }

    void OpenGLShader::SetFloat2Array(const std::string& name, const glm::vec2* values, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform2fv(m_RendererID, location, count, glm::value_ptr(*values));
    }

    void OpenGLShader::SetFloat2(const std::string& name, const glm::vec2& value)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform2f(m_RendererID, location, value.x, value.y);
    }

    void OpenGLShader::SetFloat3Array(const std::string& name, const glm::vec3* values, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform3fv(m_RendererID, location, count, glm::value_ptr(*values));
    }

    void OpenGLShader::SetFloat3(const std::string& name, const glm::vec3& value)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform3f(m_RendererID, location, value.x, value.y, value.z);
    }

    void OpenGLShader::SetFloat4Array(const std::string& name, const glm::vec4* values, uint32_t count)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform4fv(m_RendererID, location, count, glm::value_ptr(*values));
    }

    void OpenGLShader::SetFloat4(const std::string& name, const glm::vec4& value)
    {
        int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
        if (location == -1)
            Log::Error("Attemped to set uniform '{0}' that uniform does not exist!", name);
        else
            glProgramUniform4f(m_RendererID, location, value.x, value.y, value.z, value.w);
    }

}
