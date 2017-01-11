#version 430 core

out vec4 color;


uniform UniformBlock{
	vec4 col;
	vec4 location;
	float radius;
	bool enabled;
};

void main(){

	color = vec4(0.0, 1.0, 0.0, 1.0);
}