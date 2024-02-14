//
// Created by AsusTuf on 2024. 02. 13..
//

#include "GameLogic.h"

#include <utility>
#include <iostream>

GameLogic::~GameLogic() {
}

GameLogic::GameLogic() {
    redPlayer = std::make_shared<Player>(Player(PlayerColor::RED));
    bluePlayer = std::make_shared<Player>(Player(PlayerColor::BLUE));
    currentPlayer = redPlayer;
    initializeBoard();
}

void GameLogic::toggleCurrentPlayer() {
    if (currentPlayer->getColor() == PlayerColor::BLUE) {
        currentPlayer = redPlayer;
    } else {
        currentPlayer = bluePlayer;
    }
}

std::shared_ptr<Player> GameLogic::getCurrentPlayer() {
    return currentPlayer;
}

bool GameLogic::setFigureToMove(std::shared_ptr<Cell> cell) {
    if (cell->getFigureOnCell() != nullptr) {
        figureToMove = cell->getFigureOnCell();
        cellWithFigureToMove = std::move(cell);
        isAFigureCurrentlySelected = true;
        return true;
    }
    return false;
}

void GameLogic::setTargetCell(std::shared_ptr<Cell> cell) {
    targetCell = std::move(cell);
}

void GameLogic::initializeBoard() {
//    std::vector<Cell> cells = {};
//
//    for (int x = 0; x < 10; x++) {
//        for (int y = 0; y < 10; y++) {
//            Cell cell(x, y, 20);
//            cells.push_back(cell);
//        }
//    }
//
//    for (int i = 0; i < cells.size(); i++) {
//        board.get()[i] = cells[i];
//        if (i < 30) {
//            redAvailableCells.get()[i] = cells[i];
//        }
//        if (i > 69) {
//            blueAvailableCells.get()[i-70] = cells[i];
//        }
//    }
}

void GameLogic::moveOrAttack() {
    if (figureToMove->getMovement() > 0 && targetCell->getFigureOnCell() == nullptr) {
        cellWithFigureToMove->removeFigureFromCell();
        targetCell->addFigureToCell(figureToMove);
    } else if (targetCell->getFigureOnCell() != nullptr) {
        figureToMove->attack(targetCell->getFigureOnCell());
        if (targetCell->getFigureOnCell()->getIsDead()) {
            targetCell->removeFigureFromCell();
        }
    }
    isAFigureCurrentlySelected = false;
}

std::shared_ptr<Cell> GameLogic::getSelectedCell() {
    return targetCell;
}

bool GameLogic::getCurrentlySelectedFigure() {
    return isAFigureCurrentlySelected;
}

std::shared_ptr<Player> GameLogic::getRedPlayer() {
    return redPlayer;
}

std::shared_ptr<Player> GameLogic::getBluePlayer() {
    return bluePlayer;
}

