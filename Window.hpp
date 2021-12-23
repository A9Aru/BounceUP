#ifndef Window_hpp
#define Window_hpp

#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "Ball.hpp"

using namespace std;

class Window
{
    int width;
    int height;
    bool closed = false;
    string name;
    bool init();
    SDL_Window* win = nullptr;
    SDL_Renderer* renderer = nullptr;
public:
    Window(const string &title, int height, int width);
    bool isClosed();
    void pollEvents(SDL_Event &event);
    void render();
    void close();
    SDL_Renderer* get_renderer();
    void Ballrenderer(Ball b);
};


#endif /* Window_hpp */
