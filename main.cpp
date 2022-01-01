#include "Game.hpp"
#include <SDL2/SDL_ttf.h>
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
} ButtonPressed;


int main()
{
    Game *bounce=new Game();
    MainMenu* newmain=new MainMenu();
    EndScreen* ends=new EndScreen();
    
    if(SDL_Init(SDL_INIT_VIDEO) || SDL_Init(SDL_INIT_TIMER)){
        cerr<<SDL_GetError()<<endl;
    }
    else{
        int run=MAINMENU ;
        while(run==MAINMENU || run==PLAY){
            
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
                Uint32 FB; //framebegin
                int FT; //frametime
                
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
                bounce->clean();
            }

            if(run==GAMEOVER){
                ends->init();
                ends->render();
                while (run==GAMEOVER) {
                    run=ends->EventHandler();
                }
                
                ends->clean();
                
            }
        }
        if(run==EXIT){
            newmain->~MainMenu();
            ends->~EndScreen();
        }
    }
//  // Home screen test code
//    SDL_Window* window=nullptr;
//    if(SDL_Init(SDL_INIT_VIDEO) < 0){
//        std::cout << "SDL could not be initialized: " <<
//                  SDL_GetError();
//    }
//
//    window = SDL_CreateWindow("BounceUP",20, 20,1280,720,SDL_WINDOW_SHOWN);
//
//    SDL_Renderer* renderer = nullptr;
//    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
//
//    // Just like when we initialize our graphics subsystem,
//    // we need to do the same for our font system.
//    if(TTF_Init() == -1){
//        std::cout << "Could not initailize SDL2_ttf, error: " << TTF_GetError() << std::endl;
//    }else{
//        std::cout << "SDL2_ttf system ready to go!" << std::endl;
//    }
//
//
//    TTF_Font* ourFont = TTF_OpenFont("8bitOperatorPlus8-Regular.ttf",32);
//
//     
//     // Making textures of all the three buttons.
//    SDL_Surface* surface_New_game = TTF_RenderText_Solid(ourFont,"New Game",{255,255,255});
//    SDL_Texture* texture_New_game = SDL_CreateTextureFromSurface(renderer,surface_New_game);
//
//    SDL_Surface* surface_Leader_board = TTF_RenderText_Solid(ourFont,"Leader Board",{255,255,255});
//    SDL_Texture* texture_Leader_board = SDL_CreateTextureFromSurface(renderer,surface_Leader_board);
//
//    SDL_Surface* surface_Exit_game = TTF_RenderText_Solid(ourFont,"Exit Game",{255,255,255});
//    SDL_Texture* texture_Exit_game = SDL_CreateTextureFromSurface(renderer,surface_Exit_game);
//
//    // Create a rectangle to draw on
//    SDL_Rect rect1,rect2,rect3;
//    rect1 = {470,10,400,180};
//    rect2 = {470,250,400,180};
//    rect3 = {470,490,400,180};
//
//    // Infinite loop for our application
//    bool gameIsRunning = true;
//    // Main application loop
//    while(gameIsRunning){
//        SDL_Event event;
//        while(SDL_PollEvent(&event)){
//            // Handle each specific event
//            if(event.type == SDL_QUIT){
//                gameIsRunning= false;
//            }
//
//        }
//     
//        SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
//        SDL_RenderClear(renderer);
//
//        // Render our text on a rectangle
//        SDL_RenderCopy(renderer,texture_New_game,NULL,&rect1);
//        SDL_RenderCopy(renderer,texture_Leader_board,NULL,&rect2);
//        SDL_RenderCopy(renderer,texture_Exit_game,NULL,&rect3);
//
//        // Finally show what we've drawn
//        SDL_RenderPresent(renderer);
//    }
//
//    // Destroy stuff
//    SDL_DestroyTexture(texture_New_game);
//    SDL_DestroyWindow(window);
//    TTF_CloseFont(ourFont);
//    SDL_Quit();
    return 0;
}
