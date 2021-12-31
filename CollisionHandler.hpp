#pragma once
#include "Map.hpp"
#include<vector>
#include <SDL2/SDL.h>
#include "Score.hpp"

class CollisionHandler
{
public:
	bool checkCollision(SDL_Rect *a, SDL_Rect *b);
    bool checkCircularCollision(SDL_Rect *a, SDL_Rect *b);
	void checkMapCollision(SDL_Rect* a,Score* s);
	Map* m;
    CollisionHandler(Map *pointer);
};
