#include "Window.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

Window::Window(const string &st, int h, int w)
{
    this->name = st;
    this->height = h;
    this->width = w;
    this->closed = !init();
}

void Window::close()
{
    closed = true;
    cout << "Closing Window" << endl;
}

bool Window::init()
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

void Window::pollEvents(SDL_Event &event)
{
    
    if (event.type == SDL_QUIT)
    {
        closed = true;
    }
}

void Window::render()
{
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

SDL_Renderer* Window::get_renderer()
{
    return renderer;
}

bool Window :: isClosed()
{
    return closed;
}

void Window::Ballrenderer(Ball b){
    text=SDL_CreateTextureFromSurface(renderer, b.getsurface());
    SDL_RenderCopy(renderer, text, NULL, b.getrect());
    SDL_RenderPresent(renderer);
}
