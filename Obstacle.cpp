#include "Obstacle.hpp"
#include "Game.hpp"
//constructor
Obstacle::Obstacle(const char* file, int x, int y) :Object(file, x, y, Game::renderer)
{
    Object::setdrec(x_pos, y_pos, 80, 80);
    Object::setsrec(0, 0, NULL, NULL);
}
//update position
void Obstacle::Updatepos(int i) {
    x_pos += i;
    //if (x_pos < 0) x_pos = 1280;
    //if (x_pos > 1280) x_pos = 0;
    setdrec(x_pos, y_pos, 80, 80);
}
//Render objects
void Obstacle::Render() {
    SDL_RenderCopy(Game::renderer, Object::text, NULL, &(Object::drec));
}
//update based on user input
void Obstacle::Update(bool l, bool r) {
    const Uint8* currkey = SDL_GetKeyboardState(NULL);
    // When D is Pressed
    if (r == true && (currkey[SDL_SCANCODE_D] || currkey[SDL_SCANCODE_RIGHT])) {
        this->Updatepos(-5);
    }
    //              When A is pressed i.e LEFT arrow
    else if (l == true && (currkey[SDL_SCANCODE_A] || currkey[SDL_SCANCODE_LEFT])) {
        this->Updatepos(5);
    }
}