#pragma once
#include <SDL\SDL.h>
#include <vector>

class InputListener{
public:
	InputListener();

	const static unsigned char A = 'a';
	const static unsigned char B = 'b';
	const static unsigned char C = 'c';
	const static unsigned char D = 'd';
	const static unsigned char E = 'e';
	const static unsigned char F = 'f';
	const static unsigned char G = 'g';
	const static unsigned char H = 'h';
	const static unsigned char I = 'i';
	const static unsigned char J = 'j';
	const static unsigned char K = 'k';
	const static unsigned char L = 'l';
	const static unsigned char M = 'm';
	const static unsigned char N = 'n';
	const static unsigned char O = 'o';
	const static unsigned char P = 'p';
	const static unsigned char Q = 'q';
	const static unsigned char R = 'r';
	const static unsigned char S = 's';
	const static unsigned char T = 't';
	const static unsigned char U = 'u';
	const static unsigned char V = 'v';
	const static unsigned char W = 'w';
	const static unsigned char X = 'x';
	const static unsigned char Y = 'y';
	const static unsigned char Z = 'z';
	const static unsigned char UP = 'up';
	const static unsigned char DOWN = 'down';
	const static unsigned char LEFT = 'left';
	const static unsigned char RIGHT = 'righ';



	void update();

	static bool isKeyDown(unsigned char key);
	static bool isKeyUp(unsigned char key);







	~InputListener();

private:

	std::vector<unsigned char> keys;

};

