//
// Created by AsusTuf on 2024. 02. 12..
//

#include "IO_Handler.h"

void IO_Handler::initSDL() {

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_CreateWindow("Dradegon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth,windowHeight,
                     SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);

    SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

}

void IO_Handler::run() {

    while(isRunning){
        handleEvent();
        SDL_Delay(25);
    }
}

void IO_Handler::handleEvent() {

    while (SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE){
            isRunning = false;
        }
    }
}

