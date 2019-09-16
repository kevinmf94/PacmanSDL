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
#include <vector>
#include <SDL2/SDL.h>
#include "Game.hpp"

class Asset {

public:
	Asset(Game* game);
	void draw();
	void addFrame(SDL_Texture* texture, SDL_Rect rect);
	
	int x = 0, y = 0;
	int w = -1, h = -1;
	
private:
	int frame = 0;
	std::vector<SDL_Texture*> textures;
	std::vector<SDL_Rect> rects;
	Game* game;
};

#endif /* Asset_hpp */
