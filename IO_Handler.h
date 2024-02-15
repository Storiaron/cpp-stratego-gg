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
#include "UI/PanelLayerUI.h"
#include "UI/ButtonUI.h"
#include "Logic/GameLogic.h"
#include "Logic/InfoPanel.h"
#include "Logic/ShopPanel.h"
#include "Figures/Soldiers/Marauder.h"
#include "Figures/Soldiers/Peasant.h"
#include "UI/PanelUI/PanelUI.h"


class IO_Handler {
public:
    IO_Handler(){
        initSDL();
        initCells();
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

    std::shared_ptr<GameLogic> gameLogic;
    std::shared_ptr<InfoPanel> infoPanel;
    std::shared_ptr<ShopPanel> shopPanel;
    std::shared_ptr<InfoPanel> currentPanel;

    std::shared_ptr<PanelUI> infoPanelUI{nullptr};

    const static int layerWidth{250};
    const static int boardWidth{1010};
    const static int windowHeight{1010};
    const static int windowWidth{layerWidth + boardWidth};

    int currentCellIndex{-1};
    std::vector<std::shared_ptr<Cell>> cells{};
    std::vector<std::shared_ptr<CellUI>> boardCellsUI;
    std::shared_ptr<BoardUI> boardUI{nullptr};
    std::shared_ptr<PanelLayerUI> panelUI{nullptr};
    std::shared_ptr<ButtonUI> shopButton{nullptr};

    bool isRunning{true};
    int numberOfCells = 100;

    void initSDL();
    void initCells();
    void initLogic();
    void initUI();
    void display();
    void handleEvent();
    void handleClick(const SDL_MouseButtonEvent &click);
    void handleHover(SDL_MouseMotionEvent motion);
    void togglePanels();

    void handleClickInGamePhase();

    void handleClickInBuyPhase();

    void decideClickHandlePhase();
};
