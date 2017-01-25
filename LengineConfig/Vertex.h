#pragma once
#include <GL\glew.h>
#include <lml\Vector3.h>

struct Color{

	GLubyte red;
	GLubyte green;
	GLubyte blue;
	GLubyte alpha;

};



struct Position{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

struct Normal{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

struct UV{
	GLfloat u;
	GLfloat v;

};


struct Vertex{

	Vertex(){}
	//Vector3 position;
	Color color;
	Position pos;

	void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a){
		color.red = r;
		color.green = g;
		color.blue = b;
		color.alpha = a;
	}

	void setPosition(GLfloat positionX, GLfloat positionY){
		pos.x = positionX;
		pos.y = positionY;
		pos.z = 1.0f;
	}


};

struct VertexNorm{

	VertexNorm(){}
	Normal normal;
	Color color;
	Position pos;
	UV uv;

	void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a){
		color.red = r;
		color.green = g;
		color.blue = b;
		color.alpha = a;
	}

	void setPosition(GLfloat positionX, GLfloat positionY){
		pos.x = positionX;
		pos.y = positionY;
		pos.z = 1.0f;
	}

	void setNormal(GLfloat normalX, GLfloat normalY){
		normal.x = normalX;
		normal.y = normalY;
		normal.z = 1.0f;
	}

	void setUV(GLfloat newU, GLfloat newV){
		uv.u = newU;
		uv.v = newV;
	}


};