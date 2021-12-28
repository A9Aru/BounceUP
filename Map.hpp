#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Object.hpp"
#include <vector>

class Map
{
	SDL_Rect src, dest;

	SDL_Texture* rock;
	//SDL_Texture* coin;
	//SDL_Texture* lighting;

public:
	Map();
	~Map();
	void loadMap(int arr[40][40]);
	void drawMap();
	int map[40][40];
};