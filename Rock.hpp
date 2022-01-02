#ifndef Rock_hpp
#define Rock_hpp
#include "Object.hpp"
using namespace std;

class Rock: public Object
{
    bool left = true;
    bool right = true;
public:
    Rock(const char* file,int x,int y);
    void Updatepos(int i);
    void Render();
    void Update();
    void setLeft(bool m);
    void setRight(bool m);
};

#endif
