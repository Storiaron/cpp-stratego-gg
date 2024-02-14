//
// Created by AsusTuf on 2024. 02. 13..
//

#include "GameLogic.h"

#include <utility>

GameLogic::~GameLogic() {
}

GameLogic::GameLogic() {
    currentPlayer = std::make_shared<Player>(redPlayer);
    initializeBoard();
}

void GameLogic::toggleCurrentPlayer() {
    if (currentPlayer->getColor() == PlayerColor::BLUE) {
        currentPlayer = std::make_shared<Player>(redPlayer);
    } else {
        currentPlayer = std::make_shared<Player>(bluePlayer);
    }
}

std::shared_ptr<Player> GameLogic::getCurrentPlayer() {
    return currentPlayer;
}

void GameLogic::setFigureToMove(std::shared_ptr<Figure> figure, std::shared_ptr<Cell> cell) {
    selectedFigureToMove = std::move(figure);
    selectedCellWithFigureToMove = std::move(cell);
}

void GameLogic::setTargetCell(std::shared_ptr<Cell> cell) {
    targetCell = std::move(cell);
}

void GameLogic::initializeBoard() {
    std::vector<Cell> cells = {};

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            Cell cell(x, y, 20);
            cells.push_back(cell);
        }
    }

    for (int i = 0; i < cells.size(); i++) {
        board.get()[i] = cells[i];
        if (i < 30) {
            redAvailableCells.get()[i] = cells[i];
        }
        if (i > 69) {
            blueAvailableCells.get()[i-70] = cells[i];
        }
    }
}

bool GameLogic::moveOrAttack() {
    if (selectedFigureToMove->getMovement() > 0 && targetCell->getFigureOnCell() == nullptr) {
        selectedCellWithFigureToMove->removeFigureFromCell();
        targetCell->addFigureToCell(selectedFigureToMove);
        return true;
    } else if (targetCell->getFigureOnCell() != nullptr) {
        selectedFigureToMove->attack(targetCell->getFigureOnCell());
        return true;
    }
    return false;
}

std::shared_ptr<Cell> GameLogic::getSelectedCell() {
    return targetCell;
}
