#ifndef Ball_hpp
#define Ball_hpp
#include "Game.hpp"
#include "Rock.hpp"
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
    Ball(const char* file,int x,int y, int r);
    
    void Update(class Rock * r);
    void Render();
    void keyboardinput(Rock *r);
    void setdeg(double deg);
};

#endif /* Ball_hpp */
