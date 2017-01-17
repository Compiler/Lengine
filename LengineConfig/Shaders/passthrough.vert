#version 430 core

layout(location = 0) in vec4 vPosition;
layout(location = 1) in vec4 vColor;
layout(location = 2) in vec2 vTexCoord;
layout(location = 3) in vec2 vNormal;

out vec4 fColor;
out vec2 fTexCoord;
out vec2 fNormal;


void main(){
	
	gl_Position = vec4(vPosition.xyz, 1.0);
	
	fTexCoord = vTexCoord;
	
	fColor = vColor;
	
	fNormal = vNormal;
}