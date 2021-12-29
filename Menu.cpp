#include "Object.hpp"
#include "Texture.hpp"

Menu :: Menu (){
     Texture *Play = LoadTextBox("PLAY");
     Texture *Leaderboard = LoadTextBox("Leaderboard");
     Texture *Exit = LoadTextBox("Exit");
     SDL_Rect rect = {};
     draw_text(Play,NULL,); // should set the coordinates of the buttons.
     draw_text(Leaderboard,NULL,);
     draw_text(Exit,NULL,);

     // Should also implement the live score and the pause/Exit Widget.
}

