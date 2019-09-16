//
//  PacmanMap.h
//  PacmanSDL
//
//  Created by Kevin Martín Fernández on 16/09/2019.
//  Copyright © 2019 Kevin Martín Fernández. All rights reserved.
//

#ifndef PacmanMap_h
#define PacmanMap_h

const int MAP_H = 9;
const int MAP_W = 10;
const int CELL_SIZE = 20;

/*
 * Pacman MAP
 * 0: Free
 * 1: Wall
 * 2: Coin
 * 4: Powerup
 * 5: Ghost
 */
const int FREE = 0;
const int WALL = 1;
const int COIN = 2;
const int POWERUP = 3;
const int GHOST = 5;

const int MAP[MAP_H][MAP_W] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,1},
	{1,0,0,0,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
};

#endif /* PacmanMap_h */
