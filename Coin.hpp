#include "Window.hpp"
#pragma once
class Coin {
public:
	Coin();
	virtual void generateObstacle(Window* window);
	virtual void draw(SDL_Renderer* renderer, Window* window);
	virtual void handleCollision();
	virtual ~Coin();
	virtual int ObstacleID();
private:
	int stage;
	int ticks;
	int totalStages;
	bool launching;
};