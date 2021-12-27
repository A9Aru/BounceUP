#include "Rock.hpp"

Rock::Rock(const char* file,int x,int y,SDL_Renderer* renderer): Object(file, x, y, renderer)
{
    Object::setdrec(400, 500, 100, 100);
    Object::setsrec(0,0,NULL,NULL);
}

void Rock::Update(){
    x_pos++;
    if(x_pos<0) x_pos=1280;
    if(x_pos>1280) x_pos=0;
    setdrec(x_pos, y_pos, 100, 100);
}

void Rock::Render(SDL_Renderer *renderer){
    SDL_RenderCopy(renderer, Object::text, NULL, &(Object::drec));
}

void Rock::keyboardinput(){
    
}
