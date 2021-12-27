#include<SDL2/SDL.h>
#include<iostream>
#include<SDL2/SDL_image.h>
#include "Rock.hpp"
Rock::Rock(int x, int y)
{
    x_pos = x;
    y_pos = y;
    rrect={x,y,100,100};
}
int Rock::get_x()
{
    return x_pos;
}
int Rock::get_y()
{
    return y_pos;
}
SDL_Texture* Rock::gettext(){
    return rocktext;
}
SDL_Surface* Rock::getsurface(){
    return rocksurface;
}
SDL_Rect* Rock::getrect(){
    return &rrect;
}
void Rock::loadimage(SDL_Renderer* renderer){
    rocksurface=IMG_Load("rock.png");
    if(rocksurface==nullptr){
        cout<<"Failed to load image:"<<IMG_GetError()<<endl;
    }
    else{
        rocktext=SDL_CreateTextureFromSurface(renderer, rocksurface);
    }
}
