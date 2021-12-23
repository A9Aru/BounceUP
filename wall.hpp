#ifndef Wall_hpp
#define Wall_hpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
using namespace std;

class wall
{
    private:
        int length, breadth, x_pos, y_pos;
    public:
        wall(int x, int y);
        int get_x();
        int get_y();
        void render(SDL_Renderer* renderer, int cx, int cy, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};