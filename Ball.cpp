#include<SDL2/SDL.h>
#include<iostream>
#include<SDL2/SDL_image.h>
#include "Ball.hpp"

using namespace std;

Ball::Ball(int x, int y, int r)
{
    x_pos = x;
    y_pos = y;
    radius = r;
    
    x_velocity = 0;
    y_velocity = 0;
}

int Ball::get_x()
{
    return x_pos;
}

int Ball::get_y()
{
    return y_pos;
}

void Ball::render(SDL_Renderer* renderer, int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    static const int BPP = 4;

    for (double dy = 1; dy <= radius; dy += 1.0)
    {
        double dx = floor(sqrt((2.0 * radius * dy) - (dy * dy)));
        int x = (cx - dx);

        SDL_SetRenderDrawColor(renderer, r, g, b, a);
        SDL_RenderDrawLine(renderer, (cx - dx), cy + dy - radius, (cx + dx), cy + dy - radius);
        SDL_RenderDrawLine(renderer, (cx - dx), cy - dy + radius, (cx + dx), cy - dy + radius);
    }
}

void Ball::loadimage(SDL_Surface *image){
    Ballimage=image;
    if(Ballimage==nullptr){
        cout<<"Failed to load image:"<<IMG_GetError()<<endl;
    }
}


void Ball :: update()
{
  cout<<x_pos<<" "<<y_pos<<endl;
  cout<<"X vel:"<<x_velocity<<" Y vel:"<<y_velocity<<endl;
  x_pos += x_velocity;
  y_pos += y_velocity;
  
  if (y_pos <= 20 || y_pos >= 400 - 20)
    {
      y_velocity *= -1;
      std::cout << "Y: " << this->get_y() << std::endl;
    }
    if (x_pos <= 20 || x_pos >= 640 - 20)
    {
      x_velocity=0;
      std::cout << "X: " << this->get_x()<<"X vel: "<<x_velocity << std::endl;
    }
}

void Ball::poll_events(SDL_Event &event)
{
      switch (event.type)
      {
//          When W is pressed i.e UP arrow
            case SDL_SCANCODE_W:
                cout<<"W is pressed"<<endl;
                if (y_velocity > -18)
                {
                  y_velocity -= 2;
                  x_velocity = 0;
                }
                update();
                break;
//          When UP arrow is pressed
            case SDL_SCANCODE_UP:
                if (y_velocity > -18)
                {
                y_velocity -= 2;
                x_velocity = 0;
                }
                update();
                break;
//          When S is pressed i.e DOWN arrow
            case SDL_SCANCODE_S:
              cout<<"S is pressed"<<endl;
              if (y_velocity < 18)
              {
                  x_velocity = 0;
                  y_velocity += 2;
              }
              update();
              break;
//          When DOWN arrow is pressed
            case SDL_SCANCODE_DOWN:
              if (y_velocity < 18)
              {
                  x_velocity = 0;
                  y_velocity += 2;
              }
              update();
              break;
//          When D is pressed i.e RIGHT arrow
            case SDL_SCANCODE_D:
                cout<<"D is pressed"<<endl;
                if ((x_pos <= 640 - 20)&&(x_velocity < 18))
                {
                  x_velocity += 2;
                  y_velocity = 0;
                }
                else if(x_pos>620){
                x_velocity=0;
                y_velocity=0;
                }
                else{
                x_velocity=18;
                y_velocity=0;
                }
                update();
                break;
//          When RIGHT arrow
            case SDL_SCANCODE_RIGHT:
              cout<<"D is pressed"<<endl;
              if ((x_pos <= 640 - 20)&&(x_velocity < 18))
              {
                x_velocity += 2;
                y_velocity = 0;
              }
              else if(x_pos>620){
              x_velocity=0;
              y_velocity=0;
              }
              else{
              x_velocity=18;
              y_velocity=0;
              }
              update();
              break;
//              When A is pressed i.e LEFT arrow
            case SDL_SCANCODE_A:
                cout<<"A is pressed"<<endl;
                if ((x_pos >= 20)&&(x_velocity > -18) )
                {
                  y_velocity = 0;
                  x_velocity -= 2;
                }
                else if (x_pos < 20){
                x_velocity=0;
                y_velocity=0;
                }
                else{
                x_velocity=-18;
                y_velocity=0;
                }
                update();
                break;
//          When LEFT arrow is pressed
            case SDL_SCANCODE_LEFT:
              cout<<"A is pressed"<<endl;
              if ((x_pos >= 20)&&(x_velocity > -18) )
              {
                y_velocity = 0;
                x_velocity -= 2;
              }
              else if (x_pos < 20){
              x_velocity=0;
              y_velocity=0;
              }
              else{
              x_velocity=-18;
              y_velocity=0;
              }
              update();
              break;
      }
}

SDL_Surface* Ball::getsurface(){
    return Ballimage;
}
