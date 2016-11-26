#pragma once

#include <iostream>
#include <string>




class Error{
	
public:
	enum ExceptionType{

		INIT,
		NULL_EXC,
		GENERAL

	};
	static void throwException(ExceptionType type, std::string error, bool close){
		std::cout << type << " Exception: "  << error << "\n";
		if(close){
			std::cout << "Forcing exit...\n";

			SDL_Delay(10000);
			exit(-10);
		}
	}

	static void throwAndClose(std::string error) {
		std::cout << error << std::endl;
		std::cout << "Forcing exit...\n";

		SDL_Delay(10000);
		exit(-1);
	}


};