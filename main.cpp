#include "Game.hpp"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "MainMenu.hpp"
#include "EndScreen.hpp"
using namespace std;
const int FPS=60;
const int FD=1000/FPS;//framedelay

typedef enum  {
    MAINMENU,
    PLAY,
    EXIT,
    LEADERBOARD,
    GAMEOVER,
} GAMESTATE;


int main()
{
    Uint32 FB; //framebegin
    int FT; //frametime
    Game *bounce=new Game();
    MainMenu* newmain=new MainMenu();
    EndScreen* ends=new EndScreen();
    
    SDL_Init(SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music *bgm = Mix_LoadMUS("sample.mp3");
    Mix_PlayMusic(bgm, -1);
    if(SDL_Init(SDL_INIT_VIDEO) || SDL_Init(SDL_INIT_TIMER)){
        cerr<<SDL_GetError()<<endl;
    }
    
    if(SDL_Init(SDL_INIT_VIDEO) || SDL_Init(SDL_INIT_TIMER)){
        cerr<<SDL_GetError()<<endl;
    }
    else{
        int run=MAINMENU ;
        while(run==MAINMENU || run==PLAY){
            int score=0;
            if(run==MAINMENU){
                newmain->init();
                newmain->render();
                
                while(run==MAINMENU || run == LEADERBOARD){
                    run=newmain->EventHandler();
                    if(run == LEADERBOARD )  newmain->render();
                }
                newmain->clean();
            }
            while(run==PLAY ){
                bounce->init("BounceUP");
//                bounce->SetClosed(false);
                
                
                while(!bounce->isClosed() && run==PLAY){
                    FB=SDL_GetTicks();
                    
                    bounce->eventhandler();
                    run=bounce->update(); //returns 1 i.e PLAY returns 4 for Gameover to render endscreen
                    bounce->render();
                    
                    FT=SDL_GetTicks()-FB;
                    if(FD>FT){
                        SDL_Delay(FD-FT);
                    }
                }
                score=bounce->get_score();
                bounce->clean();
            }

            if(run==GAMEOVER){
                ends->init();
                ends->score=score;
                ends->render();
                int fd=1000/20;
                while (run==GAMEOVER) {
                    FB=SDL_GetTicks();
                    run=ends->EventHandler();
                    ends->render();
                    FT=SDL_GetTicks()-FB;
                    if(FD>FT){
                        SDL_Delay(fd-FT);
                    }
                }
                
                ends->clean();
                
            }
        }
        if(run==EXIT){
            newmain->~MainMenu();
            ends->~EndScreen();
        }
    }
    return 0;
}
