#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Texture.hpp"
#include "Button.hpp"

class Game{
public:
    Game();
    ~Game();
    void init(const char* title);
    
    void eventhandler();
    void update();
    void render();
    void clean();
    // game state is the screen we are in.
    // 0 is main menu.
    // 1 is leaderboard.
    // 2 is running gameplay.
    int game_state = 0; // in the main menu by default.
    // Buttons in the main menu.
    Button* play;
    Button* leaderboard; 
    Button* exit; 
    
    bool isClosed();
    
    static SDL_Event event;
    static SDL_Renderer* renderer;
private:
    bool closed;
    SDL_Window* win = nullptr;
    
};
#endif /* Game_hpp */
