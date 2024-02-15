#pragma once

#include <SDL_render.h>
#include <string>
#include <SDL_image.h>
#include <iostream>

class RedPlayerTexture {
public:
    RedPlayerTexture(SDL_Renderer* renderer, int x, int y){
        redRect.x = x;
        redRect.y = y;

        if(!IMG_Init(IMG_INIT_PNG)){
            std::cout << "SDL2_Image Error:" << SDL_GetError() << std::endl;
        }else{
            initTexture(renderer);
        }
    }

    ~RedPlayerTexture(){
        SDL_DestroyTexture(redTexture);
    }

    void setFigureCoordinate(int x, int y){redRect.x = x; redRect.y = y;}

    void print(SDL_Renderer* renderer);

private:
    const std::string filePath{"../UI/figure-texture/red.png"};
    SDL_Rect redRect{0,0,0,0};
    SDL_Texture* redTexture{nullptr};

    void initTexture(SDL_Renderer* renderer);
};
