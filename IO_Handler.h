//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include <SDL.h>
#include <memory>
#include <vector>
#include "UI/BoardUI.h"
#include "UI/CellUI.h"
#include "Logic/Cell.h"


class IO_Handler {
public:
    IO_Handler(){
        initSDL();
        initLogic();
        initUI();
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

    const static int windowHeight{1010};
    const static int windowWidth{1010};

    int currentCellIndex{-1};
    std::vector<std::shared_ptr<Cell>> cells{};
    std::vector<std::shared_ptr<CellUI>> boardCellsUI;
    std::shared_ptr<BoardUI> boardUI{nullptr};

    bool isRunning{true};
    int numberOfCells = 100;

    void initSDL();
    void initLogic();
    void initUI();
    void display();
    void handleEvent();
    void handleClick(const SDL_MouseButtonEvent &click);
    void handleHover(SDL_MouseMotionEvent motion);

};
