#include "Window.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

window::window(const string &st, int h, int w)
{
    this->name = st;
    this->height = h;
    this->width = w;
    this->closed = !init();
}

void window::close()
{
    closed = true;
    cout << "Closing window" << endl;
}

bool window::init()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cerr << SDL_GetError() << endl;
        return false;
    }

    win = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    if (win == nullptr)
    {
        cerr << SDL_GetError() << endl;
        return false;
    }

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr)
    {
        cerr << SDL_GetError() << endl;
        return false;
    }

    return true;
}

void window::pollEvents(SDL_Event &event)
{
    
    if (event.type == SDL_QUIT)
    {
        closed = true;
    }
}

void window::render()
{
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 205, 210, 255);
    SDL_RenderClear(renderer);
}

SDL_Renderer* window::get_renderer()
{
    return renderer;
}

bool window :: isClosed()
{
    return closed;
}
