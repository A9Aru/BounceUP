#ifndef Ball_hpp
#define Ball_hpp
#include "Game.hpp"
#include "Rock.hpp"
#include "Coin.hpp"
using namespace std;

/*Class for ball. Uses x and y position and velocities. Has radius for size. Uses SDL_Texture and SDL_Rect to create ball image
Has functions to update position based on keyboard input and render the object.*/

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
    
    void Update(bool d, bool u);
    void Render();
    void keyboardinput(bool d, bool u);
//    void keyboardinput(Coin* c);
    void setdeg(double deg);
    SDL_Rect* getdrec();
};

#endif /* Ball_hpp */
