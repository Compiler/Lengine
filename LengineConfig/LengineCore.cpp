#include "LengineCore.h"
#include "ScreenHelper.h"


LengineCore::LengineCore(){

	ScreenHelper::GetDesktopResolution(width, height);
	std::cout << "Width: " << width << ", Height: " << height << std::endl;
}



void LengineCore::run(){




}


void LengineCore::initSubSystems(){
	



}


void LengineCore::render(){




}

void LengineCore::update(){




}



LengineCore::~LengineCore(){
}
