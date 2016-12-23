#version 330

in vec4 position;
in vec4 color;

out vec4 fColor;

uniform mat4 ortho;

void main(){

	gl_Position = ortho * position;
	fColor = color;
}