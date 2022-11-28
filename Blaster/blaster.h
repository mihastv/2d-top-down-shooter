#pragma once

#include "..\dependente\glew\glew.h"

#include "..\dependente\glfw\glfw3.h"

#include "..\dependente\glm\glm.hpp"
#include "..\dependente\glm\gtc\matrix_transform.hpp"
#include "..\dependente\glm\gtc\type_ptr.hpp"


class Blaster
{
private:
	glm::vec3 blasterPosition;
	float blasterSpeed;
	int damage;

public:
	Blaster(glm::vec3 blasterPosition, float blasterSpeed, int damage);
	Blaster();
	~Blaster();

	void applyTrans(glm::mat4 trans, GLuint programID);
	void shootUp(GLFWwindow* window, GLuint programID, float startingPointX, float startingPointY);

	glm::vec3 getBlasterPosition();
	float getBlasterPositionX();
	float getBlasterPositionY();
	float getBlasterSpeed();
	int getBlasterDamage();

	void setBlasterPosition(glm::vec3 blasterPosition);
	void setBlasterPositionX(float x);
	void setBlasterPositionY(float y);
	void setBlasterSpeed(float blasterSpeed);
	void setBlasterDamage(int damage);
};