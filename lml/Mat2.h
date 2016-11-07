#pragma once
class Mat2{
public:
	Mat2(float topLeft, float topRight, float bottomLeft, float bottomRight);

	float mat[2][2];

	void dot(Mat2 matrix);
	Mat2 getDot(Mat2 matrix);
	float elementAt(int x, int y);


	~Mat2();


private:

	

};

