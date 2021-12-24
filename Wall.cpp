#include<SDL2/SDL.h>
#include<iostream>
#include<SDL2/SDL_image.h>
#include "wall.hpp"
wall::wall(int x, int y)
{
    x_pos = x;
    y_pos = y;
}
int wall::get_x()
{
    return x_pos;
}
int wall::get_y()
{
    return y_pos;
}
void wall::render(SDL_Renderer* renderer, int cx, int cy, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_RenderClear(renderer);

    SDL_Rect rect;
    rect.x = cx;
    rect.y = cy;
    rect.w = w;
    rect.h = h;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}

