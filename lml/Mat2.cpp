#include "Mat2.h"

#define NO -7071

Mat2::Mat2(float topLeft, float topRight, float bottomLeft, float bottomRight){

	mat[0][0] = topLeft;
	mat[0][1] = bottomLeft;
	mat[1][0] = topRight;
	mat[1][1] = bottomRight;

}

void Mat2::dot(Mat2 matrix){

	/*
		
		A0,0	A1,0		B0,0	B1,0               

		A0,1	A1,1		B0,1	B1,1

	*/


	// A0,0 * B0,0 + A1,0 * B0,1
	float topLeft = mat[0][0] * matrix.mat[0][0] + mat[1][0] * matrix.mat[0][1];

	// A0,0 * B1,0 + A1,0 * B1,1
	float topRight = mat[0][0] * matrix.mat[1][0] + mat[1][0] * matrix.mat[1][1];

	// A0,1 * B0,0 + A1,1 * B0,1
	float bottomLeft = mat[0][1] * matrix.mat[0][0] + mat[1][1] * matrix.mat[0][1];

	// A0,1 * B1,0 + A1,1 * B1,1
	float bottomRight = mat[0][1] * matrix.mat[1][0] + mat[1][1] * matrix.mat[1][1];


	mat[0][0] = topLeft;
	mat[0][1] = bottomLeft;
	mat[1][0] = topRight;
	mat[1][1] = bottomRight;
	

}
/*
	Returns the element in the matrix at the given position
*/
float Mat2::elementAt(int x, int y) {
	//return mat[x < 2 ? x >= 0 ? x : 0 : break][y < 2 ? y >= 0 ? y : 0 : NO];
	return mat[x][y];
}

Mat2 Mat2::getDot(Mat2 matrix){

	/*

	A0,0	A1,0		B0,0	B1,0

	A0,1	A1,1		B0,1	B1,1

	*/


	// A0,0 * B0,0 + A1,0 * B0,1
	float topLeft = mat[0][0] * matrix.mat[0][0] + mat[1][0] * matrix.mat[0][1];

	// A0,0 * B1,0 + A1,0 * B1,1
	float topRight = mat[0][0] * matrix.mat[1][0] + mat[1][0] * matrix.mat[1][1];

	// A0,1 * B0,0 + A1,1 * B0,1
	float bottomLeft = mat[0][1] * matrix.mat[0][0] + mat[1][1] * matrix.mat[0][1];

	// A0,1 * B1,0 + A1,1 * B1,1
	float bottomRight = mat[0][1] * matrix.mat[1][0] + mat[1][1] * matrix.mat[1][1];


	//returns the new matrix from the dot product
	return Mat2(topLeft, topRight, bottomLeft, bottomRight);

}



Mat2::~Mat2(){
}
