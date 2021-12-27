#include "Game.hpp"

using namespace std;
const int FPS=60;
const int FD=1000/FPS;//framedelay
int main()
{
    Game *bounce=new Game();
    bounce->init("BounceUP");
    
    Uint32 FB; //framebegin
    int FT; //frametime
    
    while(!bounce->isClosed()){
        FB=SDL_GetTicks();
        
        bounce->eventhandler();
        bounce->update();
        bounce->render();
        
        FT=SDL_GetTicks()-FB;
        if(FD>FT){
            SDL_Delay(FD-FT);
        }
    }
    bounce->clean();
    
    return 0;
}
