
#include <iostream>

#include "Core.h"
#include <lml\Mat4x4.h>




//start of app
int main(int argc, char** argv){
	
	float first[4][4] = { { 0, 1, 2, 3 },{ 1,2,3,4 },{ 2,3,4,5 },{ 3,4,5,6 } };
	float second[4][4] = { { 0, -6, -12, -18 },{ 1,-5,-11, -17},{ 2,3,4,5 },{ 3,4,5,6 } };
	lml::Mat4x4 firstMatrix(first);
	lml::Mat4x4 secondMatrix(second);

	firstMatrix.print();
	secondMatrix.print();

	(firstMatrix * secondMatrix).print();

	Core game;
	game.run();

	return 0;
}
