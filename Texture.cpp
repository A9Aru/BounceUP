#include "Texture.hpp"
#include <iostream>
#include <SDL2/SDL_ttf.h>

//function to load image and return texture
SDL_Texture* Texture::LoadTexture(const char* filename, SDL_Renderer* ren) {
    SDL_Surface* temp = IMG_Load(filename);
    if (temp) std::cout << "Image Loaded" << std::endl;
    SDL_Texture* text = SDL_CreateTextureFromSurface(ren, temp);
    SDL_FreeSurface(temp);
    return text;
}
//function to load a text box
SDL_Texture* Texture::LoadTextBox(const char* string, SDL_Renderer* ren) {
    TTF_Font* ourFont = TTF_OpenFont("ComicSans.ttf", 16);
    SDL_Surface* surface_New_game = TTF_RenderText_Solid(ourFont, string, { 255,255,255 });
    SDL_Texture* texture_New_game = SDL_CreateTextureFromSurface(ren, surface_New_game);
    return texture_New_game;
}
//function to draw texture
void Texture::draw_text(SDL_Texture* t, SDL_Rect* src, SDL_Rect* dest)
{
    SDL_RenderCopy(Game::renderer, t, src, dest);
}