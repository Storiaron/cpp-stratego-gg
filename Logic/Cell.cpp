//
// Created by AsusTuf on 2024. 02. 13..
//

#include "Cell.h"

#include <utility>

void Cell::removeFigureFromCell() {
    this->figure = nullptr;
}

void Cell::addFigureToCell(std::shared_ptr<Figure> figureToAdd) {
    this->figure = std::move(figureToAdd);
}

Cell::Cell(int x, int y, int pixelSize) {
    this->x = x;
    this->y = y;
}

std::shared_ptr<Figure> Cell::getFigureOnCell() {
    return figure;
}
