#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
#include"Texture.hpp"
#include "Game.hpp"
#include<bits/stdc++.h>
#include<vector>

using namespace std;


class Button{
private:
	SDL_Rect box;
	int x_pos;
	int y_pos; 
	const char* text;  // Text to be displayed on the button
	int width;
	int height;

public: 
	Button(int x_pos,int y_pos,int width,int height,const char* text);
// void draw_button(Window *w); 
	bool isOnButton(vector<int> a); // returns if True if mouse is on the button
	bool isClicked(vector<int> a); // returs true if the Button is clicked
	void Update();
    void Render();
    //void mouseinput(); // handles all the mouse events.

}; 