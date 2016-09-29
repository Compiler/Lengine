#pragma once

#include <iostream>
#include <string>


enum ExceptionType{
	
	INIT,
	NULL_EXC,
	GENERAL

};

class Error{

public:

	static void toss(ExceptionType type, std::string error, bool close){
		std::cout << type << " Exception: "  << error << "\n";
		if(close){
			std::cout << "Forcing exit...\n";
			exit(-10);
		}
	}


};