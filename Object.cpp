#include "Object.hpp"

Object::Object(const char* file,int x,int y,SDL_Renderer* renderer){
    text=Texture::LoadTexture(file, renderer);
    x_pos=x;
    y_pos=y;
}

void Object::setsrec(int x,int y,int width,int height){
    srec.x=x;
    srec.y=y;
    srec.h=height;
    srec.w=width;
}

void Object::setdrec(int x,int y,int width,int height){
    drec.x=x;
    drec.y=y;
    drec.h=height;
    drec.w=width;
}
