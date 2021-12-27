#include "Window.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

Window::Window(const string &st, int h, int w)
{
    this->name = st;
    this->height = h;
    this->width = w;
    this->closed = !init();
}

void Window::close()
{
    closed = true;
    cout << "Closing Window" << endl;
}

bool Window::init()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cerr << SDL_GetError() << endl;
        return false;
    }

    win = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    if (win == nullptr)
    {
        cerr << SDL_GetError() << endl;
        return false;
    }

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr)
    {
        cerr << SDL_GetError() << endl;
        return false;
    }

    return true;
}

void Window::closewindow(){
        closed = true;
        cout << "Closing Window" << endl;
}

<<<<<<< Updated upstream
void Window::pollEvents(SDL_Event &event,Ball &b)
=======
void Window::pollEvents(SDL_Event &event,Ball b,Rock r)
>>>>>>> Stashed changes
{
    switch (event.key.keysym.sym)
    {
        //          When W is pressed i.e UP arrow
        case SDLK_w:
            cout<<"W is pressed"<<endl;
            b.set_y(b.get_y()+10);
            break;
        //          When UP arrow is pressed
        case SDLK_UP:
            cout << "Up is pressed"<<endl;
            b.set_y(b.get_y()-10);
            cout<< b.get_y()<<endl;
            break;
        //          When S is pressed i.e DOWN arrow
        case SDLK_s:
            cout<<"S is pressed"<<endl;
            cout<< b.get_y()<<endl;
//            if(b.get_y()>0){
            break;
        //          When DOWN arrow is pressed
        case SDLK_DOWN:
            b.set_y(b.get_y()+10);
            cout<< b.get_y()<<endl;
            cout<< b.get_y()<<endl;
            cout<<"S is pressed"<<endl;

            break;
        //          When D is pressed i.e RIGHT arrow
        case SDLK_d:
            cout<<"D is pressed\n";
//            Ballsprite.x+=framewidth;
//            if(Ballsprite.x>texturewidth){
//                Ballsprite.x=0;
//            }
            cout<<b.getdeg()<<endl;
            b.setdeg(b.getdeg()+30);
            cout<<b.getdeg()<<endl;
            break;
        //          When RIGHT arrow
        case SDLK_RIGHT:
            cout<<"-> is pressed\n";
//            Ballsprite.x+=framewidth;
//            if(Ballsprite.x>texturewidth){
//                Ballsprite.x=0;
//            }
//            cout<<Ballsprite.x<<endl;
            cout<<b.getdeg()<<endl;
            b.setdeg(b.getdeg()+30);
            cout<<b.getdeg()<<endl;
            break;
        //              When A is pressed i.e LEFT arrow
        case SDLK_a:
            cout<<"A is pressed\n";
//            Ballsprite.x-=framewidth;
//            if(Ballsprite.x<0){
//                Ballsprite.x=texturewidth;
//            }
            cout<<b.getdeg()<<endl;
            b.setdeg(b.getdeg()-30);
            cout<<b.getdeg()<<endl;
            break;
        //          When LEFT arrow is pressed
        case SDLK_LEFT:
            cout<<"<- is pressed\n";
            
//            Ballsprite.x-=framewidth;
//            if(Ballsprite.x<0){
//                Ballsprite.x=texturewidth;
//            }
            cout<<b.getdeg()<<endl;
            b.setdeg(b.getdeg()-30);
            cout<<b.getdeg()<<endl;
            break;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255,255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, r.gettext(), NULL, r.getrect());
    SDL_RenderCopyEx(renderer, b.gettext(), NULL, b.getrect(), b.getdeg(), NULL, b.getflip());
//    SDL_RenderCopy(renderer, text,&Ballsprite, b.getrect());
    SDL_RenderPresent(renderer);
}

void Window::render()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Window::get_renderer()
{
    return renderer;
}

bool Window :: isClosed()
{
    return closed;
}

void Window::render(Ball b,Rock r){
//    SDL_QueryTexture(text, NULL, NULL, &texturewidth, &textureheight);
//    cout<<texturewidth<<" width "<<textureheight<<" height\n";
//
//    framewidth=texturewidth/12;
//    frameheight=textureheight;
//    cout<<framewidth<<" width "<<frameheight<<" height\n";
//
//    Ballsprite.x=Ballsprite.y=0;
//    Ballsprite.w=framewidth;
//    Ballsprite.h=frameheight;
//
//    SDL_RenderCopy(renderer, text,&Ballsprite, b.getrect());
    SDL_SetRenderDrawColor(renderer, 255, 255,255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, r.gettext(), NULL, r.getrect());
    SDL_RenderCopy(renderer, b.gettext(), NULL, b.getrect());
    SDL_RenderPresent(renderer);
}

Window::~Window(){
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(text);
    win=nullptr;
    renderer=nullptr;
    text=nullptr;
}
