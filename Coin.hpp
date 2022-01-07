#pragma once
#ifndef Coin_hpp
#define Coin_hpp
#include "Object.hpp"
using namespace std;
//Uses the parent object class to make a coin object for the game. Has functions to update position and render.
class Coin : public Object
{
private:
    SDL_Texture* text;
public:
    Coin(const char* file, int x, int y);
    void Updatepos(int i);
    void Render();
    void Update(bool l, bool r);
};
#endif
