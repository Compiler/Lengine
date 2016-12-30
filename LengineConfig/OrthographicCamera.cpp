#include "OrthographicCamera.h"
#include <iostream>


//sets default value
OrthographicCamera::OrthographicCamera() : position(0.0f, 0.0f), camMatrix(1.0f), camScale(1), updateCam(true), viewport(640, 480)
{


}
//initializes viewport and matrix
void OrthographicCamera::init(float width, float height) {

	viewport.x = width;
	viewport.y = height;

	orthoMatrix = glm::ortho(0.0f, viewport.x, 0.0f, viewport.y);

	std::cout << viewport.x << ", " << viewport.y << std::endl;

}


//updates the cameras scale and view
void OrthographicCamera::update() {
	if (updateCam) {
		glm::vec3 translate(-position.x, -position.y, 0.0f);
		camMatrix = glm::translate(orthoMatrix, translate);
		glm::vec3 scale(camScale, camScale, 0.0f);
		camMatrix = glm::scale(camMatrix, scale);


		updateCam = false;
	}


}
void OrthographicCamera::translate(GLfloat xAmount, GLfloat yAmount, GLfloat zAmount) {
	
	
	//orthographicMatrix.print();
}

//void OrthographicCamera::scale(GLfloat amount) {}
//void OrthographicCamera::scale(GLfloat xAmount, GLfloat yAmount) {}
void OrthographicCamera::scaleX(GLfloat amount) {}
void OrthographicCamera::scaleY(GLfloat amount) {}


OrthographicCamera::~OrthographicCamera()
{
}
