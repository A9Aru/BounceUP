#include "EndScreen.hpp"
#include "Texture.hpp"

typedef enum  {
    MAINMENU,
    PLAY,
    EXIT,
    LEADERBOARD,
    GAMEOVER
} ButtonPressed;

EndScreen::~EndScreen(){
    menu=NULL;
    exitwin=NULL;
    SDL_Quit();
}

void EndScreen::init()
{
    
    if(SDL_Init(SDL_INIT_VIDEO)== 0){
        win = SDL_CreateWindow("Game Over", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, 0);
        if (win == nullptr)
        {
            std::cerr << SDL_GetError() << std::endl;
            
        }
        else
        {
            ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (ren == nullptr)
            {
                std::cerr << SDL_GetError() << std::endl;
                
            }
            else
            {
                menu=new Button(285,505,155,105);
                restart=new Button(445,505,385,105);
                exitwin=new Button(835,505,135,105);
                bg=Texture::LoadTexture("images/gameover.png", ren);
                closed=false;
                std:: cout << "Window Created\n";
            }
        }
    }
    else
    {
        std::cerr << SDL_GetError() << std::endl;
    }
}

int EndScreen::EventHandler(){
    SDL_PollEvent(&ev);
    SDL_PumpEvents();
    int x,y;
    Uint32 buttons;
    buttons=SDL_GetMouseState(&x, &y);
    std::cout<<x<<" X "<<y<<"Y\n";
    switch (ev.type) {
        case SDL_QUIT:
            closed=true;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if((x>restart->box.x) && (x<restart->box.x+restart->box.w) && (y>restart->box.y) && (y<restart->box.y+restart->box.h) ){
                std::cout<<"RESTART\n";
                return PLAY;
            }
            else if ((x > exitwin->box.x) && (x<(exitwin->box.x + exitwin->box.w)) && (y > exitwin->box.y ) && (y < (exitwin->box.y + exitwin->box.h))){
                std::cout<<"exit\n";
                return EXIT;
            }
            else if(((x > menu->box.x) && (x<(menu->box.x + menu->box.w)) && (y > menu->box.y ) && (y < (menu->box.y + menu->box.h)))){
                std::cout<<"MEN\n";
                return MAINMENU;
            }
        }
    if(closed) {
        return EXIT;}
    return GAMEOVER;
}
void EndScreen::render(){
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren,bg, NULL,NULL);
    SDL_RenderPresent(ren);
}

void EndScreen::clean(){
    SDL_DestroyWindow(win);
    SDL_DestroyTexture(bg);
    SDL_DestroyRenderer(ren);
}
bool EndScreen::isClosed(){
    return closed;
}
