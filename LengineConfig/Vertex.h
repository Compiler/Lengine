#pragma once


struct Vertex {

	//8 bits
	float x, y;
	//16 bits
	float r, g, b, a;
	//8 bits
	float u, v;

	//8+16+8 = 32 = 2^5  no padding needed

};
