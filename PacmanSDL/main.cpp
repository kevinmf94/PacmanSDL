//
//  main.cpp
//  PacmanSDL
//
//  Created by Kevin Martín Fernández on 10/09/2019.
//  Copyright © 2019 Kevin Martín Fernández. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL.h>

#include "Pacman.hpp"

//The surfaces
//SDL_Surface *image = NULL;
//SDL_Surface *screen = NULL;

int main(int argc, const char * argv[]) {
	
	Pacman pacman;
	pacman.play();
	
    /*SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0 );
    SDL_RenderClear(renderer);
    
    SDL_Surface* image = IMG_Load("Sprites/pacmanpsprite.png");
    if(image == NULL){
        
        printf( "Unable to load image %s! SDL_image Error: %s\n", "PATH", IMG_GetError() );
    }
    
    //SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    
    //SDL_RenderCopy(renderer, texture, NULL, NULL);
    //SDL_RenderPresent(renderer);
    
    
    while (!quit)
    {
        SDL_WaitEvent(&event);
        
        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
        }
    }
    
    //SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);*/
    
    return 0;
}
