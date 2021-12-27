#include<SDL2/SDL.h>
#include<iostream>
#include<SDL2/SDL_image.h>
#include "Ball.hpp"

using namespace std;

Ball::Ball(int y, int r)
{
    y_pos = y;
    radius = r;
    degrees=new double;
    y_velocity = 0;
    text_rec={y,360,radius,radius};
}

int Ball::get_y()
{
    return y_pos;
}

SDL_Surface* Ball::getsurface(){
    return Ballimage;
}

SDL_Texture* Ball::gettext(){
    return balltext;
}

SDL_Rect* Ball::getrect(){
    return &text_rec;
}

SDL_RendererFlip Ball::getflip(){
    return fliptype;
}

double Ball::getdeg(){
    return *degrees;
}

void Ball::set_y(int y){
    y_pos=y;
    text_rec.y=y_pos;
}

void Ball::setflip(SDL_RendererFlip flip){
    fliptype=flip;
}

void Ball::setdeg(double deg){
    (*degrees)=deg;
    if(*degrees>=360) (*degrees)-=360;
    else if(*degrees<=-360) *degrees+=360;
}

void Ball::loadimage(SDL_Renderer* renderer){
    Ballimage=IMG_Load("images/2.png");
    if(Ballimage==nullptr){
        cout<<"Failed to load image:"<<IMG_GetError()<<endl;
    }
    else{
        balltext=SDL_CreateTextureFromSurface(renderer, Ballimage);
    }
}

//void Ball :: update()
//{
//  cout<<"X vel:"<<x_velocity<<" Y vel:"<<y_velocity<<endl;
//  x_pos += x_velocity;
//  y_pos += y_velocity;
//
//  if (y_pos <= 20 || y_pos >= 400 - 20)
//    {
//      y_velocity *= -1;
//      std::cout << "Y: " << this->get_y() << std::endl;
//    }
//    if (x_pos <= 20 || x_pos >= 640 - 20)
//    {
//      x_velocity=0;
//      std::cout << "X: " << this->get_x()<<"X vel: "<<x_velocity << std::endl;
//    }
//}
//
//void Ball::poll_events(SDL_Event &event)
//{
//      switch (event.type)
//      {
////          When W is pressed i.e UP arrow
//            case SDL_SCANCODE_W:
//                cout<<"W is pressed"<<endl;
//                if (y_velocity > -18)
//                {
//                  y_velocity -= 2;
//                  x_velocity = 0;
//                }
//                update();
//                break;
////          When UP arrow is pressed
//            case SDL_SCANCODE_UP:
//                if (y_velocity > -18)
//                {
//                y_velocity -= 2;
//                x_velocity = 0;
//                }
//                update();
//                break;
////          When S is pressed i.e DOWN arrow
//            case SDL_SCANCODE_S:
//              cout<<"S is pressed"<<endl;
//              if (y_velocity < 18)
//              {
//                  x_velocity = 0;
//                  y_velocity += 2;
//              }
//              update();
//              break;
////          When DOWN arrow is pressed
//            case SDL_SCANCODE_DOWN:
//              if (y_velocity < 18)
//              {
//                  x_velocity = 0;
//                  y_velocity += 2;
//              }
//              update();
//              break;
////          When D is pressed i.e RIGHT arrow
//            case SDL_SCANCODE_D:
//                cout<<"D is pressed"<<endl;
//                if ((x_pos <= 640 - 20)&&(x_velocity < 18))
//                {
//                  x_velocity += 2;
//                  y_velocity = 0;
//                }
//                else if(x_pos>620){
//                x_velocity=0;
//                y_velocity=0;
//                }
//                else{
//                x_velocity=18;
//                y_velocity=0;
//                }
//                update();
//                break;
////          When RIGHT arrow
//            case SDL_SCANCODE_RIGHT:
//              cout<<"D is pressed"<<endl;
//              if ((x_pos <= 640 - 20)&&(x_velocity < 18))
//              {
//                x_velocity += 2;
//                y_velocity = 0;
//              }
//              else if(x_pos>620){
//              x_velocity=0;
//              y_velocity=0;
//              }
//              else{
//              x_velocity=18;
//              y_velocity=0;
//              }
//              update();
//              break;
////              When A is pressed i.e LEFT arrow
//            case SDL_SCANCODE_A:
//                cout<<"A is pressed"<<endl;
//                if ((x_pos >= 20)&&(x_velocity > -18) )
//                {
//                  y_velocity = 0;
//                  x_velocity -= 2;
//                }
//                else if (x_pos < 20){
//                x_velocity=0;
//                y_velocity=0;
//                }
//                else{
//                x_velocity=-18;
//                y_velocity=0;
//                }
//                update();
//                break;
////          When LEFT arrow is pressed
//            case SDL_SCANCODE_LEFT:
//              cout<<"A is pressed"<<endl;
//              if ((x_pos >= 20)&&(x_velocity > -18) )
//              {
//                y_velocity = 0;
//                x_velocity -= 2;
//              }
//              else if (x_pos < 20){
//              x_velocity=0;
//              y_velocity=0;
//              }
//              else{
//              x_velocity=-18;
//              y_velocity=0;
//              }
//              update();
//              break;
//      }
//}

