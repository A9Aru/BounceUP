#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include <SDL2/SDL_image.h>

class Texture{
public:
    static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
    
};
#endif /* Texture_hpp */
