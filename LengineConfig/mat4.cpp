#include "mat4.h"
#include <iostream>


mat4::mat4(){


}

mat4::mat4(GLfloat row1[4], GLfloat row2[4], GLfloat row3[4], GLfloat row4[4]){

	std::memcpy(row1, matrix[0], sizeof(row1));
	std::memcpy(row2, matrix[1], sizeof(row2));
	std::memcpy(row3, matrix[2], sizeof(row3));
	std::memcpy(row4, matrix[3], sizeof(row4));

}

mat4::mat4(GLfloat mat[4][4]){

	std::memcpy(mat, matrix, sizeof(matrix));

}



mat4::mat4(GLfloat linear[16]){
	int count = -1;
	for (int i = 0; i < 16; i++) {
		if (i % 4 == 0) {
			std::cout << i % 4 << " to " << i << "\n";
			count++;
		}
		
		matrix[i][count] = linear[i];
		std::cout << i << ", " << count << " = " << linear[i] << "\n";
	}

	std::cout << "\n\n\n\n";

	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			std::cout << matrix[k][i] << "  ";
		}
		std::cout << "\n";
	}

}


GLfloat mat4::getElement(GLint x, GLint y){


	return matrix[x][y];
}



mat4::~mat4()
{
}
