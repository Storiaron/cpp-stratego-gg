//
// Created by Deer on 14/02/2024.
//

#include "ButtonHoveredUI.h"

void ButtonHoveredUI::print(SDL_Renderer *renderer) {
    SDL_QueryTexture(texture, nullptr, nullptr, &hoverRect.w, &hoverRect.h);

    SDL_RenderCopy(renderer, texture, nullptr, &hoverRect);
}
