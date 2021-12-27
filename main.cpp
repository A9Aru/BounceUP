#include<SDL2/SDL.h>
#include<iostream>
#include<SDL2/SDL_image.h>
#include "Rock.hpp"
#include "Ball.hpp"
#include "Window.hpp"
#undef main

static const int height = 1280;
static const int width = 720;
using namespace std;

/*void poll_all_events(Window app, Ball bounce)
{
    SDL_Event event;
    if (SDL_PollEvent (&event))
    {
        app.pollEvents(event);
        bounce.poll_events(event);
    }
}*/

int main()
{
     SDL_Window* win = SDL_CreateWindow("GAME",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       1000, 1000, 0);
    Ball Ball(640, 50);
    Window application("BounceUP", width, height);
    Rock Rock(400,400);
    Rock.rockRenderer(application.get_renderer());
    Ball Ball(640, 50);
    Ball.loadimage();
    application.render();
    application.Ballrenderer(Ball);
    while (!application.isClosed())
    {
        SDL_Event ev;
        while(SDL_PollEvent(&ev)!=0)
        {
            if(ev.type==SDL_QUIT){
                application.closewindow();
            }
            else if (ev.type==SDL_KEYDOWN){
               // application.pollEvents(ev, Ball);
            }          
        }  
        SDL_Delay(1000/120); 
    }  
    
   SDL_Quit(); 
    return 0;
}
