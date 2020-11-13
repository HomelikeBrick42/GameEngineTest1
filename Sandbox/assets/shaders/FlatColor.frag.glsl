#version 330 core

layout(location = 0) out vec4 o_Color;

uniform vec4 u_Color = vec4(1.0);

void main()
{
	o_Color = u_Color;
}
