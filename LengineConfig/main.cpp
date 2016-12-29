
#include <iostream>

#include "Core.h"
#include <lml\Mat4x4.h>


//start of app
int main(int argc, char** argv){
	float **or = new float*[4];
	for (int i = 0; i < 4; i++)
		or [i] = new float[4];
	for (int i = 0; i < 4; i++)
		for (int k = 0; k < 4; k++)
			or [i][k] = i + k;


	or [2][0] = { 44 };

	float ** orr = new float*[4];
	for (int i = 0; i < 4; i++)
		orr [i] = new float[4];
	for (int i = 0; i < 4; i++)
		for (int k = 0; k < 4; k++)
			orr [i][k] = i - k * 6;


	orr [2][0] = { 44 };

	lml::Mat4x4 first(or);
	first.print();

	lml::Mat4x4 firsttt(orr );
	firsttt.print();


	lml::Mat4x4 me = (first * firsttt);
	me.print();
	Core game;
	game.run();

	return 0;
}
