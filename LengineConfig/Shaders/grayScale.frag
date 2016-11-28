#version 330


//in takes in from vertex shader when in fragment shader
in vec4 fragmentColor;	
in vec3 fragmentPosition;
in vec2 fragmentUV;

out vec4 color;


void main(){

  float grayScale = (fragmentColor.r + fragmentColor.g + fragmentColor.b) / 3.0;
	color = vec4(grayScale, grayScale, grayScale, fragmentColor.a);
	

}
