#include "InputListener.h"



InputListener::InputListener(){
}




void InputListener::update(GameState& currentState){
	
	SDL_Event event;
	while(SDL_PollEvent(&event)){

		switch(event.type){
		
			case SDL_QUIT: {
				currentState = GameState::EXIT;
				break;
			}

		}
		
	}

}

bool InputListener::isKeyDown(unsigned int key){
	

	return false;
}


bool InputListener::isKeyUp(unsigned int key){



	return false;
}



InputListener::~InputListener(){
}
