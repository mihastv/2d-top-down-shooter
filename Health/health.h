#pragma once

#include "..\dependente\glew\glew.h"

#include "..\dependente\glfw\glfw3.h"

#include "..\dependente\glm\glm.hpp"
#include "..\dependente\glm\gtc\matrix_transform.hpp"
#include "..\dependente\glm\gtc\type_ptr.hpp"

class Health
{
private:
	glm::vec3 healthPosition;
	int HP;
	float fallSpeed;

public:
	Health();
	Health(glm::vec3 healthPosition,int HP, float fallSpeed);
	~Health();

	void applyTrans(glm::mat4 trans, GLuint programID);
	void moveDown(GLuint programID);
	void checkMotion(GLuint programID, GLuint VAO);
	void spawnHealth(glm::mat4 trans, GLuint programID);
	void despawnHealth(glm::mat4 trans, GLuint programID);

	glm::vec3 getHealthPosition();
	float getHealthPositionX();
	float getHealthPositionY();
	int getHealthHP();
	float getFallSpeed();

	void setHealthPosition(glm::vec3 healthPosition);
	void setHealthPositionX(float x);
	void setHealthPositionY(float y);
	void setHealthHP(int HP);
	void setFallSpeed(float fallSpeed);
};