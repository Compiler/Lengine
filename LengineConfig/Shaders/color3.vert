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
	gl_Position.w = 1.0;
	gl_Position = vec4(vertexPosition, 1.0) * mat4(
	cos(45), sin(45), 0.0, 0.0, 
	-sin(45), cos(45),0.0, 0.0, 
	0.0,   	0.0, 	1.0, 	0.0, 
	0.0, 	0.0, 	0.0, 	1.0
	);
	//gl_Position.xy = vec2(1,1);
	
	
	//Says that the coordinates ARE normalized
	
	
	fragmentPosition = vertexPosition;
	
	//sets it to input then sends it out to fragment shader
	fragmentColor = vertexColor;
	
	fragmentUV = vec2(vertexUV.x, 1 - vertexUV.y);
	
	
}