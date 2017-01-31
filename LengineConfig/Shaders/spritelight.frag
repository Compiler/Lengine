#version 430 core

out vec4 color;


in vec4 fColor;
in vec2 fTexCoord;
in vec2 fNormal;

uniform sampler2D texture1;
uniform vec3 lightColor;
uniform vec3 lightPosition;
void main()
{

	vec3 N = vec3(fNormal, 1.0);
	float cosTheta = clamp(dot(N, (lightPosition - N)
	/ length(lightPosition - N)), 0.0, 1.0);
	
    color = texture(texture1, fTexCoord);
	color *= fColor * vec4(lightColor * cosTheta, 1.0);
}