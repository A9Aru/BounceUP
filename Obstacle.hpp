#pragma once
#ifndef Obstacle_hpp
#define Obstacle_hpp
#include "Object.hpp"
using namespace std;

class Obstacle: public Object
{
private:
    SDL_Texture* text;
public:
    Obstacle(const char* file, int x, int y);
    void Updatepos(int i);
    void Render();
    void Update();
};
#endif
