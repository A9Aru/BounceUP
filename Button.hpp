#pragma once
#include <SDL2/SDL.h>
class Button{
public:
    SDL_Rect box;
    Button(int x_pos,int y_pos,int width,int height){
        box.x = x_pos;
        box.y= y_pos;
        box.w= width;
        box.h = height;
    }

}; 
