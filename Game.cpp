#include "Game.hpp"
#include "Ball.hpp"
#include "Rock.hpp"
#include "Map.hpp"
#include "Button.hpp"
#include "Texture.hpp"
#include "Obstacle.hpp"
#include "CollisionHandler.hpp"
#include "Score.hpp"
using namespace std;

static const int height = 720;
static const int width = 1280;

Ball* b;
//Rock* r, *r1;
Map* m;
SDL_Event Game::event;
CollisionHandler* handle;
SDL_Renderer* Game::renderer = nullptr;
SDL_Texture* main_menu = nullptr;
Score* s;
bool ex=false;
typedef enum {
    MAINMENU,
    PLAY,
    EXIT,
    LEADERBOARD,
    GAMEOVER
} GAMESTATE;

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
        win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

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
        b = new Ball("images/1.png", 160, 80, 80);
        s = new Score();
        //r = new Rock("rock.png", 1100, 600);
        //r1 = new Rock("rock.png", 1000, 600);
        m = new Map();
        m->drawMap();
        handle = new CollisionHandler(m);
    }
}

void Game::eventhandler() {
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        closed = true;
            ex=true;
        break;
    }
}

int Game::update() {
    //call this update for every switch case
    handle->checkMapCollision(b->getdrec(), s);
    if (handle->checkFlag(b->getdrec()) || handle->checkObstacle(b->getdrec()) || handle->checkObstacle1(b->getdrec())) {
        closed = true;
        return GAMEOVER;
    }
    bool d = handle->checkWallDownCollision(b->getdrec());
    bool u = handle->checkWallUpCollision(b->getdrec());
    bool l = handle->checkWallLeftCollision(b->getdrec());
    bool r = handle->checkWallRightCollision(b->getdrec());
    b->Update(d,u);
    
    for (int i = 0; i < m->level_rocks.size(); i++)
    {
        m->rocks = m->level_rocks[i];
        m->rocks->Update(l,r);
    }

    for (int i = 0; i < m->level_obstacles.size(); i++)
    {
        m->obstacles = m->level_obstacles[i];
        m->obstacles->Update(l,r);
    }

    for (int i = 0; i < m->level_obstacles1.size(); i++)
    {
        m->obstacles1 = m->level_obstacles1[i];
        m->obstacles1->Update(l, r);
    }

    for (int i = 0; i < m->level_coins.size(); i++)
    {
        m->coins = m->level_coins[i];
        m->coins->Update(l,r);
    }
    m->flag->Update(l,r);
    if(closed==true && ex==true) return EXIT;
    return PLAY;
}

void Game::render() {
    SDL_RenderClear(renderer);
    m->render_objects();
    b->Render();
    s->render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
}

bool Game::isClosed() {
    return closed;
}
void Game::SetClosed(bool set) {
    closed = set;
}

int Game::get_score() {
    return s->score;
}
