#include "Rock.hpp"
#include "Game.hpp"
#include "Map.hpp"
Rock::Rock(const char* file,int x,int y):Object(file,x, y, Game :: renderer)
{
    Object::setdrec(x_pos,y_pos,80,80);
    Object::setsrec(0,0,NULL,NULL);
}

void Rock::Updatepos(int i){
    x_pos+=i;
    //if(x_pos<0) x_pos=1280;
    //if(x_pos>1280) x_pos=0;
    setdrec(x_pos, y_pos, 80, 80);
}

void Rock::Render(){
    SDL_RenderCopy(Game::renderer, Object::text, NULL, &(Object::drec));
}

void Rock::Update() {
    const Uint8* currkey = SDL_GetKeyboardState(NULL);
    // When D is Pressed
    //cout << "left in update" << left << endl;
    if (right == true && (currkey[SDL_SCANCODE_D] || currkey[SDL_SCANCODE_RIGHT])) {
       // cout << "D is pressed\n";
        this->Updatepos(-1);
    }
    //              When A is pressed i.e LEFT arrow
    
        if (left == true && (currkey[SDL_SCANCODE_A] || currkey[SDL_SCANCODE_LEFT])) {
          //  cout << "A is pressed\n";
            this->Updatepos(1);
        }
}
void Rock::setLeft(bool m)
{
    left = m;
}

void Rock::setRight(bool m)
{
    right = m;
}
