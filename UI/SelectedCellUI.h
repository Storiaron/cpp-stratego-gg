#pragma once

#include "TextureCreator.h"

class SelectedCellUI : public TextureCreator {
public:
    SelectedCellUI(SDL_Renderer* renderer, int width, int height, int x, int y, SDL_Color color) :
    TextureCreator(renderer, width, height, color)
    {
        selectedCellRect.x = x;
        selectedCellRect.y = y;
    };

    void print(SDL_Renderer *renderer) override;

    void setSelectedCellCoordinates(int x, int y){
        selectedCellRect.x = x;
        selectedCellRect.y = y;
    };

private:
    SDL_Rect selectedCellRect{0,0,0,0};
};
