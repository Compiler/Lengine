#version 430 core

out vec4 color;


uniform UniformBlock{
	vec4 location;
	float radius;
	bool enabled;
};



in vec4 fColor;
in vec2 fTexCoord;


uniform sampler2D texture1;

void main()
{
    color = texture(texture1, fTexCoord);
	color *= fColor;
}