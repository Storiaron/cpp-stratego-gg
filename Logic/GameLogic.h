//
// Created by AsusTuf on 2024. 02. 13..
//

#pragma once


#include "Cell.h"
#include "../Player/Player.h"

class GameLogic {
public:
    GameLogic();
    ~GameLogic();
    void toggleCurrentPlayer();
    std::shared_ptr<Player> getCurrentPlayer();
    void setSelectedFigure(std::shared_ptr<Figure> figure);
    void setSelectedCell(std::shared_ptr<Cell> cell);
    void moveOrAttack();

private:
    void initializeBoard();
    std::shared_ptr<Cell> selectedCell = nullptr;
    std::shared_ptr<Figure> selectedFigure = nullptr;
    std::shared_ptr<Cell> previouslySelectedCell = nullptr;
    Player redPlayer{(PlayerColor::RED)};
    Player bluePlayer{(PlayerColor::BLUE)};
    std::shared_ptr<Player> currentPlayer;
    //std::shared_ptr<Cell> board{new Cell[100]};
    //std::shared_ptr<Cell> redAvailableCells{new Cell[30]};
    //std::shared_ptr<Cell> blueAvailableCells{new Cell[30]};
};
