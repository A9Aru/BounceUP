#include "Game.hpp"
#include "Ball.hpp"
#include "Rock.hpp"
#include "Map.hpp"
#include "Button.hpp"
using namespace std;

static const int height = 1280;
static const int width = 720;

Ball* b;
//Rock* r, *r1;
Map* m;
SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;
// game state is the screen we are in.
// 0 is main menu.
// 1 is leaderboard.
// 2 is running gameplay.
int game_state = 0; // in the main menu by default.
// Buttons in the main menu.
Button* play;
Button* leaderboard;
Button* exitwin;

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
        //r = new Rock("rock.png", 1100, 600);
        //r1 = new Rock("rock.png", 1000, 600);
        m = new Map();
        m->drawMap();
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
    b->Update();
    for (int i = 0; i < m->level_rocks.size(); i++)
    {
        m->rocks = m->level_rocks[i];
        cout << "Rendering rock in level" << endl;
        m->rocks->Update();
    }
    for (int i = 0; i < m->level_coins.size(); i++)
    {
        m->coins = m->level_coins[i];
//        cout << "Rendering rock in level" << endl;
        m->coins->Update();
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    b->Render();
    m->render_objects();
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
