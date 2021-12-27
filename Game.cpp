#include "Game.hpp"
#include "Ball.hpp"
#include "Rock.hpp"
using namespace std;

static const int height = 1280;
static const int width = 720;

Ball *b;
Rock *r;
SDL_Event Game::event;

Game::Game(){
    
}

Game::~Game(){
    
}

void Game::init(const char* title){
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << SDL_GetError() << endl;
        closed=true;
    }
    else{
        win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height,width, 0);
        
        if (win == nullptr)
        {
            cerr << SDL_GetError() << endl;
        }
        else{
            renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            
            if (renderer == nullptr)
            {
                cerr << SDL_GetError() << endl;
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                cout<<"Window Created\n";
                closed=false;
            }
        }
        b=new Ball("images/2.png",height/2,width/2,60,renderer);
        r=new Rock("rock.png",1100,600,renderer);
    }
}

void Game::eventhandler(){
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            closed=true;
            break;
    }
}

void Game::update(){
    //call this update for every switch case
    b->Update();
    r->Update();
}

void Game::render(){
    SDL_RenderClear(renderer);
    b->Render(renderer);
    r->Render(renderer);
    //Add here to render every frame
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::isClosed(){
    return closed;
}
