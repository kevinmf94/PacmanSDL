//
//  Asset.hpp
//  PacmanSDL
//
//  Created by Kevin Martín Fernández on 15/09/2019.
//  Copyright © 2019 Kevin Martín Fernández. All rights reserved.
//

#ifndef Asset_hpp
#define Asset_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Game.hpp"

class Asset {

public:
	Asset(Game* game, SDL_Texture* texture, SDL_Rect clip);
	void draw();
	
	int x = 0, y = 0;
	int w = -1, h = -1;
	
private:
	SDL_Texture* texture;
	Game* game;
	SDL_Rect clip;
};

#endif /* Asset_hpp */
