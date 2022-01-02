#include "EndScreen.hpp"
#include "Texture.hpp"
#include <SDL2/SDL_ttf.h>
#include <string>
#include "Game.hpp"
#include <bits/stdc++.h>
typedef enum  {
    MAINMENU,
    PLAY,
    EXIT,
    LEADERBOARD,
    GAMEOVER
} GAMESTATE;

EndScreen::~EndScreen(){
    menu=NULL;
    exitwin=NULL;
    SDL_Quit();
}
int w,h;
SDL_Texture *tb;
TTF_Font* font;
const char * c;

void EndScreen::init()
{
    m_text = "";
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
                font = TTF_OpenFont("ComicSans.ttf",36);
                c = m_text.c_str();
                TTF_SizeText(font,c,&w,&h);  // returns the size of drec
                menu=new Button(288,565,155,100);
                restart=new Button(447,565,385,100);
                exitwin=new Button(835,565,155,100);
                textbox = new Button(288,430,704,85); // Should set the width and height of the UI Textbox.
                temp = {474,720,w,h}; // drec
                bg =Texture::LoadTexture("images/gameover.png", ren);
                tb =Texture::LoadTextBox(c,ren);
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
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    buttons=SDL_GetMouseState(&x, &y);
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
                std::cout<<"EXIT\n";
                return EXIT;
            }
            else if(((x > menu->box.x) && (x<(menu->box.x + menu->box.w)) && (y > menu->box.y ) && (y < (menu->box.y + menu->box.h)))){
                std::cout<<"MENU\n";
                return MAINMENU;
            }
    }
    
    if(((x > textbox->box.x) && (x<(textbox->box.x + textbox->box.w)) && (y > textbox->box.y ) && (y < (textbox->box.y + textbox->box.h)))){
        if(keystate[SDL_SCANCODE_BACKSPACE] && m_text.size() > 0){
            m_text.pop_back();
        }
        else if(ev.type==SDL_TEXTINPUT){
            m_text+=ev.text.text;
            std::cout<<m_text<<std::endl;
        }
        else if(keystate[SDL_SCANCODE_KP_ENTER] ||  keystate[SDL_SCANCODE_RETURN]) // for the enter part
        {
            update_leaderboard(m_text); // name ,score
            return MAINMENU;
        }
        return GAMEOVER;
    }
    std::cout.flush();
    
    if(closed) {
        return EXIT;
    }
    return GAMEOVER;
}
void EndScreen::render(){
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren,bg, NULL,NULL);
    c = m_text.c_str();
    TTF_SizeText(font,c,&w,&h);
    temp = {textbox->box.x,textbox->box.y,w,h};
    tb =Texture::LoadTextBox(c,ren); // loading the texture for the updated text.
    SDL_RenderCopy(ren,tb,NULL,&temp); // rendering the name.(m_text)
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

bool comparator(std::pair<int,std::string> p1,std::pair<int,std::string> p2){
    return p2.first<p1.first;
}

void EndScreen::update_leaderboard(std::string name){
    std::vector<std::pair<int,std::string>> scoreboard;  // names and scores.
    std::fstream file;
    std::string word;
    int points;
    // Reading the text file
    file.open ("leader_board.txt");
    std::pair<int,std::string> temp;
    for(int i =0;i<5;i++){
        file>> word;
        temp.second = word;
        file>>points;
        temp.first = points;
        scoreboard.push_back(temp);
    }
    temp.first = score;
    temp.second = name;
    scoreboard.push_back(temp);
    std::sort(scoreboard.begin(),scoreboard.end(),comparator);
    file.close();
    // Empying the text file.
    std::ofstream ofs;
    ofs.open("leader_board.txt", std::ofstream::out | std::ofstream::trunc);
    for(std::pair<int,std::string> p: scoreboard){
        ofs<<p.second<<" "<<p.first<<"\n";
    }
}

