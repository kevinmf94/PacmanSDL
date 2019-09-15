//
//  AssetManager.hpp
//  PacmanSDL
//
//  Created by Kevin Martín Fernández on 11/09/2019.
//  Copyright © 2019 Kevin Martín Fernández. All rights reserved.
//

#ifndef AssetManager_hpp
#define AssetManager_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>

class AssetLoader {
public:
	static SDL_Texture* loadPNG(const std::string fileName, SDL_Renderer* render);
};

#endif /* AssetManager_hpp */
