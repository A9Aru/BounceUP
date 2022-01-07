#ifndef Rock_hpp
#define Rock_hpp
#include "Object.hpp"
using namespace std;

//Uses the parent object class to make a coin object for the game. Has functions to update position and render.

class Rock : public Object
{
public:
    Rock(const char* file, int x, int y);
    void Updatepos(int i);
    void Render();
    void Update(bool left, bool right);
};

#endif
