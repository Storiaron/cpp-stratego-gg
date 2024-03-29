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
    bool setFigureToMove(std::shared_ptr<Cell> cell);
    void setTargetCell(std::shared_ptr<Cell> cell);
    std::string handleAction();
    void move();
    void attack();
    int calculateCellDistance();
    bool getCurrentlySelectedFigure();
    std::shared_ptr<Player> getRedPlayer();
    std::shared_ptr<Player> getBluePlayer();
    std::shared_ptr<Cell> getSelectedCell();
    int checkIfAPlayerHasWon();

private:
    void initializeBoard();
    int bluePlayerWin{2};
    int redPlayerWin{1};
    int noPlayerWin{0};
    std::shared_ptr<Cell> targetCell = nullptr;
    std::shared_ptr<Figure> figureToMove = nullptr;
    std::shared_ptr<Cell> cellWithFigureToMove = nullptr;
    bool isAFigureCurrentlySelected{false};
    std::shared_ptr<Player> redPlayer;
    std::shared_ptr<Player> bluePlayer;
    std::shared_ptr<Player> currentPlayer;
    std::shared_ptr<Player> otherPlayer;
    //std::shared_ptr<Cell> board{new Cell[100]};
    //std::shared_ptr<Cell> redAvailableCells{new Cell[30]};
    //std::shared_ptr<Cell> blueAvailableCells{new Cell[30]};

};
