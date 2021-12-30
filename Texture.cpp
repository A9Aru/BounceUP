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
SDL_Texture* Texture::LoadTextBox(const char* text, SDL_Renderer* ren){
      TTF_Font* ourFont = TTF_OpenFont("8bitOperatorPlus8-Regular.ttf",32);
      SDL_Surface* surfaceText = TTF_RenderText_Solid(ourFont,text,{255,255,255});
      SDL_Texture* textureText = SDL_CreateTextureFromSurface(ren,surfaceText);
     return textureText;
}
void ::Texture::draw_text(SDL_Texture* t, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, t, &src, &dest);
}
