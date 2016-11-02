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

	
	//Assigns position
	//gl_Position.xyz = (/*cameraMatrix * */vec4(vertexPosition, 1.0)).xyz;
	gl_Position.xyz = vertexPosition;
	//gl_Position.xy = vec2(1,1);
	
	
	//Says that the coordinates ARE normalized
	gl_Position.w = 1.0;
	
	fragmentPosition = vertexPosition;
	
	//sets it to input then sends it out to fragment shader
	fragmentColor = vertexColor;
	
	fragmentUV = vec2(vertexUV.x, 1 - vertexUV.y);
	
	
}