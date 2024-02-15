//
// Created by Deer on 14/02/2024.
//

#include "ButtonClickUI.h"

void ButtonClickUI::print(SDL_Renderer *renderer) {
    SDL_QueryTexture(texture, nullptr, nullptr, &clickRect.w, &clickRect.h);

    SDL_RenderCopy(renderer, texture, nullptr, &clickRect);
}
