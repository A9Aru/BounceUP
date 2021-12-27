// #ifndef Wall_hpp
// #define Wall_hpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
using namespace std;

class Rock
{
    private:
        int length, breadth, x_pos, y_pos;
    public:
        Rock(int x, int y);
        int get_x();
        int get_y();
        void rockRenderer(SDL_Renderer* renderer);
};
// #endif
