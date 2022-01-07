#pragma once
#ifndef Obstacle_hpp
#define Obstacle_hpp
#include "Object.hpp"
using namespace std;

//class of obstacles in the game. Has functions for update position and render functions

class Obstacle: public Object
{
private:
    SDL_Texture* text;
public:
    Obstacle(const char* file, int x, int y);
    void Updatepos(int i);
    void Render();
    void Update(bool l, bool r);
};
#endif
