#include "Texture.hpp"
#include <iostream>
#include <SDL2/SDL_ttf.h>


SDL_Texture* Texture::LoadTexture(const char* filename, SDL_Renderer* ren){
    SDL_Surface *temp=IMG_Load(filename);
    if(temp) std::cout<<"Image Loaded"<<std::endl;
    SDL_Texture *text=SDL_CreateTextureFromSurface(ren, temp);
    SDL_FreeSurface(temp);
    return text;
} 

void ::Texture::draw_text(SDL_Texture* t, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, t, &src, &dest);
}
