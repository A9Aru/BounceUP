//#include "Coin.hpp"
//#include "Window.hpp"
//#include <iostream>
//
//#include <cmath>
//
////Create the coin object
//Coin::Coin()
//{
//};
//Coin::~Coin() {
//}
//
////Deal with collision between coin and player
//void Coin::handleCollision() {
//    //increment score and then destroy the coin
//    this->~Coin();
//}
//
//void Coin::draw(SDL_Renderer *renderer, Window* window) {
//    SDL_Event input;
//    bool quit = false;
//    SDL_Texture* spriteSheet = NULL;
//    SDL_Surface* temp = IMG_Load("spritesheet.png");
//    spriteSheet = SDL_CreateTextureFromSurface(renderer, temp);
//    SDL_FreeSurface(temp);
//    SDL_Rect windowRect;
//    for(int i = 0; i < 4; i++)
//    windowRect.x = 0;
//    windowRect.y = rand()%360;
//    windowRect.w = 100;
//    windowRect.h = 100;
//    SDL_Rect textureRect;
//    textureRect.x = 2;
//    textureRect.y = 2;
//    SDL_QueryTexture(spriteSheet, NULL, NULL, &textureRect.w, &textureRect.h);
//    textureRect.w /= 4;
//
//    while (!quit)
//    {
//        while (SDL_PollEvent(&input) > 0)
//        {
//            if (input.type == SDL_QUIT) quit = true;
//        }
//        int totalFrames = 4;
//        int delayPerFrame = 200;
//        int frame = (SDL_GetTicks() / delayPerFrame) % totalFrames;
//        textureRect.x = frame * textureRect.w;
//
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//        SDL_RenderClear(renderer);
//        SDL_RenderCopy(renderer, spriteSheet, &textureRect, &windowRect);
//
//        SDL_RenderPresent(renderer);
//    }
//    SDL_DestroyTexture(spriteSheet);
//    SDL_DestroyRenderer(renderer);
//    IMG_Quit();
//    SDL_Quit();
//}
