#version 430 core

out vec4 color;


uniform UniformBlock{
	vec4 location;
	float radius;
	bool enabled;
};


in vec4 fColor;

void main(){
	//vec3 mine = col.xyz;
	//vec2 p = gl_FragCoord.xy / vec2(640, 480);
	//vec2 q = p - vec2(0.5, 0.5);
//	float r = 0.15 + 0.1 * cos(atan(q.x, q.y) * 10.0);
	//mine *= smoothstep(r, r+ 0.01, length(q));
	color = fColor;
}