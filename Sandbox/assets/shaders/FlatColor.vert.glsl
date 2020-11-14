#version 330 core

layout(location = 0) in vec4 a_Position;
layout(location = 1) in vec3 a_Normal;

uniform mat4 u_Model = mat4(1.0);
uniform mat4 u_ViewProjection = mat4(1.0);

layout(location = 0) out vec3 v_Normal;

void main()
{
	gl_Position = u_ViewProjection * u_Model * a_Position;
	v_Normal = normalize((transpose(inverse(mat3(u_Model))) * a_Normal).xyz);
}
