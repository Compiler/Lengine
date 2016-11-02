#pragma once


struct Vertex {

	//8 bits
	Position position;
	//16 bits
	Color color;
	//8 bits
	UV uv;
	//8+16+8 = 32 = 2^5  no padding needed

};


struct Position {

	float x, y;

	void set(float newX, float newY) {
		x = newX;
		y = newY;
	}
};


struct UV{

	float u, v;

	void set(float newU, float newV) {
		u = newU;
		v = newV;
	}
};

struct Color {

	float r, g, b, a;

	void set(float red, float green, float blue, float alpha) {
		r = red;
		g = green;
		b = blue;
		a = alpha;
	}
};