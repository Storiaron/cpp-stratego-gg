//
// Created by Deer on 15/02/2024.
//

#include "BluePlayerTexture.h"

void BluePlayerTexture::initTexture(SDL_Renderer *renderer) {

    SDL_Surface* surface = IMG_Load(filePath.c_str());

    if(!surface){
        std::cerr << "Error: Image surface: " << SDL_GetError() << std::endl;
        return;
    }

    blueTexture = SDL_CreateTextureFromSurface(renderer,surface);

    if(!blueTexture){
        std::cerr << "Error: Image texture: " << SDL_GetError() << std::endl;
        return;
    }

}

void BluePlayerTexture::print(SDL_Renderer *renderer) {
    SDL_QueryTexture(blueTexture, nullptr, nullptr, &blueRect.w, &blueRect.h);

    SDL_RenderCopy(renderer, blueTexture, nullptr, &blueRect);

}
