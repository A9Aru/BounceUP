#ifndef EndScreen_hpp
#define EndScreen_hpp

#include <iostream>
#include "Window.hpp"
#include "Button.hpp"
#include <string>
#include "Game.hpp"

//Derived class of window for final window display. Acts appropriately based on user input

class EndScreen : public Window {
public:
    void init();
    int EventHandler();
    void render();
    void clean();
    bool isClosed();
    void update_leaderboard(std::string name); // name ,score
    ~EndScreen();
    SDL_Event ev;
    SDL_Rect temp;
    std::string m_text;
    int score;
    Button* menu;
private:
    Button* restart;
    Button* exitwin;
    Button* textbox; // To store the coordinates of the textbox.
};

#endif /* EndScreen_hpp */