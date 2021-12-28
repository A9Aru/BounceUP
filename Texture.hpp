#ifndef Texture_hpp
#define Texture_hpp
#include "Game.hpp"

#include <stdio.h>
#include <SDL2/SDL_image.h>

class Texture{
public:
    static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
    static void draw_text(SDL_Texture* text, SDL_Rect src, SDL_Rect dest);
};
#endif /* Texture_hpp */
