#include "Sprite.h"



Sprite::Sprite(){
}


Sprite::Sprite(GLfloat positionX, GLfloat positionY, GLfloat width, GLfloat height, const char* filePath){
	
	vertex[PositionTuples::BOTTOM_LEFT].setPosition(positionX, positionY);
	vertex[PositionTuples::BOTTOM_LEFT].setNormal(1.0f, 1.0f);

	vertex[PositionTuples::TOP_LEFT].setPosition(positionX, positionY + height);
	vertex[PositionTuples::TOP_LEFT].setNormal(1.0f, 1.0f);

	vertex[PositionTuples::TOP_RIGHT].setPosition(positionX + width, positionY + height);
	vertex[PositionTuples::TOP_RIGHT].setNormal(1.0f, 1.0f);

	vertex[PositionTuples::BOTTOM_RIGHT].setPosition(positionX + width, positionY);
	vertex[PositionTuples::BOTTOM_RIGHT].setNormal(1.0f, 1.0f);
}

void Sprite::init(GLfloat positionX, GLfloat positionY, GLfloat width, GLfloat height, const char* filePath) {

	vertex[PositionTuples::BOTTOM_LEFT].setPosition(positionX, positionY);
	vertex[PositionTuples::BOTTOM_LEFT].setNormal(1.0f, 1.0f);

	vertex[PositionTuples::TOP_LEFT].setPosition(positionX, positionY + height);
	vertex[PositionTuples::TOP_LEFT].setNormal(1.0f, 1.0f);

	vertex[PositionTuples::TOP_RIGHT].setPosition(positionX + width, positionY + height);
	vertex[PositionTuples::TOP_RIGHT].setNormal(1.0f, 1.0f);

	vertex[PositionTuples::BOTTOM_RIGHT].setPosition(positionX + width, positionY);
	vertex[PositionTuples::BOTTOM_RIGHT].setNormal(1.0f, 1.0f);

}



void Sprite::render(){


}


Sprite::~Sprite(){
}
