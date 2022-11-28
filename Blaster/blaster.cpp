#include "blaster.h"

//double xPos = 0, yPos = 0;
//const int width = 728, height = 728;
//
//void cursor_position_callback(GLFWwindow* window, float ypos)
//{
//	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
//	{
//		yPos = ypos;
//	}
//}


Blaster::Blaster(glm::vec3 blasterPosition, float blasterSpeed, int damage)
{
	this->blasterPosition = blasterPosition;
	this->blasterSpeed = blasterSpeed;
	this->damage = damage;
}

Blaster::Blaster()
{
}

Blaster::~Blaster()
{
}

void Blaster::applyTrans(glm::mat4 trans, GLuint programID)
{
	//trans = glm::translate(trans, glm::vec3(this->blasterPosition.x, this->blasterPosition.y, 0.0));
	unsigned int transformLoc = glGetUniformLocation(programID, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

	glDrawElements(GL_TRIANGLE_FAN, 16, GL_UNSIGNED_INT, 0);
}

void Blaster::shootUp(GLFWwindow* window, GLuint programID, float startingPointX, float startingPointY)
{
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS ||
		glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		glm::mat4 trans(1.0f);

		this->setBlasterPositionX(startingPointX);
		this->setBlasterPositionY(startingPointY);

		//glm::vec3 vec = glm::vec3(float((-width / 2 + xPos) / (width / 2)), float((height / 2 - yPos) / (height / 2)), 0);

		float pos = this->getBlasterPositionY() + 1;
		//float pos = yPos;
		//cursor_position_callback(window, vec.y);

		/*while(this->getBlasterPositionY() < pos) {*/

			//glm::mat4 trans(1.0f);
			/*this->setBlasterPositionY(this->getBlasterPositionY() + 0.08f);
			trans = glm::translate(trans, glm::vec3(this->blasterPosition.x, this->blasterPosition.y, 0.0));
			this->applyTrans(trans, programID);*/
		/*}*/
	}

	glm::mat4 trans(1.0f);
	this->setBlasterPositionY(this->getBlasterPositionY() + 0.01f);
	trans = glm::translate(trans, glm::vec3(this->blasterPosition.x, this->blasterPosition.y, 0.0));
	this->applyTrans(trans, programID);
	
}

glm::vec3 Blaster::getBlasterPosition()
{
	return this->blasterPosition;
}

float Blaster::getBlasterPositionX()
{
	return this->getBlasterPosition().x;
}

float Blaster::getBlasterPositionY()
{
	return this->getBlasterPosition().y;
}

float Blaster::getBlasterSpeed()
{
	return this->blasterSpeed;
}

int Blaster::getBlasterDamage()
{
	return this->damage;
}

void Blaster::setBlasterPosition(glm::vec3 blasterPosition)
{
	this->blasterPosition = blasterPosition;
}

void Blaster::setBlasterPositionX(float x)
{
	this->blasterPosition.x = x;
}

void Blaster::setBlasterPositionY(float y)
{
	this->blasterPosition.y = y;
}

void Blaster::setBlasterSpeed(float blasterSpeed)
{
	this->blasterSpeed = blasterSpeed;
}

void Blaster::setBlasterDamage(int damage)
{
	this->damage = damage;
}