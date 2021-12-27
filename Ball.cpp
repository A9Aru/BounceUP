#include<SDL2/SDL.h>
#include<iostream>
#include<SDL2/SDL_image.h>
#include "Ball.hpp"
#include "Texture.hpp"

using namespace std;

Ball::Ball(const char* file,int x,int y, int r,SDL_Renderer* renderer)
{
    x_pos=x;
    y_pos = y;
    radius = r;
    degrees=new double;
    (*degrees)=0;
    y_velocity = 0;
    srec={0,0,NULL,NULL};
    drec={x,y,radius,radius};
    balltext=Texture::LoadTexture(file, renderer);
    rotate=false;
}

void Ball::Update(){
    keyboardinput();
    drec.x=x_pos;
    drec.y=y_pos;
    drec.h=radius;
    drec.w=radius;

}

void Ball::Render(SDL_Renderer* renderer){
    if(rotate==true) SDL_RenderCopyEx(renderer, balltext, NULL, &drec, *degrees, NULL, SDL_FLIP_NONE);
    else SDL_RenderCopy(renderer, balltext, NULL, &drec);
}

void Ball::setdeg(double deg){
    (*degrees)+=deg;
    if(*degrees>=360) (*degrees)-=360;
    else if(*degrees<=-360) *degrees+=360;
}

void Ball::keyboardinput(){
    const Uint8* currkey=SDL_GetKeyboardState(NULL);
    
    if((currkey[SDL_SCANCODE_W] || currkey[SDL_SCANCODE_UP]) && (currkey[SDL_SCANCODE_LEFT] || currkey[SDL_SCANCODE_A])){
        cout<<"W and A is pressed"<<endl;
        y_pos-=2;
        this->setdeg(-5);
        rotate=true;
        cout<<"Rotate Left by"<<*degrees<<"\n";
    }
    else if((currkey[SDL_SCANCODE_W] || currkey[SDL_SCANCODE_UP]) && (currkey[SDL_SCANCODE_RIGHT] || currkey[SDL_SCANCODE_D])){
        cout<<"W and D is pressed"<<endl;
        y_pos-=2;
        this->setdeg(5);
        rotate=true;
        cout<<"Rotate Right by "<<*degrees<<"\n";
    }
    else if((currkey[SDL_SCANCODE_S] || currkey[SDL_SCANCODE_DOWN]) && (currkey[SDL_SCANCODE_LEFT] || currkey[SDL_SCANCODE_A])){
        cout<<"W and A is pressed"<<endl;
        y_pos+=2;
        this->setdeg(-5);
        rotate=true;
        cout<<"Rotate Left by"<<*degrees<<"\n";
    }
    else if((currkey[SDL_SCANCODE_S] || currkey[SDL_SCANCODE_DOWN]) && (currkey[SDL_SCANCODE_RIGHT] || currkey[SDL_SCANCODE_D])){
        cout<<"W and D is pressed"<<endl;
        y_pos+=2;
        this->setdeg(5);
        rotate=true;
        cout<<"Rotate Right by "<<*degrees<<"\n";
    }
//  When W is pressed i.e UP arrow
    else if(currkey[SDL_SCANCODE_W]){
        cout<<"W is pressed"<<endl;
        y_pos-=2;
    }
//          When UP arrow is pressed
    else if(currkey[SDL_SCANCODE_UP]){
        cout << "Up is pressed"<<endl;
        y_pos-=2;
    }
//          When S is pressed i.e DOWN arrow
    else if(currkey[SDL_SCANCODE_S]){
        cout<<"S is pressed"<<endl;
        y_pos+=2;
    }
//          When DOWN arrow is pressed
    else if(currkey[SDL_SCANCODE_DOWN]){
        cout << "Down is pressed"<<endl;
        y_pos+=2;
    }
//          When D is pressed i.e RIGHT arrow
    else if(currkey[SDL_SCANCODE_D]){
        cout<<"D is pressed\n";
        this->setdeg(5);
        rotate=true;
        cout<<"Rotate Right by "<<*degrees<<"\n";
    }
//          When RIGHT arrow
    else if (currkey[SDL_SCANCODE_RIGHT]){
        cout<<"-> is pressed\n";
        this->setdeg(5);
        rotate=true;
        cout<<"Rotate Right by "<<*degrees<<"\n";
    }
//              When A is pressed i.e LEFT arrow
    else if (currkey[SDL_SCANCODE_A]){
        cout<<"A is pressed\n";
        this->setdeg(-5);
        rotate=true;
        cout<<"Rotate Left by "<<*degrees<<"\n";
    }
//          When LEFT arrow is pressed
    else if (currkey[SDL_SCANCODE_LEFT]){
        cout<<"<- is pressed\n";
        this->setdeg(-5);
        rotate=true;
        cout<<"Rotate Left by "<<*degrees<<"\n";
    }
}
