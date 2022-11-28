#pragma once

#include "..\dependente\glew\glew.h"

#include "..\dependente\glfw\glfw3.h"

#include "..\dependente\glm\glm.hpp"
#include "..\dependente\glm\gtc\matrix_transform.hpp"
#include "..\dependente\glm\gtc\type_ptr.hpp"

class Asteroid
{
private:
	glm::vec3 asteroidPosition;
	int HP;
	float fallSpeed;

public:
	Asteroid();
	Asteroid(glm::vec3 asteroidPosition, int HP, float fallSpeed);
	~Asteroid();

	void applyColor(glm::vec4 color, GLuint programID);
	void applyTrans(glm::mat4 trans, GLuint programID);
	void applyRotation(glm::mat4 trans, GLuint programID);
	void moveDown(GLuint programID);
	void checkMotion(GLuint programID,GLuint VAO);
	void shootDown();

	void spawnAsteroid(glm::mat4 trans, GLuint programID, float left, float right, int level);

	void despawnAsteroid(glm::mat4 trans, GLuint programID, float left, float right, int level);

	void asteroidLevelUp();


	glm::vec3 getAsteroidPosition();
	float getAsteroidPositionX();
	float getAsteroidPositionY();
	int getAsteroidHP();
	float getFallSpeed();

	void setAsteroidPosition(glm::vec3 asteroidPosition);
	void setAsteroidPositionX(float x);
	void setAsteroidPositionY(float y);
	void setAsteroidHP(int HP);
	void setFallSpeed(float fallSpeed);
};