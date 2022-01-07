#ifndef Texture_hpp
#define Texture_hpp
#include "Game.hpp"

#include <stdio.h>
#include <SDL2/SDL_image.h>

//Functions to load textures 

class Texture{
public:
    static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
    static void draw_text(SDL_Texture* text, SDL_Rect* src, SDL_Rect* dest);
    static SDL_Texture *LoadTextBox(const char* string, SDL_Renderer* ren); // for rendering a text box

};
#endif /* Texture_hpp */
