#ifndef Ball_hpp
#define Ball_hpp
#include "Game.hpp"
#include "Rock.hpp"
#include "Coin.hpp"
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
    
    void Update();
    void Render();
    void keyboardinput();
//    void keyboardinput(Coin* c);
    void setdeg(double deg);
    SDL_Rect* getdrec();
};

#endif /* Ball_hpp */
