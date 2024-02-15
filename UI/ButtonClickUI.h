#pragma once

#include "TextureCreator.h"

class ButtonClickUI : TextureCreator {
public:
    ButtonClickUI(SDL_Renderer* renderer, int width, int height, int x, int y, SDL_Color color) :
            TextureCreator(renderer, width, height, color){
        clickRect.x = x;
        clickRect.y = y;
    };

    void print(SDL_Renderer* renderer) override;


private:
    SDL_Rect clickRect{0,0,0,0};
};
