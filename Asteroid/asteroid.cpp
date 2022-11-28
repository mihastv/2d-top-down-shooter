#include "asteroid.h"
#include <iostream>

static int HPArray[] = { 1, 200, 400, 600, 800, 1000 };

float randomFloat(float a, float b) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

Asteroid::Asteroid(glm::vec3 asteroidPosition, int HP, float fallSpeed)
{
	this->asteroidPosition = asteroidPosition;
	this->HP = HP;
	this->fallSpeed = fallSpeed;
}

Asteroid::Asteroid()
{
	this->asteroidPosition = glm::vec3(0.0f, -0.5f, 0.0f);
}

Asteroid::~Asteroid()
{
}

void applyColor(glm::vec4 color, GLuint programID)
{
	unsigned int transformLoc2 = glGetUniformLocation(programID, "color");
	glUniform4fv(transformLoc2, 1, glm::value_ptr(color));
}

void Asteroid::applyTrans(glm::mat4 trans, GLuint programID)
{
	//trans = glm::translate(trans, glm::vec3(this->asteroidPosition.x, this->asteroidPosition.y, 0.0));
	unsigned int transformLoc = glGetUniformLocation(programID, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}

void Asteroid::applyRotation(glm::mat4 trans, GLuint programID)
{
	trans = glm::rotate(trans, 10.0f, glm::vec3(this->getAsteroidPositionX(),
		this->getAsteroidPositionY(), 0.0));
	unsigned int transformLoc = glGetUniformLocation(programID, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}

void Asteroid::moveDown(GLuint programID)
{
	if (this->getAsteroidPositionY() > -1.6) {

		glm::mat4 trans(1.0f);
		this->setAsteroidPositionY(this->getAsteroidPositionY() - this->getFallSpeed());
		trans = glm::translate(trans, glm::vec3(this->asteroidPosition.x, this->asteroidPosition.y, 0.0));
		this->applyTrans(trans, programID);
		this->applyRotation(trans, programID);
	}

}

void Asteroid::checkMotion(GLuint programID,GLuint VAO)
{
	this->moveDown(programID);

	glEnableVertexAttribArray(0);

	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLE_FAN, 8, GL_UNSIGNED_INT, 0);
}

void Asteroid::spawnAsteroid(glm::mat4 trans,GLuint programID, float left, float right, int level)
{
	this->setAsteroidPositionX(randomFloat(left,right));
	this->setAsteroidHP(1);
	this->setAsteroidPositionY(1.2f);
	trans = glm::translate(trans, glm::vec3(this->asteroidPosition.x, this->asteroidPosition.y, 0.0));
	this->applyTrans(trans, programID);
	this->setAsteroidHP(HPArray[level]);
	//this->applyColor(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f), programID);

	/*unsigned int transformLoc2 = glGetUniformLocation(programID, "color");
	glUniform4fv(transformLoc2, 1, glm::value_ptr(glm::vec4(0.0f, 0.1f * HPArray[level], 0.0f, 1.0f)));*/
}

void Asteroid::despawnAsteroid(glm::mat4 trans, GLuint programID, float left, float right, int level)
{
	if (this->getAsteroidPositionY() <= -1.6)
		this->spawnAsteroid(trans, programID, left, right, level);
}


void Asteroid::shootDown()
{
	glTranslatef(this->getAsteroidPositionX(), this->getAsteroidPositionY(),
		0.0f);
	glClear(GL_TRIANGLES);
}


void Asteroid::asteroidLevelUp()
{
	if (this->getFallSpeed() < 0.5)
		this->setFallSpeed(this->getFallSpeed() * 1.35);
	else std::cout << "YOU HAVE REACHED MAX LEVEL";

	//this->setAsteroidHP(this->getAsteroidHP() * 500);
}


glm::vec3 Asteroid::getAsteroidPosition()
{
	return this->asteroidPosition;
}

float Asteroid::getAsteroidPositionX()
{
	return this->asteroidPosition.x;
}

float Asteroid::getAsteroidPositionY()
{
	return this->asteroidPosition.y;
}

int Asteroid::getAsteroidHP()
{
	return this->HP;
}

float Asteroid::getFallSpeed()
{
	return this->fallSpeed;
}

void Asteroid::setAsteroidPosition(glm::vec3 asteroidPosition)
{
	this->asteroidPosition = asteroidPosition;
}

void Asteroid::setAsteroidPositionX(float x)
{
	this->asteroidPosition.x = x;
}

void Asteroid::setAsteroidPositionY(float y)
{
	this->asteroidPosition.y = y;
}

void Asteroid::setAsteroidHP(int HP)
{
	this->HP = HP;
}

void Asteroid::setFallSpeed(float fallSpeed)
{
	this->fallSpeed = fallSpeed;
}