#ifndef Rock_hpp
#define Rock_hpp
#include "Object.hpp"
using namespace std;

class Rock: public Object
{
private:
    int length,breadth;
public:
    Rock(const char* file,int x,int y,SDL_Renderer* renderer);
    void Update();
    void Render(SDL_Renderer* renderer);
    void keyboardinput();
};
#endif
