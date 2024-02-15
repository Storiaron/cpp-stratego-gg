#pragma once

#include "TextureCreator.h"

class PanelLayerUI : public TextureCreator {
public:
    PanelLayerUI(SDL_Renderer* renderer, int width, int height, int x, int y) :
    TextureCreator(renderer, width, height, SDL_Color{255,0,255,255})
    {
        panelRect.x = x;
        panelRect.y = y;
    }

    void print(SDL_Renderer* renderer) override;

private:
    SDL_Rect panelRect{0,0,0,0};
};
