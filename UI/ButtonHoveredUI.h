#pragma once

#include "TextureCreator.h"

class ButtonHoveredUI : public TextureCreator {
public:
    ButtonHoveredUI(SDL_Renderer* renderer, int width, int height, int x, int y, SDL_Color color) :
            TextureCreator(renderer, width, height, color)
    {
        hoverRect.x = x;
        hoverRect.y = y;
    }

    void print(SDL_Renderer* renderer) override;

private:
    SDL_Rect hoverRect{0,0,0,0};
};
