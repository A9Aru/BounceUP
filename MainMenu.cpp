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
                bg=Texture::LoadTexture("images/Menu.JPEG",ren);
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
//    std::cout<<x<<" X "<<y<<"Y\n";
    if(ev.type==SDL_MOUSEBUTTONDOWN){
            if( (x > play->box.x) && (x<(play->box.x + play->box.w)) && (y > play->box.y ) && (y < (play->box.y + play->box.h))){
                std::cout<<"Play Pressed\n";
                return PLAY;
            }
            else if ((x > exitwin->box.x) && (x<(exitwin->box.x + exitwin->box.w)) && (y > exitwin->box.y ) && (y< (exitwin->box.y + exitwin->box.h))){
                std::cout<<"Exit Pressed\n";
                return EXIT;
            }
            else if((x > leaderboard->box.x-leaderboard->box.w) && (y<(leaderboard->box.x + leaderboard->box.w)) && (y > leaderboard->box.y - leaderboard->box.h) && (x < (leaderboard->box.y + leaderboard->box.h))){
                std::cout<<"Leaderboard Pressed\n";
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
