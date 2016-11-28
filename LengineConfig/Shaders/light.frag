#version 330


//in takes in from vertex shader when in fragment shader
in vec4 fragmentColor;	
in vec3 fragmentPosition;
in vec2 fragmentUV;

out vec4 color;

uniform sampler2D samp;
uniform vec3 light0;
uniform vec2 uResolution;

void main(){

	
	vec4 texCol = texture(samp, fragmentUV);
	color = texCol * fragmentColor;
	color.r += light0.z;
	

}