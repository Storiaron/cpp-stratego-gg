#pragma once

#include <utility>

#include "TextureCreator.h"
#include "../Logic/Cell.h"
#include "SelectedCellUI.h"
#include "CellHoveredUI.h"

class CellUI : public TextureCreator {
public:
    CellUI(SDL_Renderer* renderer, std::shared_ptr<Cell> cell, int width, int height, int x, int y) :
            cell(std::move(cell)),
            TextureCreator(renderer, width, height, SDL_Color{212,255, 168,255}),
            selectedCellUi(renderer, width, height, x,y,SDL_Color{187, 227, 155,255}),
            hoveredUi(renderer, width, height,x,y,SDL_Color{197,239,163,255}){
        cellRect.x = x;
        cellRect.y = y;
    }

    SDL_Rect cellRect{0,0,0,0};

    void print(SDL_Renderer* renderer) override;

private:
    SelectedCellUI selectedCellUi;
    CellHoveredUI hoveredUi;
    std::shared_ptr<Cell> cell;
};
