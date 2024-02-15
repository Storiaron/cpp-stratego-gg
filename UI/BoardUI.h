#pragma once

#include "TextureCreator.h"

class BoardUI : public TextureCreator {
public:
    BoardUI(SDL_Renderer* renderer, int width, int height, int x, int y) :
    TextureCreator(renderer, width, height, SDL_Color{133, 104, 87,255})
    {
        boardRect.x = x;
        boardRect.y = y;
    };

    void print(SDL_Renderer* renderer) override;

private:
    SDL_Rect boardRect{0,0,0,0};
};
