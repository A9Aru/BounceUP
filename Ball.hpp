#ifndef Ball_hpp
#define Ball_hpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
using namespace std;

class Ball
{
private:
    int y_pos;
    int radius;
    int y_velocity;
    SDL_Surface *Ballimage=nullptr;
    SDL_Texture *balltext=nullptr;
    SDL_Rect text_rec;
    double *degrees = new double;
    SDL_RendererFlip fliptype=SDL_FLIP_NONE;
    
public:
    Ball(int y, int r);
//    void update();
    int get_y();
    SDL_Surface* getsurface();
    SDL_Texture* gettext();
//    void poll_events(SDL_Event &event);
    SDL_Rect* getrect();
    SDL_RendererFlip getflip();
    double getdeg();
    void setdeg(double deg);
    void set_y(int y);
    void setflip(SDL_RendererFlip flip);
    void loadimage(SDL_Renderer* renderer);
};

#endif /* Ball_hpp */