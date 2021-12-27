#ifndef Ball_hpp
#define Ball_hpp
#include "Game.hpp"
using namespace std;

class Ball
{
private:
    int x_pos,y_pos;
    int radius;
    int x_velocity,y_velocity;
    SDL_Texture *balltext;
    SDL_Rect srec,drec;
    double *degrees = new double;
    bool rotate;
public:
    Ball(const char* file,int x,int y, int r,SDL_Renderer* renderer);
    
    void Update();
    void Render(SDL_Renderer* renderer);
    void keyboardinput();
    void setdeg(double deg);
};

#endif /* Ball_hpp */
