//
//  Asset.cpp
//  PacmanSDL
//
//  Created by Kevin Martín Fernández on 15/09/2019.
//  Copyright © 2019 Kevin Martín Fernández. All rights reserved.
//

#include "Asset.hpp"

Asset::Asset(Game* game, SDL_Texture* texture, SDL_Rect clip)
{
	this->game = game;
	this->texture = texture;
	this->clip = clip;
}

void Asset::draw()
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	
	if(w < 0)
	   rect.w = clip.w;
	else
		rect.w = w;
	   
	if(h < 0)
	   rect.h = clip.h;
	else
		rect.h = h;
	
	SDL_RenderCopy(game->renderer, texture, &clip, &rect);
}
