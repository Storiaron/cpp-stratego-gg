#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include <utility>

class GameText {

public:
    GameText(SDL_Renderer* renderer,std::string  fontPath, int fontSize, std::string  message, const SDL_Color& color, int x, int y) :
            textTexture(nullptr),  fontPath(std::move(fontPath)), fontSize(fontSize), message(std::move(message)),
            textColor(color)
    {
        if(TTF_Init() < 0){
            std::cerr << "Error: TTF_Init(): " << TTF_GetError() << std::endl;
        } else {
            loadFont(renderer);
        }
        textRect.x = x;
        textRect.y = y;
    };

    GameText(const GameText& other) = delete;

    ~GameText(){
        if (textTexture) {
            SDL_DestroyTexture(textTexture);


        }

        TTF_Quit();
    };

    void display(SDL_Renderer* renderer);

    std::string message;

protected:
    std::string fontPath;
    int fontSize;
    SDL_Color textColor;
    SDL_Texture* textTexture;
    SDL_Rect textRect{};

    void loadFont(SDL_Renderer* renderer);
};