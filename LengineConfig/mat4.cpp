#include "mat4.h"
#include <iostream>


mat4::mat4(){


}
/*
	Creates a matrix 4x4 by giving 4 rows of information
*/
mat4::mat4(GLfloat row1[4], GLfloat row2[4], GLfloat row3[4], GLfloat row4[4]){

	std::memcpy(row1, matrix[0], sizeof(row1));
	std::memcpy(row2, matrix[1], sizeof(row2));
	std::memcpy(row3, matrix[2], sizeof(row3));
	std::memcpy(row4, matrix[3], sizeof(row4));

}

/*
	Creates a matrix 4x4 by giving 4 rows of information
*/
void mat4::initByRow(GLfloat row1[4], GLfloat row2[4], GLfloat row3[4], GLfloat row4[4]) {

	std::memcpy(row1, matrix[0], sizeof(row1));
	std::memcpy(row2, matrix[1], sizeof(row2));
	std::memcpy(row3, matrix[2], sizeof(row3));
	std::memcpy(row4, matrix[3], sizeof(row4));

}


/*
	Creates a 4x4 matrix simply by giving a 4x4 float array
*/
mat4::mat4(GLfloat mat[4][4]){

	std::memcpy(mat, matrix, sizeof(matrix));

}

/*
	Creates a 4x4 matrix simply by giving a 4x4 float array
*/
void mat4::initByMat(GLfloat mat[4][4]) {

	std::memcpy(mat, matrix, sizeof(matrix));

}

/*
	Creates a 4x4 matrix by giving a one dimensional array given like so:

	0, 1, 2, 3,
	4, 5, 6, 7,
	8, 9, 10, 11,
	12, 13, 14, 15

	by index

*/
mat4::mat4(GLfloat linear[16]){
	std::memcpy(linear, linMat, sizeof(linMat));
	int count = -1;
	for (int i = 0; i < 16; i++) {
		matrix[i % 4][i % 4 == 0 ? ++count : count] = linear[i];
	}
}

/*
	Creates a 4x4 matrix by giving a one dimensional array given like so:

	0, 1, 2, 3,
	4, 5, 6, 7,
	8, 9, 10, 11,
	12, 13, 14, 15

	by index

*/
void mat4::initByArray(GLfloat linear[16]) {
	int count = -1;
	for (int i = 0; i < 16; i++) {
		matrix[i % 4][i % 4 == 0 ? ++count : count] = linear[i];
	}
}



/*
	Returns the element in the array by the given index for x and y
*/
GLfloat mat4::getElement(GLint x, GLint y){
	return matrix[x][y];
}

GLfloat* mat4::getLinear() {
	
	return linMat;

}



mat4::~mat4()
{
}
