#include "Game.hpp"
#include "Ball.hpp"
#include "Rock.hpp"
#include "Map.hpp"
using namespace std;

static const int height = 1280;
static const int width = 720;

Ball* b;
Rock* r;
Map* m;
SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << SDL_GetError() << endl;
        closed = true;
    }
    else {
        win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, 0);

        if (win == nullptr)
        {
            cerr << SDL_GetError() << endl;
        }
        else {
            renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if (renderer == nullptr)
            {
                cerr << SDL_GetError() << endl;
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 135, 206, 255, 255); //135,206,255 or 0,191,255
                cout << "Window Created\n";
                closed = false;
            }
        }
        b = new Ball("images/2.png", height / 2, width / 2, 60);
        r = new Rock("images/rock.png", 1100, 600);
        m = new Map();
    }
}

void Game::eventhandler() {
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        closed = true;
        break;
    }
}

void Game::update() {
    //call this update for every switch case
    b->Update(r);
    //r->Update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    m->drawMap();
    b->Render();
    r->Render();
    //Add here to render every frame
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::isClosed() {
    return closed;
}