
#include <iostream>
#include "LengineCore.h"
#include "ImageLoader.h"

//start of app
int main(int argc, char** argv){
	
	LoadBMP("Textures/wood.bmp");

	LengineCore core;
	core.run();
	
	return 0;
}
