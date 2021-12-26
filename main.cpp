#include<SDL2/SDL.h>
#include<iostream>
#include<SDL2/SDL_image.h>

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
    Window application("Bouncing Ball", width, height);
    Ball Ball(100, 100, 20);
    SDL_Surface *Ballimage= IMG_Load("/Users/chinthanchandra/Documents/GitHub/Bounce/BounceUP/images/1.png");
    Ball.loadimage(Ballimage);
    application.render();
    application.Ballrenderer(Ball);
    
    while (!application.isClosed())
    {
        SDL_Event ev;
        if (SDL_PollEvent(&ev))
        {
            if (ev.type == SDL_QUIT)
                application.pollEvents(ev);
            else if (ev.type == SDL_KEYDOWN){
                Ball.poll_events(ev);
            }
        }
//        Ball.render(application.get_renderer(), Ball.get_x(), Ball.get_y(), 20, 0x00, 0xFF, 0xFF, 0xFF);

    }

    return 0;
}
