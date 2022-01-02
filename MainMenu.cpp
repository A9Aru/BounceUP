#include "MainMenu.hpp"
#include "Texture.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>

using namespace std;

typedef enum  {
    MAINMENU,
    PLAY,
    EXIT,
    LEADERBOARD,
    GAMEOVER
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
        SDL_Surface *icon=IMG_Load("images/icon.png");
        SDL_SetWindowIcon(win,icon);
        SDL_FreeSurface(icon);
        if(TTF_Init() !=0){
            std::cout << "Could not initailize SDL2_ttf, error: " << TTF_GetError() << std::endl;
        }
        else
        {
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
                    closed=false;
                    std:: cout << "Window Created\n";
                }
            }
        }
    }
}
int MainMenu::EventHandler(){
    SDL_PollEvent(&ev);
    SDL_PumpEvents();
    int x,y,d=MAINMENU;
    Uint32 buttons;
    buttons=SDL_GetMouseState(&x, &y);
    std::cout<<x<<" "<<y<<std::endl;
    switch (ev.type) {
        case SDL_QUIT:
            closed = true;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if( (x > play->box.x) && (x<(play->box.x + play->box.w)) && (y > play->box.y ) && (y < (play->box.y + play->box.h))){
                d=PLAY;
                std::cout<<"PLAY\n";
            }
            else if ((x > exitwin->box.x) && (x<(exitwin->box.x + exitwin->box.w)) && (y > exitwin->box.y ) && (y < (exitwin->box.y + exitwin->box.h))){
                d=EXIT;
                std::cout<<"EXIT\n";
            }
            else if((x > leaderboard->box.x-leaderboard->box.w) && (x<(leaderboard->box.x + leaderboard->box.w)) && (y > leaderboard->box.y - leaderboard->box.h) && (y < (leaderboard->box.y + leaderboard->box.h))){
                d=LEADERBOARD;
                std::cout<<"LEADERBOARD\n";
            }
            else if((x > back->box.x-back->box.w) && (x<(back->box.x + back->box.w)) && (y > back->box.y - back->box.h) && (y < (back->box.y + back->box.h))){
                SDL_RenderClear(ren);
                SDL_RenderCopy(ren,bg, NULL,NULL);
                SDL_RenderPresent(ren);
                d=MAINMENU;
                std::cout<<"LEADERBOARD\n";
            }
            break;
    }
    
    if(closed) {
        return EXIT;}
    return d;
}

void MainMenu::render(){
    int state = EventHandler();
    if(state == MAINMENU){
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren,bg, NULL,NULL);
        SDL_RenderPresent(ren);  }
    if(state == LEADERBOARD){
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren,lb, NULL,NULL);
        print_leaderboard();
        SDL_RenderPresent(ren);   }
    
}


void MainMenu::print_leaderboard(){
    vector<pair<Texture*,Texture*>> lines; // pairs of score and names.
    // SDL_Rect locations[10] ={{488,223,220,26},{884,225,130,26},{},{},{},{},{},{},{},{}};
    // Testing for onnly one location now.
    SDL_Rect locations[2] ={{488,223,220,26},{884,225,130,26}};
    SDL_Texture *temp;
    fstream file;
    string word;
    const char * c;
    file.open ("leader_board.txt");
    for(int i=0;i<2;i++){
        file >> word;
        c = word.c_str();
        temp =Texture::LoadTextBox(c,ren); // Loading Name
        SDL_RenderCopy(ren,temp,NULL,&locations[i]);  // rendering the name texture.
    }
    
}
void MainMenu::clean(){
    SDL_DestroyWindow(win);
    SDL_DestroyTexture(bg);
    SDL_DestroyRenderer(ren);
}
bool MainMenu::isClosed(){
    return closed;
}
