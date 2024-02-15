//
// Created by AsusTuf on 2024. 02. 12..
//

#include "IO_Handler.h"
#include "Figures/Soldiers/Peasant.h"
#include "Figures/Soldiers/Artificer.h"
#include "Figures/Soldiers/Marauder.h"

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
    panelUI = std::make_shared<PanelLayerUI>(renderer, layerWidth, windowHeight,0,0);
    boardUI = std::make_shared<BoardUI>(renderer, boardWidth,windowHeight, layerWidth,0);
    shopButton = std::make_shared<ButtonUI>(renderer, 200,40, layerWidth * 0.1, windowHeight * 0.85);

    int cellWidth = 90;
    int cellHeight = 90;
    int cellBorderSize = 10;
    int x = cellBorderSize + layerWidth;
    int y = cellBorderSize;

    for(int i = 0; i < numberOfCells; i++){
        boardCellsUI.push_back(std::make_shared<CellUI>(renderer,cells[i], cellWidth, cellHeight, x, y));

        if( x + cellWidth + cellBorderSize >= boardWidth + layerWidth){
            y = y + cellHeight + cellBorderSize;
            x = cellBorderSize + layerWidth;
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
                cells[currentCellIndex]->isSelected = false;
            }
            currentCellIndex = index;
            cells[currentCellIndex]->isSelected = true;

            //Set shop's selected figure to test whether we can place a figure on board or not
            shopPanel->setSelectedFigure(std::make_shared<Artificer>(Artificer(PlayerColor::NO_COLOR)));

            decideClickHandlePhase();
            break;
        }
        index++;
    }

    if(SDL_PointInRect(&point, &shopButton->buttonRect) == SDL_TRUE){
        shopButton->isClicked = true;
    } else {
        if(shopButton->isClicked){
            shopButton->isClicked = false;
        }
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
        gameLogic->moveOrAttack();
    } else {
        gameLogic->setFigureToMove(cells[currentCellIndex]);
    }
}


void IO_Handler::handleHover(SDL_MouseMotionEvent motion) {
    Sint32 mouseX = motion.x;
    Sint32 mouseY = motion.y;

    int index = 0;

    for (std::shared_ptr<CellUI> &cell : boardCellsUI) {
        if((cell->cellRect.x < mouseX) && (cell->cellRect.w + cell->cellRect.x > mouseX) &&
                (cell->cellRect.y < mouseY) && (cell->cellRect.h + cell->cellRect.y > mouseY)){
            cells[index]->isHovered = true;
            if (cells[index]->getFigureOnCell() != nullptr) {
                infoPanel->setCurrentFigureInfo(cells[index]->getFigureOnCell());

                //Write the figure's name in the console
                std::cout << infoPanel->getCurrentFigureInfo()->name << std::endl;
                std::cout << infoPanel->getCurrentFigureInfo()->currentHp << std::endl;
            }
        } else {
            if(cells[index]->isHovered){
                cells[index]->isHovered = false;
            }
        }
        index++;
    }

    if((shopButton->buttonRect.x < mouseX) && (shopButton->buttonRect.w + shopButton->buttonRect.x > mouseX) &&
       (shopButton->buttonRect.y < mouseY) && (shopButton->buttonRect.h + shopButton->buttonRect.y > mouseY)){
        shopButton->isHovered = true;
    } else {
        if(shopButton->isHovered){
            shopButton->isHovered = false;
        }
    }
}

void IO_Handler::display() {
    SDL_RenderClear(renderer);

    panelUI->print(renderer);
    boardUI->print(renderer);
    shopButton->print(renderer);

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
    cells[0]->addFigureToCell(std::make_shared<Peasant>(Peasant(RED)));
    cells[1]->addFigureToCell(std::make_shared<Marauder>(Marauder(BLUE)));
    gameLogic->getBluePlayer()->setReady();
    gameLogic->getRedPlayer()->setReady();
}

void IO_Handler::togglePanels() {
    if (gameLogic->getBluePlayer()->getIsReady() && gameLogic->getRedPlayer()->getIsReady()) {
        currentPanel = infoPanel;
    } else {
        currentPanel = shopPanel;
    }
}



