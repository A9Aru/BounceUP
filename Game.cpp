#include "Game.hpp"
#include "Ball.hpp"
#include "Rock.hpp"
#include "Map.hpp"
#include "Button.hpp"
#include "Texture.hpp"
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
// Buttons in the main menu.
int Game::game_state = 0;
SDL_Texture *main_menu = nullptr;
Button* play;
Button* leaderboard;
Button* exitwin;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title) {
    game_state = 0; // in the main menu by default
    play = new Button(1200,220,350,130,"NULL");  // Coordinates of the play button.

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
            main_menu = Texture::LoadTexture("main_menu.jpg",renderer);
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
        if(game_state == 0){
            // draw the Main Menu if the game state is 0.
            SDL_RenderCopy(Game::renderer,main_menu, NULL,NULL);
        }
        m = new Map();
        if(game_state == 1){
        m->drawMap();  }
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
    
    if(game_state == 1){
        m->drawMap();  
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
    
    if(game_state == 0){
        play->Update();
    }
  cout << "GAME STATE IS " << game_state << endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    if(game_state == 0) SDL_RenderCopy(Game::renderer,main_menu, NULL,NULL);
    if(game_state == 1){
    b->Render();
    m->render_objects(); }
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
