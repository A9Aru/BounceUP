#ifndef Menu_hpp
#define Menu_hpp
#include "Object.hpp"
#include "Texture.hpp"
using namespace std;


class Menu{
    private:
        Texture *Play;  // The Elements in the start screen
        Texture *Leaderboard;  // The Button in the start screen
        Texture *ExitGame;  // The button in the start screen
    //    Texture *livescore; // The Widget that displays live score during gameplay.
    //    Object *gamepause; // The Button that is used to pause the gameplay.
    public:
        Menu();
        void Update();
        void Render();
        

}




#endif