#pragma once
#ifndef FFlag_hpp
#define FFlag_hpp
#include "Object.hpp"
using namespace std;

//Uses the parent object class to make a flag object for the game. Has functions to update position and render.


class FFlag : public Object
{
private:
    SDL_Texture* text;
public:
    FFlag(const char* file, int x, int y);
    void Updatepos(int i);
    void Render();
    void Update(bool l, bool r);
};
#endif