#pragma once

#include "TextureCreator.h"
#include "ButtonHoveredUI.h"
#include "ButtonClickUI.h"

class ButtonUI : public TextureCreator {

public:
    ButtonUI(SDL_Renderer* renderer, int width, int height, int x, int y) :
            TextureCreator(renderer, width, height, SDL_Color{162, 158, 105,255}),
            hovered(renderer, width, height, x,y,SDL_Color{152, 148, 95,255}),
            clicked(renderer, width, height,x,y,SDL_Color{142, 138, 85,255})
    {
        buttonRect.x = x;
        buttonRect.y = y;
    }

    void print(SDL_Renderer* renderer) override;

    bool isHovered{false};
    bool isClicked{false};

    SDL_Rect buttonRect{0,0,0,0};

private:
    ButtonHoveredUI hovered;
    ButtonClickUI clicked;
};
