#include "MainMenu.hpp"
#include "Texture.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
SDL_Texture *lb;
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
                // Rendering the screen and setting the state back to menu if the back button is triggered.
                bg=Texture::LoadTexture("images/Menu.JPEG",ren);
                lb=Texture::LoadTexture("images/leader_board.jpg",ren);
                play=new Button(855,190,345,165);
                leaderboard=new Button(80,650,50,50);
                exitwin=new Button(855,392,345,165);
                 back = new Button(1101,575,141,100);
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
     std::cout<<x<<" X "<<y<<"Y\n";
    if((buttons && SDL_BUTTON_LMASK)!=0){
            if( (x > play->box.x) && (x<(play->box.x + play->box.w)) && (y > play->box.y ) && (y < (play->box.y + play->box.h))){
                return PLAY;
            }
            else if ((x > exitwin->box.x) && (x<(exitwin->box.x + exitwin->box.w)) && (y > exitwin->box.y ) && (y < (exitwin->box.y + exitwin->box.h))){
                return EXIT;
            }
            else if((x > leaderboard->box.x-leaderboard->box.w) && (x<(leaderboard->box.x + leaderboard->box.w)) && (y > leaderboard->box.y - leaderboard->box.h) && (y < (leaderboard->box.y + leaderboard->box.h))){
                return LEADERBOARD; 
            }
            else if((x > back->box.x-back->box.w) && (x<(back->box.x + back->box.w)) && (y > back->box.y - back->box.h) && (y < (back->box.y + back->box.h))){
                    SDL_RenderClear(ren);
                    SDL_RenderCopy(ren,bg, NULL,NULL);
                    SDL_RenderPresent(ren);
                    return 0;
            }
    }
    if(closed) {
        return EXIT;}
    return RUN;
}

void MainMenu::render(){
    int state = EventHandler();
    if(state == 0){
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren,bg, NULL,NULL);
    SDL_RenderPresent(ren);  }
    if(state == 3){
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren,lb, NULL,NULL);
    SDL_RenderPresent(ren);   }

}
void MainMenu::clean(){
    SDL_DestroyWindow(win);
    SDL_DestroyTexture(bg);
    SDL_DestroyRenderer(ren);
}
bool MainMenu::isClosed(){
    return closed;
}
