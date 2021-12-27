#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include "Game.hpp"

using namespace std;

class Object
{
protected:
    int x_pos,y_pos;
    int x_velocity,y_velocity;
    SDL_Texture *text;
    SDL_Rect srec,drec;

public:
    Object(const char* file,int x,int y,SDL_Renderer* renderer);
    void setsrec(int x,int y,int width,int height);
    void setdrec(int x,int y,int width,int height);
};


#endif /* Object_hpp */
