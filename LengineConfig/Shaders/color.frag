#version 330


//in takes in from vertex shader when in fragment shader
in vec4 fragmentColor;	
in vec2 fragmentPosition;
in vec2 fragmentUV;

out vec4 color;


void main(){


	color = vec4(0.0, 1.0, 0.0, 1.0);
	

}