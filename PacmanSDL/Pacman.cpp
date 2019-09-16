//
//  Pacman.cpp
//  PacmanSDL
//
//  Created by Kevin Martín Fernández on 11/09/2019.
//  Copyright © 2019 Kevin Martín Fernández. All rights reserved.
//

#include "Pacman.hpp"
#include "AssetLoader.hpp"
#include <SDL2/SDL.h>


void Pacman::init()
{
	windowName = "Pacman";
	width = 1000;
	height = 600;
	logical_width = CELL_SIZE*MAP_W;
	logical_height = CELL_SIZE*MAP_H;
}

void Pacman::start()
{
	pacman_texture = AssetLoader::loadPNG("./Sprites/pacmanpsprite.png", renderer);
	wall_texture = AssetLoader::loadPNG("./Sprites/pacman_separate/rosekane_148.png", renderer);
	coin_texture = AssetLoader::loadPNG("./Sprites/pacman_separate/rosekane_0.png", renderer);
	
	//Wall
	wall = new Asset(this, wall_texture, {0,0,20,20});
	wall->w = wall->h = CELL_SIZE;
	
	//Coin
	coin = new Asset(this, coin_texture, {0,0,20,20});
	coin->w = coin->h = CELL_SIZE;
	
	
	pacman = new Asset(this, pacman_texture, {453,0,20,15});
	pacman->w = pacman->h = CELL_SIZE;
}

void Pacman::update(double deltaTime)
{
	//Pacman movement
	updatePacman();
}

void Pacman::onEvent(SDL_Event event)
{
	Game::onEvent(event);
	
	int newOrientation = -1;
	
	switch (event.type) {
		case SDL_KEYDOWN:
			{
				if(event.key.keysym.sym == SDLK_DOWN)
					newOrientation = DOWN;
				else if (event.key.keysym.sym == SDLK_UP)
					newOrientation = UP;
				else if (event.key.keysym.sym == SDLK_RIGHT)
					newOrientation = RIGHT;
				else if (event.key.keysym.sym == SDLK_LEFT)
					newOrientation = LEFT;
				
				orientation = checkNewOrientation(newOrientation);
			}
			break;
	}
	
}

void Pacman::draw()
{
	clearScreen();
	drawMap();
	drawPacman();
	updateScreen();
}

void Pacman::updatePacman()
{
	if(orientation == RIGHT)
	{
		if(MAP[y][(x+1)] != WALL)
			x += 1;
	}
	else if(orientation == DOWN)
	{
		if(MAP[y+1][x] != WALL)
			y += 1;
	}
	else if(orientation == LEFT)
	{
		if(MAP[y][x-1] != WALL)
			x -= 1;
	}
	else if(orientation == UP)
	{
		if(MAP[y-1][x] != WALL)
			y -= 1;
	}
}

void Pacman::drawPacman()
{
	pacman->draw();
	pacman->x = x*CELL_SIZE;
	pacman->y = y*CELL_SIZE;
}

void Pacman::drawMap()
{
	int i, j;
	
	for(i = 0; i < MAP_H; i++)
	{
		for(j = 0; j < MAP_W; j++)
		{
			int cell = MAP[i][j];
			switch(cell)
			{
				case WALL:
					wall->x = j*CELL_SIZE;
					wall->y = i*CELL_SIZE;
					wall->draw();
					break;
				/*case COIN:
					coin->x = j*CELL_SIZE;
					coin->y = i*CELL_SIZE;
					coin->draw();
					break;*/
			}
		}
	}
}

int Pacman::checkNewOrientation(int newOrientation)
{
	switch(newOrientation)
	{
		case DOWN:
			if(MAP[y+1][x] != WALL)
				return newOrientation;
			break;
		case UP:
			if(MAP[y-1][x] != WALL)
				return newOrientation;
			break;
		case LEFT:
			if(MAP[y][x-1] != WALL)
				return newOrientation;
			break;
		case RIGHT:
			if(MAP[y][x+1] != WALL)
				return newOrientation;
			break;
	}
	
	return orientation;
}

void Pacman::end()
{
	delete wall;
	delete coin;
	delete pacman;
	
	SDL_DestroyTexture(pacman_texture);
	SDL_DestroyTexture(coin_texture);
	SDL_DestroyTexture(wall_texture);
	
	Game::end();
}
