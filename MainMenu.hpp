#ifndef MainMenu_hpp
#define MainMenu_hpp

#include "Window.hpp"
#include "Button.hpp"
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
    SDL_Event ev;
};
#endif /* MainMenu_hpp */
