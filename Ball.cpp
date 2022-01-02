#include<SDL2/SDL.h>
#include<iostream>
#include<SDL2/SDL_image.h>
#include "Ball.hpp"
#include "Rock.hpp"
#include "Texture.hpp"
#include "Game.hpp"

using namespace std;

Ball::Ball(const char* file, int x, int y, int r)
{
    x_pos = x;
    y_pos = y;
    radius = r;
    degrees = new double;
    (*degrees) = 0;
    y_velocity = 0;
    srec = { 0,0,NULL,NULL };
    drec = { x,y,radius,radius };
    balltext = Texture::LoadTexture(file, Game::renderer);
    rotate = false;
}

void Ball::Update(bool d, bool u) {
    keyboardinput(d, u);
    drec.x = x_pos;
    drec.y = y_pos;
    drec.h = radius;
    drec.w = radius;
}

void Ball::Render() {
    if (rotate == true) SDL_RenderCopyEx(Game::renderer, balltext, NULL, &drec, *degrees, NULL, SDL_FLIP_NONE);
    else SDL_RenderCopy(Game::renderer, balltext, NULL, &drec);
}

void Ball::setdeg(double deg) {
    (*degrees) += deg;
    if (*degrees >= 360) (*degrees) -= 360;
    else if (*degrees <= -360) *degrees += 360;
}

void Ball::keyboardinput(bool d, bool u) {
    const Uint8* currkey = SDL_GetKeyboardState(NULL);

//    if ((currkey[SDL_SCANCODE_W] || currkey[SDL_SCANCODE_UP]) && (currkey[SDL_SCANCODE_A] || currkey[SDL_SCANCODE_LEFT])) {
//        cout << "W and A is pressed" << endl;
//        this->setdeg(-5);
//        rotate = true;
//        if (u == true)
//        {
//            y_pos = y_pos - 5;
//        }
//        cout << "Rotate Left by" << *degrees << "\n";
//    }
//    else if ((currkey[SDL_SCANCODE_S] || currkey[SDL_SCANCODE_DOWN]) && (currkey[SDL_SCANCODE_LEFT] || currkey[SDL_SCANCODE_A])) {
//        cout << "S and A is pressed" << endl;
//        this->setdeg(-5);
//        rotate = true;
//        if (d == true)
//        {
//
//            y_pos = y_pos + 5;
//        }
//        cout << "Rotate Left by" << *degrees << "\n";
//    }
//    else if ((currkey[SDL_SCANCODE_W] || currkey[SDL_SCANCODE_UP]) && (currkey[SDL_SCANCODE_D] || currkey[SDL_SCANCODE_RIGHT])) {
//        cout << "W and D is pressed" << endl;
//        this->setdeg(5);
//        rotate = true;
//        if (u == true)
//        {
//
//            y_pos = y_pos - 5;
//        }
//        cout << "Rotate Right by" << *degrees << "\n";
//    }
//    else if ((currkey[SDL_SCANCODE_S] || currkey[SDL_SCANCODE_DOWN]) && (currkey[SDL_SCANCODE_D] || currkey[SDL_SCANCODE_RIGHT])) {
//        cout << "S and D is pressed" << endl;
//        this->setdeg(5);
//        rotate = true;
//        if (d == true)
//        {
//            y_pos = y_pos + 5;
//        }
//        cout << "Rotate Right by" << *degrees << "\n";
//    }
    //  When W is pressed i.e UP arrow
    if (currkey[SDL_SCANCODE_W] || currkey[SDL_SCANCODE_UP]) {
        cout << "W is pressed" << endl;
        if (u == true)
        {
            y_pos = y_pos - 5;
        }
    }
    //          When S is pressed i.e DOWN arrow
    if (currkey[SDL_SCANCODE_S] || currkey[SDL_SCANCODE_DOWN]) {
        cout << "S is pressed" << endl;
        if (d == true)
        {
            y_pos = y_pos + 5;
        }
    }
    //          When D is pressed i.e RIGHT arrow
    if (currkey[SDL_SCANCODE_D] || currkey[SDL_SCANCODE_RIGHT]) {
        x_velocity++;
        cout << "D is pressed\n";
        this->setdeg(5);
        rotate = true;
        cout << "Rotate Right by " << *degrees << "\n";
    }
    //              When A is pressed i.e LEFT arrow
    if (currkey[SDL_SCANCODE_A] || currkey[SDL_SCANCODE_LEFT]) {
        x_velocity--;
        cout << "A is pressed\n";
        this->setdeg(-5);
        rotate = true;
        cout << "Rotate Left by " << *degrees << "\n";
    }
}

SDL_Rect* Ball::getdrec()
{
    return &drec;
}
