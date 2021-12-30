#include"Button.hpp"
#include<bits/stdc++.h>

using namespace std;
Button :: Button(int x_pos,int y_pos,int width,int height,const char* text){
	this->x_pos = x_pos; 
	this->y_pos = y_pos;
	this->width = width;
	this->height = height;
	this->text = text;  // text to be displayed on the button.
}

// void Button :: draw_button(Window* w){
 //  SDL_Texture *texture = w->loadTexture(this->image_path);
 //  w->Render_texture(texture,this->x_pos,this->y_pos,this->width,this->height);
 // }


bool Button :: isOnButton(vector<int> a){
	int mouse_x = a[0]; 
	int mouse_y = a[1];

    if((mouse_x > this->x_pos)&&(mouse_x < this->x_pos + this->width)){
    	 if((mouse_y > this->y_pos)&&(mouse_y < this->y_pos + this->height)){
                return true;
    	 }

    	 return false;	
    }
    return false;
}

bool Button :: isClicked(vector<int> a){
	if(this->isOnButton(a) && a[2]==1 ){
		return true;
	}

	return false;
}