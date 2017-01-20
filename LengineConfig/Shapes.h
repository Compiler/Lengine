#pragma once


struct Shape{

	virtual void draw() = 0;
};

struct Triangle: public Shape{

	virtual void draw(){

	}

};

struct Square: public Shape{

	virtual void draw(){

	}

};