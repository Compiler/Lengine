#version 330

in vec2 position;
in vec4 color;

out vec4 fColor;



void main(){

	gl_Position = vec4(position.x, position.y, 0.0, 1.0);
	fColor = color;
}