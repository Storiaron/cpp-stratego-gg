#pragma once

#include "TextureCreator.h"

class CellHoveredUI : public TextureCreator {
public:
    CellHoveredUI(SDL_Renderer* renderer, int width, int height, int x, int y, SDL_Color color) :
            TextureCreator(renderer, width, height, color)
    {
        hoveredCellRect.x = x;
        hoveredCellRect.y = y;
    };

    void print(SDL_Renderer* renderer) override;

private:
    SDL_Rect hoveredCellRect{0,0,0,0};
};
