#version 430 core

out vec4 color;


in vec4 fColor;
in vec2 fTexCoord;
in vec2 fNormal;

uniform sampler2D texture1;

void main()
{
    color = texture(texture1, fTexCoord);
	color *= fColor;
}