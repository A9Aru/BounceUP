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
<<<<<<< Updated upstream
    Ball Ball(640, 50);
    Window application("BounceUP", width, height);
  //  Rock Rock(400,400);
   // Rock.rockRenderer(application.get_renderer());
    Ball.loadimage();
    application.render();
    application.Ballrenderer(Ball);
=======
    Window application("BounceUP", width, height);
    application.render();
    Rock Rock(400,400);
    Ball Ball(640, 50);
    Rock.loadimage(application.get_renderer());
    Ball.loadimage(application.get_renderer());
    application.render(Ball,Rock);
>>>>>>> Stashed changes
    while (!application.isClosed())
    {
        SDL_Event ev;
        while(SDL_PollEvent(&ev)!=0)
        {
            if(ev.type==SDL_QUIT){
                application.closewindow();
            }
            else if (ev.type==SDL_KEYDOWN){
<<<<<<< Updated upstream
               application.pollEvents(ev,Ball);
            }          
        }  
        SDL_Delay(1000/120); 
    }  
=======
                application.pollEvents(ev, Ball,Rock);
            }
        }
        SDL_Delay(1000/120);
    }
>>>>>>> Stashed changes
    
   SDL_Quit(); 
    return 0;
}
