#pragma once

#include "TextureCreator.h"

class SelectedCellUI : public TextureCreator {
public:
    SelectedCellUI(SDL_Renderer* renderer, int width, int height, int x, int y) :
    TextureCreator(renderer, width, height, SDL_Color{0,0,255,255})
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
