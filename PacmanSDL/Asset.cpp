//
//  Asset.cpp
//  PacmanSDL
//
//  Created by Kevin Martín Fernández on 15/09/2019.
//  Copyright © 2019 Kevin Martín Fernández. All rights reserved.
//

#include "Asset.hpp"

Asset::Asset(Game* game)
{
	this->game = game;
}

void Asset::addFrame(SDL_Texture* texture, SDL_Rect rect)
{
	textures.push_back(texture);
	rects.push_back(rect);
}


void Asset::draw()
{
	SDL_Rect frameRect = rects[frame];
	
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	
	if(w < 0)
	   rect.w = frameRect.w;
	else
		rect.w = w;
	   
	if(h < 0)
	   rect.h = frameRect.h;
	else
		rect.h = h;
	
	SDL_RenderCopy(game->renderer, textures[frame], &frameRect, &rect);
	
	if(++frame >= textures.size())
	{
		frame = 0;
	}
}
