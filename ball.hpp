#ifndef Ball_hpp
#define Ball_hpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
using namespace std;

class Ball
{
private:
    int x_pos;
    int y_pos;
    int radius;
    int x_velocity;
    int y_velocity;
    SDL_Surface *Ballimage=nullptr;
    
public:
    Ball(int x, int y, int r);
    void update();
    int get_x();
    int get_y();
    SDL_Surface* getsurface();
    void poll_events(SDL_Event &event);
    void render(SDL_Renderer* renderer, int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void loadimage(SDL_Surface *image);
};

#endif /* Ball_hpp */
