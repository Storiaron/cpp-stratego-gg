//
// Created by AsusTuf on 2024. 02. 12..
//

#include "IO_Handler.h"

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
            if (gameLogic->getCurrentlySelectedFigure()) {
                gameLogic->setTargetCell(cells[currentCellIndex]);
            } else {
                gameLogic->setFigureToMove(cells[currentCellIndex]);
            }
            break;
        }
        index++;
    }
}



void IO_Handler::handleHover(SDL_MouseMotionEvent motion) {
    Sint32 mouseX = motion.x;
    Sint32 mouseY = motion.y;

    int index = 0;

    for (auto &cell : boardCellsUI) {
        if((cell->cellRect.x < mouseX) && (cell->cellRect.w + cell->cellRect.x > mouseX) &&
                (cell->cellRect.y < mouseY) && (cell->cellRect.h + cell->cellRect.y > mouseY)){
            std::cout << std::to_string(index) << std::endl;
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
}



