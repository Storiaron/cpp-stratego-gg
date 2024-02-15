#include "ButtonUI.h"

void ButtonUI::print(SDL_Renderer *renderer) {

    if(isHovered || isClicked){

        if(isClicked){
            clicked.print(renderer);
        } else {
            hovered.print(renderer);
        }
    } else {
        SDL_QueryTexture(texture, nullptr, nullptr, &buttonRect.w, &buttonRect.h);

        SDL_RenderCopy(renderer, texture, nullptr, &buttonRect);
    }
}
