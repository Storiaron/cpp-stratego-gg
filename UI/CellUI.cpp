//
// Created by Deer on 13/02/2024.
//

#include "CellUI.h"

void CellUI::print(SDL_Renderer *renderer) {

    if(cell->isSelected){
       selectedCellUi.print(renderer);
    } else if (cell->isHovered)
    {
        hoveredUi.print(renderer);
    }
    else {
        SDL_QueryTexture(texture, nullptr, nullptr, &cellRect.w, &cellRect.h);

        SDL_RenderCopy(renderer, texture, nullptr, &cellRect);
    }

}
