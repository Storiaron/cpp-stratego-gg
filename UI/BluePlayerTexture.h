#pragma once

#include <SDL_render.h>
#include <string>
#include <SDL_image.h>
#include <iostream>

class BluePlayerTexture {

public:
    BluePlayerTexture(SDL_Renderer* renderer, int x, int y){
        blueRect.x = x;
        blueRect.y = y;

        if(!IMG_Init(IMG_INIT_PNG)){
            std::cout << "SDL2_Image Error:" << SDL_GetError() << std::endl;
        }else{
            initTexture(renderer);
        }
    }

    ~BluePlayerTexture(){
        SDL_DestroyTexture(blueTexture);
    }

    void setFigureCoordinate(int x, int y){blueRect.x = x; blueRect.y = y;}

    SDL_Rect blueRect{0,0,0,0};

    void print(SDL_Renderer* renderer);

private:
    const std::string filePath{"../UI/figure-texture/blue.png"};
    SDL_Texture* blueTexture{nullptr};

    void initTexture(SDL_Renderer* renderer);
};
