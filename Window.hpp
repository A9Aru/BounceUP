#ifndef Window_hpp
#define Window_hpp

#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "Ball.hpp"
#include "Rock.hpp"
using namespace std;

class Window
{
private:
    int width;
    int height;
    bool closed = false;
    string name;
    bool init();
    SDL_Window* win = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture *text=nullptr;
    SDL_Rect Ballsprite;
    int texturewidth,textureheight;
    int frameheight,framewidth;
public:
    Window(const string &title, int height, int width);
    bool isClosed();
    void closewindow();
<<<<<<< Updated upstream
    void pollEvents(SDL_Event &event,Ball &b);
=======
    void pollEvents(SDL_Event &event,Ball b,Rock r);
>>>>>>> Stashed changes
    void render();
    void close();
    SDL_Renderer* get_renderer();
    void render(Ball b,Rock r);
    ~Window();
};


#endif /* Window_hpp */
