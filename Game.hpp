#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Texture.hpp"
class Game{
public:
    Game();
    ~Game();
    void init(const char* title);
    
    void eventhandler();
    void update();
    void render();
    void clean();
    
    bool isClosed();
    
    static SDL_Event event;
    static SDL_Renderer* renderer;
private:
    bool closed;
    SDL_Window* win = nullptr;
    
};
#endif /* Game_hpp */
