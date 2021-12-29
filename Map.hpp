#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Object.hpp"
#include "Rock.hpp"
#include "Coin.hpp"
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
	void loadMap(int arr[16][9]);
	void drawMap();
	void create_rock(int x, int y);
	void create_coin(int x, int y);
	void render_objects();
	Coin* coins;
	Rock* rocks;
	vector<Rock *> level_rocks;
	vector<Coin*> level_coins;
	int map[40][40];
};