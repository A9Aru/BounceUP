#ifndef Rock_hpp
#define Rock_hpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
using namespace std;

class Rock
{
    private:
        int length, breadth, x_pos, y_pos;
        SDL_Rect rrect;
        SDL_Texture *rocktext =nullptr;
        SDL_Surface *rocksurface=nullptr;
    public:
        Rock(int x, int y);
        int get_x();
        int get_y();
        SDL_Texture* gettext();
        SDL_Surface* getsurface();
        SDL_Rect* getrect();
        void loadimage(SDL_Renderer* renderer);
};
#endif
