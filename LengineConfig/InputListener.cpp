#include "InputListener.h"



InputListener::InputListener(){
}




void InputListener::update(){
	
	SDL_Event* event;

	SDL_PollEvent(event);

	switch(event->key.keysym.sym){
		
		case SDLK_w: keys[];

	}

}

bool InputListener::isKeyDown(unsigned char key){
	


}


bool InputListener::isKeyUp(unsigned char key){

}



InputListener::~InputListener(){
}
