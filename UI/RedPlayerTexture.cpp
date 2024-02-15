//
// Created by Deer on 15/02/2024.
//

#include "RedPlayerTexture.h"

void RedPlayerTexture::initTexture(SDL_Renderer *renderer) {
    SDL_Surface* surface = IMG_Load(filePath.c_str());

    if(!surface){
        std::cerr << "Error: Image surface: " << SDL_GetError() << std::endl;
        return;
    }

    redTexture = SDL_CreateTextureFromSurface(renderer,surface);

    if(!redTexture){
        std::cerr << "Error: Image texture: " << SDL_GetError() << std::endl;
        return;
    }

}

void RedPlayerTexture::print(SDL_Renderer *renderer) {
    SDL_QueryTexture(redTexture, nullptr, nullptr, &redRect.w, &redRect.h);

    SDL_RenderCopy(renderer, redTexture, nullptr, &redRect);

}
