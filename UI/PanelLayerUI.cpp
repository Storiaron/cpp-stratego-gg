#include "PanelLayerUI.h"

void PanelLayerUI::print(SDL_Renderer *renderer) {
    SDL_QueryTexture(texture, nullptr, nullptr, &panelRect.w, &panelRect.h);

    SDL_RenderCopy(renderer, texture, nullptr, &panelRect);
}
