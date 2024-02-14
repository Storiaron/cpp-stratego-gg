//
// Created by AsusTuf on 2024. 02. 13..
//

#pragma once
#include "../Figures/Figure.h"
#include <SDL.h>

class Cell {
public:
    Cell(int index) :
    cellIndex(index)
    {};

    bool isClicked{false};

    void removeFigureFromCell();
    void addFigureToCell(std::shared_ptr<Figure> figure);
    std::shared_ptr<Figure> getFigureOnCell();

private:
    std::shared_ptr<Figure> figure = nullptr;
    int cellIndex;
};
