#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL_image.h>
#include "Texture.hpp"

//To run the main game. Has functions to render the whole game and update the objects present in the game based on user input.

class Game {
public:
    Game();
    ~Game();
    void init(const char* title);

    void eventhandler();
    int update();
    void render();
    void clean();
    int get_score();
    bool isClosed();
    void SetClosed(bool set);
    //void endGame();

    static SDL_Event event;
    static SDL_Renderer* renderer;
private:
    bool closed;
    SDL_Window* win = nullptr;

};
#endif /* Game_hpp */