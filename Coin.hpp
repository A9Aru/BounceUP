#pragma once
#ifndef Coin_hpp
#define Coin_hpp
#include "Object.hpp"
using namespace std;

class Coin : public Object
{
private:
    SDL_Texture* text;
public:
    Coin(const char* file, int x, int y);
    void Update(int i);
    void Render();
    void keyboardinput();
};
#endif