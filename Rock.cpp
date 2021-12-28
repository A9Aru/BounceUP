#include "Rock.hpp"
#include "Game.hpp"
Rock::Rock(const char* file,int x,int y): Object(file, x, y, Game :: renderer)
{
    Object::setdrec(x_pos, y_pos, 100, 100);
    Object::setsrec(0,0,NULL,NULL);
}

void Rock::Update(int i){
    x_pos+=(i*5);
    if(x_pos<0) x_pos=1280;
    if(x_pos>1280) x_pos=0;
    setdrec(x_pos, y_pos, 100, 100);
}

void Rock::Render(){
    SDL_RenderCopy(Game :: renderer, Object::text, NULL, &(Object::drec));
}

void Rock::keyboardinput(){
    
}
