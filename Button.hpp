#pragma once
#include <SDL2/SDL.h>
//Simple class to make a button image.
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
