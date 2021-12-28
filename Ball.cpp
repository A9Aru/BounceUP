#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include "Ball.hpp"
#include "Rock.hpp"
#include "Texture.hpp"
#include "game.hpp"

using namespace std;

Ball::Ball(const char* file,int x,int y, int r)
{
    x_pos=x;
    y_pos = y;
    radius = r;
    degrees=new double;
    (*degrees)=0;
    y_velocity = 0;
    srec={0,0,NULL,NULL};
    drec={x,y,radius,radius};
    balltext=Texture::LoadTexture(file, Game :: renderer);
    rotate=false;
}

void Ball::Update(Rock *r){
    keyboardinput(r);
    drec.x=x_pos;
    drec.y=y_pos;
    drec.h=radius;
    drec.w=radius;

}

void Ball::Render(){
    if(rotate==true) SDL_RenderCopyEx(Game :: renderer, balltext, NULL, &drec, *degrees, NULL, SDL_FLIP_NONE);
    else SDL_RenderCopy(Game :: renderer, balltext, NULL, &drec);
}

void Ball::setdeg(double deg){
    (*degrees)+=deg;
    if(*degrees>=360) (*degrees)-=360;
    else if(*degrees<=-360) *degrees+=360;
}

void Ball::keyboardinput(Rock *r){
    const Uint8* currkey=SDL_GetKeyboardState(NULL);
    
    if((currkey[SDL_SCANCODE_W] || currkey[SDL_SCANCODE_UP])){
        cout<<"W and A is pressed"<<endl;
        if(y_velocity > -10)
            y_velocity -= 2;
        y_pos = y_pos + (y_velocity)/10;
        if (x_velocity > 0)
        {
            this->setdeg(-5);
            rotate=true;
            x_velocity--;
            r->Update(-1);
        }
        else if (x_velocity < 0)
        {
            this->setdeg(-5);
            rotate = true;
            x_velocity++;
            r->Update(1);
        }
        cout<<"Rotate Left by"<<*degrees<<"\n";
    }
    else if((currkey[SDL_SCANCODE_S] || currkey[SDL_SCANCODE_DOWN])){
        cout<<"W and A is pressed"<<endl;
        if(y_velocity < 10)
            y_velocity += 2;
        y_pos = y_pos + (y_velocity)/10;
        /*if (y_velocity<10)
            y_velocity++;
        y_pos+=y_velocity;*/
        y_pos += 2;
        if (x_velocity > 0)
        {
            this->setdeg(-5);
            rotate=true;
            x_velocity--;
            r->Update(-1);
        }
        else if (x_velocity < 0)
        {
            this->setdeg(5);
            rotate = true;
            x_velocity++;
            r->Update(1);
        }
        cout<<"Rotate Left by"<<*degrees<<"\n";
    }
//  When W is pressed i.e UP arrow
   /* else if (currkey[SDL_SCANCODE_W]) {
        cout<<"W is pressed"<<endl;
        y_velocity -= 3;
        y_pos = y_pos - (y_velocity)/10;
        if (y_pos > 600)
            y_pos = 600;
    }
//          When UP arrow is pressed
    else if(currkey[SDL_SCANCODE_UP]){
        cout << "Up is pressed"<<endl;
        y_velocity -= 3;
        y_pos = y_pos - (y_velocity) / 10;
        if (y_pos > 600)
            y_pos = 600;
    }
//          When S is pressed i.e DOWN arrow
    else if(currkey[SDL_SCANCODE_S]){
        cout<<"S is pressed"<<endl;
        y_velocity += 3;
        y_pos = y_pos + (y_velocity) / 10;
        if (y_pos > 600)
            y_pos = 600;
    }
//          When DOWN arrow is pressed
    else if(currkey[SDL_SCANCODE_DOWN]){
        cout << "Down is pressed"<<endl;
        y_velocity += 3;
        y_pos = y_pos + (y_velocity) / 10;
        if (y_pos > 600)
            y_pos = 600;
    }*/
//          When D is pressed i.e RIGHT arrow
    else if(currkey[SDL_SCANCODE_D]){
        x_velocity++;
        cout<<"D is pressed\n";
        this->setdeg(5);
        rotate=true;
        r->Update(-1);
        cout<<"Rotate Right by "<<*degrees<<"\n";
    }
//          When RIGHT arrow
    else if (currkey[SDL_SCANCODE_RIGHT]){
        x_velocity++;
        cout << "-> is pressed\n";
        this->setdeg(5);
        rotate=true;
        r->Update(-1);
        cout<<"Rotate Right by "<<*degrees<<"\n";
    }
//              When A is pressed i.e LEFT arrow
    else if (currkey[SDL_SCANCODE_A]){
        x_velocity--;
        cout<<"A is pressed\n";
        this->setdeg(-5);
        rotate=true;
        r->Update(1);
        cout<<"Rotate Left by "<<*degrees<<"\n";
    }
//          When LEFT arrow is pressed
    else if (currkey[SDL_SCANCODE_LEFT]){
        y_velocity += 1;
        x_velocity--;
        cout<<"<- is pressed\n";
        this->setdeg(-5);
        rotate=true;
        r->Update(1);
        cout<<"Rotate Left by "<<*degrees<<"\n";
    }
}
