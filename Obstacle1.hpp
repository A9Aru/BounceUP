
#ifndef Obstacle1_hpp
#define Obstacle1_hpp
#include "Object.hpp"
using namespace std;

class Obstacle1 : public Object
{
private:
    SDL_Texture* text;
public:
    Obstacle1(const char* file, int x, int y);
    void Updatepos(int i);
    void Render();
    void Update(bool l, bool r);
};
#endif
