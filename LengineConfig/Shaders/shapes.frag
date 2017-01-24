#version 430 core

out vec4 color;


in vec4 fColor;
//in vec2 fNormal;

void main()
{
	color = fColor;
	//color += vec4(1.0);
}