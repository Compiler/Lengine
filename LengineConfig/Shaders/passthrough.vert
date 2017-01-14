#version 430 core

layout(location = 0) in vec4 vPosition;
layout(location = 1) in vec4 vColor;
layout(location = 2) in vec2 vTexCoord;

out vec4 fColor;
out vec2 fTexCoord;

uniform mat4 transform;

void main(){
	
	gl_Position = transform * vPosition;
	
	fTexCoord = vTexCoord;
	
	fColor = vColor;
}