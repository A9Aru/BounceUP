#include<SDL2/SDL.h>
#include<iostream>
#include<SDL2/SDL_image.h>
#include "Rock.hpp"
Rock::Rock(int x, int y)
{
    x_pos = x;
    y_pos = y;
}
int Rock::get_x()
{
    return x_pos;
}
int Rock::get_y()
{
    return y_pos;
}
void Rock::rockRenderer(SDL_Renderer* renderer)
{
    SDL_Texture* texture = NULL;
    SDL_Surface* temp = IMG_Load("rock.png");
    texture = SDL_CreateTextureFromSurface(renderer, temp);
    SDL_FreeSurface(temp);
    SDL_Rect rect;
    rect.x = 250; //Extreme left of the window
    rect.y = 500; //Very bottom of the window
    rect.w = 50; //100 pixels width
    rect.h = 50; //100 pixels height
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
}