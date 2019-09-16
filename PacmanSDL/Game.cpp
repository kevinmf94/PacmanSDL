//
//  Game.cpp
//  PacmanSDL
//
//  Created by Kevin Martín Fernández on 11/09/2019.
//  Copyright © 2019 Kevin Martín Fernández. All rights reserved.
//

#include "Game.hpp"

/*
* Init SDL librarys and configure window/screen
*/
void Game::loadSDL()
{
	//Init SDL Engine
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Error loading SDL\n");
	}
	
	//Init image engine
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		printf("Error loading IMG_init\n");
	}
	
	//Create window
	window = SDL_CreateWindow(windowName.c_str(),
							  SDL_WINDOWPOS_UNDEFINED,
							  SDL_WINDOWPOS_UNDEFINED,
							  width,
							  height, 0);
	
	//Create renderer
	renderer = SDL_CreateRenderer(window, -1, 0);
	
	if(logical_width > 0 && logical_height > 0)
		SDL_RenderSetLogicalSize(renderer, logical_width, logical_height);
}

/**
* Free memory and shutdown SDL library.
*/
void Game::shutdownSDL()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}

/*
* Clear screen to black
*/
void Game::clearScreen()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Game::updateScreen()
{
	SDL_RenderPresent(renderer);
}

void Game::init(){}
void Game::start(){}
void Game::update(double deltaTime){}
void Game::draw(){}

void Game::loop()
{
	Uint64 now = SDL_GetPerformanceCounter();
	Uint64 last;
	
	while (!exit)
	{
		last = now;
		now = SDL_GetPerformanceCounter();
		
		deltaTime = (double) ((last-now) * 1000/ SDL_GetPerformanceFrequency());
		
		SDL_Delay(200);
		
		processEvents();
		update(deltaTime);
		draw();
	}
}

void Game::processEvents()
{
	while (SDL_PollEvent(&event))
	{
		onEvent(event);
	}
}

void Game::onEvent(SDL_Event event)
{
	switch (event.type)
	{
		case SDL_QUIT:
			exit = true;
			break;
	}
}

void Game::end()
{
	
}

void Game::play()
{
	init();
	loadSDL();
	start();
	loop();
	end();
	shutdownSDL();
}
