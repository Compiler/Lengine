#version 330


in vec2 vertexPosition;
in vec4 vertexColor;
in vec2 vertexUV;

//out sends to frag when named the same and in vertex shader
out vec4 fragmentColor;
out vec2 fragmentPosition;
out vec2 fragmentUV;
out mat4 myMat;

uniform mat4 cameraMatrix;
//uniform mat2 transform;

mat4 getMat(){
	
	return mat4(
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0
	);
	
}

void main(){
	myMat = cameraMatrix;
	vec2 orig = (getMat() * vec4(vertexPosition, 0.0, 1.0)).xy;
	
	gl_Position = (cameraMatrix * vec4(vertexPosition.x, -vertexPosition.y, 0.0, 1.0));

	gl_Position.z = 0.0;
	
	
	gl_Position.w = 1.0;
	
	fragmentPosition = vertexPosition;
	
	
	fragmentColor = vertexColor;
	
	fragmentUV = vec2(vertexUV.x, 1.0 - vertexUV.y);
	
	
}