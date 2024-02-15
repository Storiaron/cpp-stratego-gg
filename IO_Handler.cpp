//
// Created by AsusTuf on 2024. 02. 12..
//

#include "IO_Handler.h"
#include "Figures/Soldiers/Peasant.h"
#include "Figures/Soldiers/Artificer.h"
#include "Figures/Soldiers/Marauder.h"
#include "Figures/Soldiers/Cavalier.h"
#include "Figures/Soldiers/Archer.h"
#include "Figures/Soldiers/Paladin.h"
#include "Figures/Soldiers/Wall.h"
#include "Figures/Soldiers/King.h"
#include "Figures/Soldiers/BabyDragon.h"
#include "Figures/Soldiers/Vampire.h"
#include "Figures/Soldiers/Sorcerer.h"
#include "Figures/Soldiers/Cleric.h"
#include "Figures/Soldiers/Knight.h"
#include "Figures/Soldiers/Cavalier.h"

void IO_Handler::initSDL() {

    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("Dradegon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth,windowHeight,
                     SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);

    if (!window) {
        std::cerr << "Error: Unable to create window!" << SDL_GetError() << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        std::cerr << "Error: Unable to create renderer!" << SDL_GetError() << std::endl;
        return;
    }

}


void IO_Handler::initCells() {
    for(int i = 0; i < numberOfCells; i++){
        cells.push_back(std::make_shared<Cell>(i));
    }
}


void IO_Handler::initUI() {
    int boardWidth = 1010;
    int boardHeight = 1010;
    boardUI = std::make_shared<BoardUI>(renderer, boardWidth,boardHeight);

    int cellWidth = 90;
    int cellHeight = 90;
    int cellBorderSize = 10;
    int x = cellBorderSize;
    int y = cellBorderSize;

    for(int i = 0; i < numberOfCells; i++){
        boardCellsUI.push_back(std::make_shared<CellUI>(renderer,cells[i], cellWidth, cellHeight, x, y));

        if( x + cellWidth + cellBorderSize >= boardWidth){
            y = y + cellHeight + cellBorderSize;
            x = cellBorderSize;
        } else {
            x = x + cellWidth + cellBorderSize;
        }
    }
}

void IO_Handler::run() {

    while(isRunning){
        handleEvent();
        togglePanels();
        display();
        SDL_Delay(25);
    }
}

void IO_Handler::handleEvent() {

    while (SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE){
            isRunning = false;
        }
        if(event.button.type == SDL_MOUSEBUTTONDOWN){
            handleClick(event.button);
        }
        if(event.type == SDL_MOUSEMOTION){
            handleHover(event.motion);
        }
    }
}

void IO_Handler::handleClick(const SDL_MouseButtonEvent &click) {
    SDL_Point point{click.x, click.y};
    int index = 0;

    for (auto &cell : boardCellsUI) {
        if (SDL_PointInRect(&point, &cell->cellRect) == SDL_TRUE){
            if(currentCellIndex >= 0){
                cells[currentCellIndex]->isClicked = false;
            }
            currentCellIndex = index;
            cells[currentCellIndex]->isClicked = true;

            decideClickHandlePhase();
            break;
        }
        index++;
    }
}

void IO_Handler::decideClickHandlePhase() {
    if (gameLogic->getRedPlayer()->getIsReady() && gameLogic->getBluePlayer()->getIsReady()) {
        handleClickInGamePhase();
    } else {
        handleClickInBuyPhase();
    }
}

void IO_Handler::handleClickInBuyPhase() {
    if (shopPanel->getSelectedFigure() != nullptr) {
        gameLogic->setTargetCell(cells[currentCellIndex]);
        shopPanel->buyFigure();
    }
}

void IO_Handler::handleClickInGamePhase() {
    if (gameLogic->getCurrentlySelectedFigure()) {
        gameLogic->setTargetCell(cells[currentCellIndex]);
        gameLogic->handleAction();
    } else {
        if (cells[currentCellIndex]->getFigureOnCell() != nullptr &&
            gameLogic->getCurrentPlayer()->getColor() == cells[currentCellIndex]->getFigureOnCell()->getPlayerColor() &&
            cells[currentCellIndex]->getFigureOnCell()->getMovement() > 0) {
            gameLogic->setFigureToMove(cells[currentCellIndex]);
        }
    }
}


void IO_Handler::handleHover(SDL_MouseMotionEvent motion) {
    Sint32 mouseX = motion.x;
    Sint32 mouseY = motion.y;

    int index = 0;

    for (auto &cell : boardCellsUI) {
        if((cell->cellRect.x < mouseX) && (cell->cellRect.w + cell->cellRect.x > mouseX) &&
                (cell->cellRect.y < mouseY) && (cell->cellRect.h + cell->cellRect.y > mouseY)){
            //std::cout << std::to_string(index) << std::endl;
            if (cells[index]->getFigureOnCell() != nullptr) {
                infoPanel->setCurrentFigureInfo(cells[index]->getFigureOnCell());

                //Write the figure's name in the console
                std::cout << infoPanel->getCurrentFigureInfo()->name << std::endl;
                std::cout << infoPanel->getCurrentFigureInfo()->currentHp << std::endl;
                std::cout << infoPanel->getCurrentFigureInfo()->color << std::endl;
            }
            break;
        }
        index++;
    }
}

void IO_Handler::display() {
    SDL_RenderClear(renderer);

    boardUI->print(renderer);

    for(const std::shared_ptr<CellUI>& cell : boardCellsUI){
        cell->print(renderer);
    }

    SDL_RenderPresent(renderer);
}

void IO_Handler::initLogic() {
    gameLogic = std::make_shared<GameLogic>(GameLogic());
    infoPanel = std::make_shared<InfoPanel>(InfoPanel(gameLogic));
    shopPanel = std::make_shared<ShopPanel>(ShopPanel(gameLogic));
    currentPanel = shopPanel;

    //add figures and set players' readiness to true for testing
    initFigures();
    gameLogic->getBluePlayer()->setReady();
    gameLogic->getRedPlayer()->setReady();
}

void IO_Handler::initFigures() {
    initRedFigures();
    initBlueFigures();
}

void IO_Handler::initBlueFigures() {
    for (int i = 70; i < 80; i++) {
        cells[i]->addFigureToCell(std::make_shared<Peasant>(Peasant(BLUE)));
    }
    cells[99]->addFigureToCell(std::make_shared<Archer>(Archer(BLUE)));
    cells[98]->addFigureToCell(std::make_shared<Artificer>(Artificer(BLUE)));
    cells[97]->addFigureToCell(std::make_shared<Paladin>(Paladin(BLUE)));
    cells[96]->addFigureToCell(std::make_shared<Wall>(Wall(BLUE)));
    cells[95]->addFigureToCell(std::make_shared<King>(King(BLUE)));
    cells[94]->addFigureToCell(std::make_shared<Wall>(Wall(BLUE)));
    cells[93]->addFigureToCell(std::make_shared<BabyDragon>(BabyDragon(BLUE)));
    cells[92]->addFigureToCell(std::make_shared<Vampire>(Vampire(BLUE)));
    cells[91]->addFigureToCell(std::make_shared<Artificer>(Artificer(BLUE)));
    cells[90]->addFigureToCell(std::make_shared<Archer>(Archer(BLUE)));
    cells[89]->addFigureToCell(std::make_shared<Archer>(Archer(BLUE)));
    cells[88]->addFigureToCell(std::make_shared<Sorcerer>(Sorcerer(BLUE)));
    cells[87]->addFigureToCell(std::make_shared<Marauder>(Marauder(BLUE)));
    cells[86]->addFigureToCell(std::make_shared<Cleric>(Cleric(BLUE)));
    cells[85]->addFigureToCell(std::make_shared<Wall>(Wall(BLUE)));
    cells[84]->addFigureToCell(std::make_shared<Knight>(Knight(BLUE)));
    cells[83]->addFigureToCell(std::make_shared<Cavalier>(Cavalier(BLUE)));
    cells[82]->addFigureToCell(std::make_shared<Marauder>(Marauder(BLUE)));
    cells[81]->addFigureToCell(std::make_shared<Sorcerer>(Sorcerer(BLUE)));
    cells[80]->addFigureToCell(std::make_shared<Archer>(Archer(BLUE)));

    for (int i = 70; i < 100; i++) {
        gameLogic->getBluePlayer()->addFigure(cells[i]->getFigureOnCell());
    }
}

void IO_Handler::initRedFigures() {
    cells[0]->addFigureToCell(std::make_shared<Archer>(Archer(RED)));
    cells[1]->addFigureToCell(std::make_shared<Artificer>(Artificer(RED)));
    cells[2]->addFigureToCell(std::make_shared<Paladin>(Paladin(RED)));
    cells[3]->addFigureToCell(std::make_shared<Wall>(Wall(RED)));
    cells[4]->addFigureToCell(std::make_shared<King>(King(RED)));
    cells[5]->addFigureToCell(std::make_shared<Wall>(Wall(RED)));
    cells[6]->addFigureToCell(std::make_shared<BabyDragon>(BabyDragon(RED)));
    cells[7]->addFigureToCell(std::make_shared<Vampire>(Vampire(RED)));
    cells[8]->addFigureToCell(std::make_shared<Artificer>(Artificer(RED)));
    cells[9]->addFigureToCell(std::make_shared<Archer>(Archer(RED)));
    cells[10]->addFigureToCell(std::make_shared<Archer>(Archer(RED)));
    cells[11]->addFigureToCell(std::make_shared<Sorcerer>(Sorcerer(RED)));
    cells[12]->addFigureToCell(std::make_shared<Marauder>(Marauder(RED)));
    cells[13]->addFigureToCell(std::make_shared<Cleric>(Cleric(RED)));
    cells[14]->addFigureToCell(std::make_shared<Wall>(Wall(RED)));
    cells[15]->addFigureToCell(std::make_shared<Knight>(Knight(RED)));
    cells[16]->addFigureToCell(std::make_shared<Cavalier>(Cavalier(RED)));
    cells[17]->addFigureToCell(std::make_shared<Marauder>(Marauder(RED)));
    cells[18]->addFigureToCell(std::make_shared<Sorcerer>(Sorcerer(RED)));
    cells[19]->addFigureToCell(std::make_shared<Archer>(Archer(RED)));
    for (int i = 20; i < 30; i++) {
        cells[i]->addFigureToCell(std::make_shared<Peasant>(Peasant(RED)));
    }

    for (int i = 0; i < 30; i++) {
        gameLogic->getRedPlayer()->addFigure(cells[i]->getFigureOnCell());
    }
}

void IO_Handler::togglePanels() {
    if (gameLogic->getBluePlayer()->getIsReady() && gameLogic->getRedPlayer()->getIsReady()) {
        currentPanel = infoPanel;
    } else {
        currentPanel = shopPanel;
    }
}



