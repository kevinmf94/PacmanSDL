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
#include <vector>

const int UP = 1;
const int DOWN = 2;
const int RIGHT = 3;
const int LEFT = 4;

const int X_SHEET = 456;
const int Y_SHEET = 0;
const int CELL_SHEET = 16;

class Pacman : public Game {
protected:
	virtual void init() override;
	virtual void start() override;
	virtual void update(double deltaTime) override;
	virtual void draw() override;
	virtual void onEvent(SDL_Event event) override;
	virtual void end() override;

private:	
	//Variables
	SDL_Texture* pacman_texture;
	SDL_Texture* wall_texture;
	SDL_Texture* coin_texture;
	
	//Pacman assets
	Asset* pacman;
	
	//Red ghost assets
	Asset* ghostRed;
	
	//Map assets
	Asset* wall;
	Asset* coin;
	
	//Pacman Variables
	int x = 1, y = 1;
	int orientation = RIGHT;
	
	//Ghost Red
	int gRedX = 6, gRedY = 11;
	
	//Pacman functions
	void drawMap();
	void drawPlayers();
	
	int checkNewOrientation(int newOrientation);
	void updatePacman();
	void updateGhostRed();
	
	//Util sprite sheet
	SDL_Rect getRectSheet(int x, int y);
};

#endif /* Pacman_hpp */
