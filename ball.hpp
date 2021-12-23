#ifndef Ball_hpp
#define Ball_hpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
using namespace std;

class ball
{
    int x_pos;
    int y_pos;
    int radius;
    int x_velocity;
    int y_velocity;
public:
    ball(int x, int y, int r);
    void update();
    int get_x();
    int get_y();
    void poll_events(SDL_Event &event);
    void render(SDL_Renderer* renderer, int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};

#endif /* Ball_hpp */
