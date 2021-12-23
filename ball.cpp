#pragma once
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include "ball.h"

using namespace std;

ball::ball(int x, int y, int r)
{
	x_pos = x;
	y_pos = y;
	radius = r;
	
	x_velocity = 0;
	y_velocity = 0;
}

int ball::get_x()
{
	return x_pos;
}

int ball::get_y()
{
	return y_pos;
}

void ball::render(SDL_Renderer* renderer, int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	static const int BPP = 4;

	for (double dy = 1; dy <= radius; dy += 1.0)
	{
		double dx = floor(sqrt((2.0 * radius * dy) - (dy * dy)));
		int x = (cx - dx);

		SDL_SetRenderDrawColor(renderer, r, g, b, a);
		SDL_RenderDrawLine(renderer, (cx - dx), cy + dy - radius, (cx + dx), cy + dy - radius);
		SDL_RenderDrawLine(renderer, (cx - dx), cy - dy + radius, (cx + dx), cy - dy + radius);
	}
}

void ball :: update()
{
	x_pos += x_velocity;
	y_pos += y_velocity;

	if (x_pos <= 20 || x_pos >= 640 - 20)
	{
		x_velocity *= -1;
		std::cout << "X: " << this->get_x() << std::endl;
	}
	if (y_pos <= 20 || y_pos >= 400 - 20)
	{
		y_velocity *= -1;
		std::cout << "Y: " << this->get_y() << std::endl;
	}
}

void ball::poll_events(SDL_Event &event)
{
		switch (event.type)
		{
			case SDL_KEYDOWN:
				cout << "Key is down" << endl;
				switch (event.key.keysym.scancode)
				{
				case SDL_SCANCODE_W:
					y_velocity -= 3;
					update();
					break;
				case SDL_SCANCODE_S:
					y_velocity += 3;
					update();
					break;
				case SDL_SCANCODE_D:
					x_velocity += 3;
					update();
					break;
				case SDL_SCANCODE_A:
					x_velocity -= 3;
					update();
					break;
				}
			break;
		}
}