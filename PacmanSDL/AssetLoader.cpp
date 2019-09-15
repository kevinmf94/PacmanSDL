//
//  AssetManager.cpp
//  PacmanSDL
//
//  Created by Kevin Martín Fernández on 11/09/2019.
//  Copyright © 2019 Kevin Martín Fernández. All rights reserved.
//

#include "AssetLoader.hpp"

SDL_Texture* AssetLoader::loadPNG(const std::string fileName, SDL_Renderer* render)
{
	printf("Trying to load image: %s\n", fileName.c_str());
	SDL_Texture *texture = nullptr;
	
	//Load the image
	SDL_Surface *loadedImage = IMG_Load(fileName.c_str());
	
	//If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr){
		texture = SDL_CreateTextureFromSurface(render, loadedImage);
		SDL_FreeSurface(loadedImage);
		
		//Make sure converting went ok too
		if (texture == nullptr){
			printf("Error al convertir la imagen a textura\n");
		}
	}
	else {
		printf("Error al cargar la imagen en una textura\n");
	}
	
	return texture;
}
