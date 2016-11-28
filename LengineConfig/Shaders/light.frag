#version 330


//in takes in from vertex shader when in fragment shader
in vec4 fragmentColor;	
in vec2 fragmentPosition;
in vec2 fragmentUV;
in mat4 myMat;

out vec4 color;

uniform sampler2D samp;
uniform vec3 light0;
uniform vec2 uResolution;


void main(){

	vec2 position = vec2(fragmentPosition.x / uResolution.x, fragmentPosition.y / uResolution.y);
	
	float dist = distance(position.xy, light0.xy);
	
	
	float radius = (light0.z / uResolution.x);
	
	vec4 texCol = texture(samp, fragmentUV);
	vec4 col = texCol * fragmentColor;
	
	if(dist < radius)
		col = col * (1.0-(dist / radius));
	else
		col = vec4(0.0);
		
		
	color = col;

}