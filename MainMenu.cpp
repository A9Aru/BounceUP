#include "MainMenu.hpp"
#include "Texture.hpp"

typedef enum  {
    RUN,
    PLAY,
    EXIT,
    LEADERBOARD,
} ButtonPressed;

MainMenu::~MainMenu(){
    play=NULL;
    exitwin=NULL;
    leaderboard=NULL;
    SDL_Quit();
}

void MainMenu::init()
{
    if(SDL_Init(SDL_INIT_VIDEO)== 0){
        win = SDL_CreateWindow("Main Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, 0);
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
                bg=Texture::LoadTexture("images/main_menu.jpg",ren);
                play=new Button(855,190,345,165);
                leaderboard=new Button(80,650,50,50);
                exitwin=new Button(855,392,345,165);
                std:: cout << "Window Created\n";
            }
        }
    }
    else
    {
        std::cerr << SDL_GetError() << std::endl;
    }

}

int MainMenu::EventHandler(){
    SDL_PollEvent(&ev);
    switch (ev.type) {
        case SDL_QUIT:
            closed = true;
            break;
    }
    SDL_PumpEvents();
    int x,y;
    Uint32 buttons;
    buttons=SDL_GetMouseState(&x, &y);
//    std::cout<<x<<" X "<<x<<"Y\n";
    if((buttons && SDL_BUTTON_LMASK)!=0){
            if( (x > play->box.x) && (x<(play->box.x + play->box.w)) && (x > play->box.y ) && (x < (play->box.y + play->box.h))){
                return PLAY;
            }
            else if ((x > exitwin->box.x) && (x<(exitwin->box.x + exitwin->box.w)) && (x > exitwin->box.y ) && (x < (exitwin->box.y + exitwin->box.h))){
                return EXIT;
            }
            else if((x > leaderboard->box.x-leaderboard->box.w) && (x<(leaderboard->box.x + leaderboard->box.w)) && (x > leaderboard->box.y - leaderboard->box.h) && (x < (leaderboard->box.y + leaderboard->box.h))){
                return LEADERBOARD;
            }
    }
    if(closed) return EXIT;
    return RUN;
}

void MainMenu::render(){
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren,bg, NULL,NULL);
    SDL_RenderPresent(ren);
}
void MainMenu::clean(){
    SDL_DestroyWindow(win);
    SDL_DestroyTexture(bg);
    SDL_DestroyRenderer(ren);
}
bool MainMenu::isClosed(){
    return closed;
}
