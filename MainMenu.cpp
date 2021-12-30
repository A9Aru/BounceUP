#include "MainMenu.hpp"
#include "Texture.hpp"

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
                bg=Texture::LoadTexture("main_menu.jpg",ren);
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
    std::cout<<ev.button.x<<" X "<<ev.button.y<<"Y\n";
    if(ev.type == SDL_MOUSEBUTTONDOWN){
            if( (ev.button.x > play->box.x) && (ev.button.x<(play->box.x + play->box.w)) && (ev.button.y > play->box.y ) && (ev.button.y < (play->box.y + play->box.h))){
                return 1;
            }
            else if ((ev.button.x > exitwin->box.x) && (ev.button.x<(exitwin->box.x + exitwin->box.w)) && (ev.button.y > exitwin->box.y ) && (ev.button.y < (exitwin->box.y + exitwin->box.h))){
                return 2;
            }
            else if((ev.button.x > leaderboard->box.x-leaderboard->box.w) && (ev.button.x<(leaderboard->box.x + leaderboard->box.w)) && (ev.button.y > leaderboard->box.y - leaderboard->box.h) && (ev.button.y < (leaderboard->box.y + leaderboard->box.h))){
                return 3;
            }
    }
    if(closed) return 2;
    return 0;
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
