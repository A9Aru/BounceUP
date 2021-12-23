#pragma once
#include<string>
#include<SDL.h>
#include<SDL_image.h>

using namespace std;

class window
{
	int width;
	int height;
	bool closed = false;
	string name;
	bool init();
	SDL_Window* win = nullptr;
	SDL_Renderer* renderer = nullptr;
public:
	window(const string &title, int height, int width);
	bool isClosed();
	void pollEvents(SDL_Event &event);
	void render();
	void close();
	SDL_Renderer* get_renderer();
};