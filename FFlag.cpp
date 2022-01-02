#include "FFlag.hpp"
#include "Game.hpp"
FFlag::FFlag(const char* file, int x, int y) :Object(file, x, y, Game::renderer)
{
    Object::setdrec(x_pos, y_pos, 80, 80);
    Object::setsrec(0, 0, NULL, NULL);
}

void FFlag::Updatepos(int i) {
    x_pos += i;
    //if (x_pos < 0) x_pos = 1280;
    //if (x_pos > 1280) x_pos = 0;
    setdrec(x_pos, y_pos, 80, 80);
}

void FFlag::Render() {
    SDL_RenderCopy(Game::renderer, Object::text, NULL, &(Object::drec));
}

void FFlag::Update() {
    const Uint8* currkey = SDL_GetKeyboardState(NULL);
    // When D is Pressed
    if (currkey[SDL_SCANCODE_D] || currkey[SDL_SCANCODE_RIGHT]) {
        cout << "D is pressed\n";
        this->Updatepos(-5);
    }
    //              When A is pressed i.e LEFT arrow
    else if (currkey[SDL_SCANCODE_A] || currkey[SDL_SCANCODE_LEFT]) {
        cout << "A is pressed\n";
        this->Updatepos(5);
    }
}
