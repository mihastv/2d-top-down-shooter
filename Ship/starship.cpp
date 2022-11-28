#include "starship.h"

int MAX_HP = 10;

Starship::Starship(glm::vec3 starshipPosition, int HP, float speed, Blaster blaster)
{
	this->starshipPosition = starshipPosition;
	this->HP = HP;
	this->speed = speed;
	this->blaster = blaster;
}

Starship::Starship()
{
	this->starshipPosition = glm::vec3(0.0f, -0.5f, 0.0f);
}

Starship::~Starship()
{
}

void Starship::applyTrans(glm::mat4 trans, GLuint programID)
{
	trans = glm::translate(trans, glm::vec3(this->starshipPosition.x, this->starshipPosition.y, 0.0));
	unsigned int transformLoc = glGetUniformLocation(programID, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}

void Starship::moveUp(GLFWwindow* window, GLuint programID)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && this->getStarshipPositionY() < 1) {

		glm::mat4 trans(1.0f);
		this->setStarshipPositionY(this->getStarshipPositionY() + this->getStarshipSpeed());
		this->applyTrans(trans, programID);

	}
}

void Starship::moveDown(GLFWwindow* window, GLuint programID)
{
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS && this->getStarshipPositionY() > -1) {

		glm::mat4 trans(1.0f);
		this->setStarshipPositionY(this->getStarshipPositionY() - this->getStarshipSpeed());
		this->applyTrans(trans, programID);

	}
}

void Starship::moveLeft(GLFWwindow* window, GLuint programID)
{
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && this->getStarshipPositionX() > -1) {

		glm::mat4 trans(1.0f);
		this->setStarshipPositionX(this->getStarshipPositionX() - this->getStarshipSpeed());
		this->applyTrans(trans, programID);

	}
}

void Starship::moveRight(GLFWwindow* window, GLuint programID)
{
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && this->getStarshipPositionX() < 1) {

		glm::mat4 trans(1.0f);
		this->setStarshipPositionX(this->getStarshipPositionX() + this->getStarshipSpeed());
		this->applyTrans(trans, programID);

	}
}

void Starship::checkMotion(GLFWwindow* window, GLuint programID)
{
	this->moveUp(window, programID);
	this->moveDown(window, programID);
	this->moveLeft(window, programID);
	this->moveRight(window, programID);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}

void Starship::blasterShootUp(GLFWwindow* window, GLuint programID)
{
	this->blaster.shootUp(window, programID, this->starshipPosition.x, this->starshipPosition.y + 0.1f);
}

void Starship::starshipLevelUp()
{
	this->setStarshipHP(MAX_HP);
}

glm::vec3 Starship::getStarshipPosition()
{
	return this->starshipPosition;
}

float Starship::getStarshipPositionX()
{
	return this->starshipPosition.x;
}

float Starship::getStarshipPositionY()
{
	return this->starshipPosition.y;
}

int Starship::getStarshipHP()
{
	return this->HP;
}

float Starship::getStarshipSpeed()
{
	return this->speed;
}

Blaster Starship::getStarshipBlaster()
{
	return this->blaster;
}

void Starship::setStarshipPosition(glm::vec3 starshipPosition)
{
	this->starshipPosition = starshipPosition;
}

void Starship::setStarshipPositionX(float x)
{
	this->starshipPosition.x = x;
}

void Starship::setStarshipPositionY(float y)
{
	this->starshipPosition.y = y;
}

void Starship::setStarshipHP(int HP)
{
	this->HP = HP;
}
void Starship::setStarshipSpeed(float speed)
{
	this->speed = speed;
}

void Starship::setStarshipBlaster(Blaster blaster)
{
	this->blaster = blaster;
}