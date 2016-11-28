#version 330


//in takes in from vertex shader when in fragment shader
in vec4 fragmentColor;	
in vec2 fragmentPosition;
in vec2 fragmentUV;

out vec4 color;

uniform sampler2D samp;
uniform vec3 light0;
uniform vec2 uResolution;

void main(){

	vec2 position = fragmentPosition.xy / uResolution.xy;
	float dist = distance(position.xy, light0.xy);
	
	
	
	vec4 texCol = texture(samp, fragmentUV);
	color = texCol * fragmentColor;
	
	if(dist > light0.z / uResolution.x)
		color = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	
		
	
	

}