#ifndef EndScreen_hpp
#define EndScreen_hpp

#include <iostream>
#include "Window.hpp"
#include "Button.hpp"
class EndScreen: public Window{
public:
    void init();
    int EventHandler();
    void render();
    void clean();
    bool isClosed();
    ~EndScreen();
    SDL_Event ev;
private:
    Button* menu;
    Button* restart;
    Button* exitwin;
};

#endif /* EndScreen_hpp */
