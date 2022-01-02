#ifndef EndScreen_hpp
#define EndScreen_hpp

#include <iostream>
#include "Window.hpp"
#include "Button.hpp"
#include <string>


class EndScreen: public Window{
public:
    void init();
    int EventHandler();
    void render();
    void clean();
    bool isClosed();
    ~EndScreen();
    SDL_Event ev;
    SDL_Rect temp;
    std::string m_text;
private:
    Button* menu;
    Button* restart;
    Button* exitwin;
    Button* textbox; // To store the coordinates of the textbox.
};

#endif /* EndScreen_hpp */
