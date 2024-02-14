#pragma once

#include "TextureCreator.h"

class BoardUI : public TextureCreator {
public:
    BoardUI(SDL_Renderer* renderer, int width, int height) :
    TextureCreator(renderer, width, height, SDL_Color{255,0,0,255})
    {
        boardRect.x = 0;
        boardRect.y = 0;
    };

    void print(SDL_Renderer* renderer) override;

private:
    SDL_Rect boardRect{0,0,0,0};
};
