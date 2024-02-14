#pragma once


#include <SDL.h>
#include <iostream>

class TextureCreator {
public:
    TextureCreator(SDL_Renderer* renderer, int width, int height, SDL_Color color)
    {
        loadTexture(renderer, width, height, color);
    }

    ~TextureCreator(){
        if(texture){
            SDL_DestroyTexture(texture);
        }
    }

    virtual void print(SDL_Renderer* renderer){};

protected:
    SDL_Texture* texture{nullptr};

    void loadTexture(SDL_Renderer* renderer, int width, int height, SDL_Color color);
};
