
#include <iostream>
#include <SDL\SDL.h>
#include "LengineCore.h"

int main(int argc, char** argv){

	LengineCore core;
	core.run();

	//studder for build errors
	char studder;
	std::cin >> studder;
	return 0;
}