#ifndef Rock_hpp
#define Rock_hpp
#include "Object.hpp"
using namespace std;

class Rock: public Object
{
public:
    Rock(const char* file,int x,int y);
    void Updatepos(int i);
    void Render();
    void Update();
};
#endif
