#version 330 core

layout(location = 0) out vec4 o_Color;

uniform vec4 u_Color = vec4(1.0);

in vec3 v_Normal;

void main()
{
	float dirLight = max(dot(normalize(v_Normal), normalize(vec3(0.4, 1.0, 0.6))), 0.0) * 0.7;
	float ambLight = 0.3;
	o_Color = vec4(u_Color.xyz * (dirLight + ambLight), u_Color.w);
}
