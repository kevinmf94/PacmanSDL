//
//  Game.hpp
//  PacmanSDL
//
//  Created by Kevin Martín Fernández on 11/09/2019.
//  Copyright © 2019 Kevin Martín Fernández. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

class Game {
public:
	SDL_Renderer* renderer;
	
	//Init all game
	void play();
	
protected:
	//Main variables
	bool exit = false;
	SDL_Event event;
	SDL_Window* window;
	double deltaTime;
	
	//Window configuration variables
	std::string windowName = "NoName";
	int width = 640;
	int height = 480;
	int logical_width = -1;
	int logical_height = -1;
	int bpp = 32;
	float frameRate = 30;
	
	//Manage game loop template
	virtual void init();
	virtual void start();
	virtual void loop();
	virtual void update(double deltaTime);
	virtual void onEvent(SDL_Event event);
	virtual void draw();
	virtual void end();
	
	//Basic functions to manage the screen
	void clearScreen();
	void updateScreen();
	
private:
	//Events process
	void processEvents();
	
	//Manage SDL
	void loadSDL();
	void shutdownSDL();
};

#endif /* Game_hpp */
