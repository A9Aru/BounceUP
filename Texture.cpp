#include "Texture.hpp"
#include <iostream>
SDL_Texture* Texture::LoadTexture(const char* filename, SDL_Renderer* ren){
    SDL_Surface *temp=IMG_Load(filename);
    if(temp) std::cout<<"Image Loaded"<<std::endl;
    SDL_Texture *text=SDL_CreateTextureFromSurface(ren, temp);
    SDL_FreeSurface(temp);
    return text;
}
