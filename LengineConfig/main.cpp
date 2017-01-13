
#include <iostream>
#include "LengineCore.h"
#include "ImageLoader.h"

//start of app
int main(int argc, char** argv){
	


	char* pixBuf;
	LoadBMP("Textures/wood.bmp", pixBuf);
	delete [] pixBuf;

	LengineCore core;
	core.run();
	
	return 0;
}
