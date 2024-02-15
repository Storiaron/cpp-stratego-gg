#include "CellHoveredUI.h"

void CellHoveredUI::print(SDL_Renderer *renderer) {
    SDL_QueryTexture(texture, nullptr, nullptr, &hoveredCellRect.w, &hoveredCellRect.h);

    SDL_RenderCopy(renderer, texture, nullptr, &hoveredCellRect);
}
