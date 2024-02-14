//
// Created by Deer on 13/02/2024.
//

#include "SelectedCellUI.h"

void SelectedCellUI::print(SDL_Renderer *renderer) {
    SDL_QueryTexture(texture, nullptr, nullptr, &selectedCellRect.w, &selectedCellRect.h);

    SDL_RenderCopy(renderer, texture, nullptr, &selectedCellRect);
}
