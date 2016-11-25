#pragma once
#include <vector>
#include <GL\glew.h>
namespace lml {


	class Matrix {


	public:

		void dot();
		void add();
		void transpose();
		
		
		int getRows();
		int getColumns();

	private:

		std::vector<std::vector<GLfloat>> rows, columns;



	};
}