#ifndef Window_hpp
#define Window_hpp

#include <iostream>
#include <SDL.h>
#include <SDL2/SDL_image.h>

//Window where the game is displayed. 

class Window{
public:
    const int H=720,W=1280;
    virtual void init()=0;
    virtual int EventHandler()=0;
    virtual void render()=0;
    virtual void clean()=0;
    virtual bool isClosed()=0;
    bool closed;
    SDL_Window* win=nullptr;
    SDL_Texture* bg=nullptr;
    SDL_Renderer* ren=nullptr;
};

#endif /* Window_hpp */
