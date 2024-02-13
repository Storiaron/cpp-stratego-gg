//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include <SDL.h>


class IO_Handler {
public:
    IO_Handler(){
        initSDL();
    }

    ~IO_Handler(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
    }

    void run();

private:
    SDL_Window* window{nullptr};
    SDL_Renderer* renderer{nullptr};
    SDL_Event event{};

    const static int windowHeight{1000};
    const static int windowWidth{1000};

    bool isRunning{true};

    void initSDL();
    void handleEvent();
};
