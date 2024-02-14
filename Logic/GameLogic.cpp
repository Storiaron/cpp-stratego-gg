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

void GameLogic::setSelectedFigure(std::shared_ptr<Figure> figure) {
    selectedFigure = std::move(figure);
}

void GameLogic::setSelectedCell(std::shared_ptr<Cell> cell) {
    selectedCell = std::move(cell);
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
    if (selectedFigure->getMovement() > 0 && selectedCell->getFigureOnCell() == nullptr) {
        previouslySelectedCell->removeFigureFromCell();
        selectedCell->addFigureToCell(selectedFigure);
        return true;
    } else if (selectedCell->getFigureOnCell() != nullptr) {
        selectedFigure->attack(selectedCell->getFigureOnCell());
        return true;
    }
    return false;
}

std::shared_ptr<Cell> GameLogic::getSelectedCell() {
    return selectedCell;
}
