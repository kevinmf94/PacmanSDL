//
//  Pacman.hpp
//  PacmanSDL
//
//  Created by Kevin Martín Fernández on 11/09/2019.
//  Copyright © 2019 Kevin Martín Fernández. All rights reserved.
//

#ifndef Pacman_hpp
#define Pacman_hpp

#include "Game.hpp"
#include "Asset.hpp"
#include "PacmanMap.hpp"

const int UP = 1;
const int DOWN = 2;
const int RIGHT = 3;
const int LEFT = 4;

class Pacman : public Game {
protected:
	virtual void init() override;
	virtual void start() override;
	virtual void update(double deltaTime) override;
	virtual void draw() override;
	virtual void onEvent(SDL_Event event) override;

private:	
	//Variables
	SDL_Texture* pacman_texture;
	SDL_Texture* wall_texture;
	
	//Assets
	Asset* wall;
	Asset* pacman;
	
	//Pacman Variables
	int x = 1, y = 1;
	int orientation = RIGHT;
	
	//Pacman functions
	void drawWalls();
	void drawPacman();
	int checkNewOrientation(int newOrientation);
	void updatePacman();
};

#endif /* Pacman_hpp */
