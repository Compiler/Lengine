#pragma once
#include <SDL\SDL.h>
#include <vector>
#include <iostream>
#include "GameState.h"


class InputListener{
public:
	InputListener();

	const static unsigned int A = 'a';
	const static unsigned int B = 'b';
	const static unsigned int C = 'c';
	const static unsigned int D = 'd';
	const static unsigned int E = 'e';
	const static unsigned int F = 'f';
	const static unsigned int G = 'g';
	const static unsigned int H = 'h';
	const static unsigned int I = 'i';
	const static unsigned int J = 'j';
	const static unsigned int K = 'k';
	const static unsigned int L = 'l';
	const static unsigned int M = 'm';
	const static unsigned int N = 'n';
	const static unsigned int O = 'o';
	const static unsigned int P = 'p';
	const static unsigned int Q = 'q';
	const static unsigned int R = 'r';
	const static unsigned int S = 's';
	const static unsigned int T = 't';
	const static unsigned int U = 'u';
	const static unsigned int V = 'v';
	const static unsigned int W = 'w';
	const static unsigned int X = 'x';
	const static unsigned int Y = 'y';
	const static unsigned int Z = 'z';
	const static unsigned int UP = 'up';
	const static unsigned int DOWN = 'down';
	const static unsigned int LEFT = 'left';
	const static unsigned int RIGHT = 'righ';



	void update(GameState& currentState);

	static bool isKeyDown(unsigned int key);
	static bool isKeyUp(unsigned int key);







	~InputListener();

private:

	std::vector<unsigned int> keys;
	SDL_Event event;
};

