#pragma once
#include "Map.hpp"
#include<vector>
#include <SDL2/SDL.h>

class CollisionHandler
{
public:
	bool checkCollision(SDL_Rect *a, SDL_Rect *b);
	void checkMapCollision(SDL_Rect* a);
	Map* m;
	CollisionHandler(Map *pointer);
	int start, end;
};