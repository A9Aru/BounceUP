#ifndef MainMenu_hpp
#define MainMenu_hpp

#include "Window.hpp"
#include "Button.hpp"

//type of window that appears in the beginning of the game. Has functions has act appropriately with the user input.

class MainMenu: public Window
{
private:
    Button* play;
    Button* exitwin;
    Button* leaderboard;
    Button *back; // go back button in leaderboard.
public:
    ~MainMenu();
    void init();
    int EventHandler();
    bool isClosed();
    void render();
    void clean();
    void print_leaderboard();
    SDL_Event ev;
};
#endif /* MainMenu_hpp */
