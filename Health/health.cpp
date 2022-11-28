#include "health.h"
#include <iostream>

float randomFloatHealth(float a, float b) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

Health::Health(glm::vec3 healthPosition, int HP, float fallSpeed)
{
	this->healthPosition = healthPosition;
	this->HP = HP;
	this->fallSpeed = fallSpeed;
}

Health::Health()
{
	this->healthPosition = glm::vec3(0.0f, -0.5f, 0.0f);
}

Health::~Health()
{
}

void Health::applyTrans(glm::mat4 trans, GLuint programID)
{
	//trans = glm::translate(trans, glm::vec3(this->asteroidPosition.x, this->asteroidPosition.y, 0.0));
	unsigned int transformLoc = glGetUniformLocation(programID, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}

void Health::moveDown(GLuint programID)
{
	if (this->getHealthPositionY() > -1.6) {

		glm::mat4 trans(1.0f);
		this->setHealthPositionY(this->getHealthPositionY() - this->getFallSpeed());
		trans = glm::translate(trans, glm::vec3(this->healthPosition.x, this->healthPosition.y, 0.0));
		this->applyTrans(trans, programID);
	}

}

void Health::checkMotion(GLuint programID, GLuint VAO)
{
	this->moveDown(programID);

	glEnableVertexAttribArray(0);

	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLE_FAN, 12, GL_UNSIGNED_INT, 0);
}

void Health::spawnHealth(glm::mat4 trans, GLuint programID)
{
	this->setHealthPositionX(randomFloatHealth(-0.8, 0.8));
	this->setHealthPositionY(2.0f);
	trans = glm::translate(trans, glm::vec3(this->healthPosition.x, this->healthPosition.y, 0.0));
	this->applyTrans(trans, programID);
	this->setHealthHP(1);
}

void Health::despawnHealth(glm::mat4 trans, GLuint programID)
{
	if (this->getHealthPositionY() <= -1.6)
		this->spawnHealth(trans, programID);
}

glm::vec3 Health::getHealthPosition()
{
	return this->healthPosition;
}

float Health::getHealthPositionX()
{
	return this->healthPosition.x;
}

float Health::getHealthPositionY()
{
	return this->healthPosition.y;
}

int Health::getHealthHP()
{
	return this->HP;
}

float Health::getFallSpeed()
{
	return this->fallSpeed;
}


void Health::setHealthPosition(glm::vec3 healthPosition)
{
	this->healthPosition = healthPosition;
}

void Health::setHealthPositionX(float x)
{
	this->healthPosition.x = x;
}

void Health::setHealthPositionY(float y)
{
	this->healthPosition.y = y;
}

void Health::setHealthHP(int HP)
{
	this->HP = HP;
}
void Health::setFallSpeed(float fallSpeed)
{
	this->fallSpeed = fallSpeed;
}
