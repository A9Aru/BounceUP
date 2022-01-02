#pragma once
#ifndef CollisionHandler_hpp
#define CollisionHandler_hpp
#include "Map.hpp"
#include<vector>
#include <SDL2/SDL.h>
#include "Score.hpp"

class CollisionHandler
{
public:
	bool checkCollision(SDL_Rect* a, SDL_Rect* b);
	bool checkCircularCollision(SDL_Rect* a, SDL_Rect* b);
	void checkMapCollision(SDL_Rect* a, Score* s);
	bool checkObstacle(SDL_Rect* a);
	bool checkWallLeftCollision(SDL_Rect* a);
	bool checkWallRightCollision(SDL_Rect* a);
	bool checkFlag(SDL_Rect* a);
	Map* m;
	CollisionHandler(Map* pointer);
};

#endif
