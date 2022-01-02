#ifndef Score_hpp
#define Score_hpp

#include <iostream>
#include <SDL2/SDL_ttf.h>

class Score{
public:
    Score();
    int score;
    std::string dis;
    void updatescore(int s);
    void render();
    SDL_Rect a1={1050,0,150,100};
    SDL_Rect a2={1200,0,50,100};
    SDL_Surface* sur1=nullptr;
    SDL_Surface* sur2=nullptr;
    SDL_Texture* text1=nullptr;
    SDL_Texture* text2=nullptr;
    TTF_Font* fon=nullptr;
};

#endif /* Score_hpp */
