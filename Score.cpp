#include "Score.hpp"
#include "Game.hpp"
Score::Score(){
    if(TTF_Init()!=0){
        std::cout<<SDL_GetError()<<std::endl;
    }
    else{
        fon=TTF_OpenFont("ComicSans.ttf", 26);
        score=0;
    }
}

void Score::updatescore(int s){
    score+=s;
    dis=std::to_string(score);
    sur1=TTF_RenderText_Solid(fon, "Score: " , {255,255,255});
    const char* t=(char*) dis.c_str();
    sur2=TTF_RenderText_Solid(fon,t ,{255,255,255});
}

void Score::render(){
    text1=SDL_CreateTextureFromSurface(Game::renderer, sur1);
    SDL_RenderCopy(Game::renderer, text1, NULL, &a1);
    text2=SDL_CreateTextureFromSurface(Game::renderer, sur2);
    SDL_RenderCopy(Game::renderer, text2, NULL, &a2);
}
