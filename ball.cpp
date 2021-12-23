#pragma once
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include<SDL_timer.h>
#include "ball.hpp"

#define gravity 9.81;

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
	/*static float timer = 0.0;
	int dt = SDL_GetTicks()/1000 - timer;
	cout << dt << endl ;
	timer += SDL_GetTicks();
	x_pos += x_velocity * dt;
	y_pos += y_velocity*dt + 0.5 * dt * dt * gravity;
	*/

	if (x_pos <= 20 || x_pos >= 640 - 20)
	{
		x_velocity *= -1;
		std::cout << "X: " << this->get_x() << std::endl;
	}
	if (y_pos <= 20 || y_pos >= 400 - 20)
	{
		y_velocity = -1;
		std::cout << "Y: " << this->get_y() << std::endl;
	}
}

void ball::poll_events(SDL_Event &event)
{
		switch (event.key.keysym.scancode)
		{
		case SDL_SCANCODE_W:
			if (y_velocity > -18)
			{
				y_velocity -= 2;
				x_velocity = 0;
			}
			update();
			break;
		case SDL_SCANCODE_S:
			if (y_velocity < 18)
			{
				x_velocity = 0;
				y_velocity += 2;
			}
			update();
			break;
		case SDL_SCANCODE_D:
			if (x_velocity < 18)
			{
				x_velocity += 2;
				y_velocity = 0;
			}
			update();
			break;
		case SDL_SCANCODE_A:
			if (x_velocity > -18)
			{
				y_velocity = 0;
				x_velocity -= 2;
			}
			update();
			break;
		}
}