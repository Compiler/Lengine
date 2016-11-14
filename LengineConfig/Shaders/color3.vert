#version 330


in vec3 vertexPosition;
in vec4 vertexColor;
in vec2 vertexUV;

//out sends to frag when named the same and in vertex shader
out vec4 fragmentColor;
out vec3 fragmentPosition;
out vec2 fragmentUV;

/*uniform mat4 cameraMatrix;*/


void main(){

	

	float rad = 45.0;
	gl_Position = vec4(vertexPosition,1.0) * mat4(
	1.0, 0.0, 	   0.0,	    0.0,
	0.0, cos(rad), -sin(rad), 0.0,
	0.0, sin(rad), cos(rad),  0.0,
	0.0, 0.0, 	  0.0,   	1.0
	);

	
	fragmentPosition = vertexPosition;
	
	fragmentColor = vertexColor;
	
	fragmentUV = vec2(vertexUV.x, 1 - vertexUV.y);
	
	
}