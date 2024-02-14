#include "BoardUI.h"

void BoardUI::print(SDL_Renderer *renderer) {
    SDL_QueryTexture(texture, nullptr, nullptr, &boardRect.w, &boardRect.h);

    SDL_RenderCopy(renderer, texture, nullptr, &boardRect);
}
