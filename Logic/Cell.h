//
// Created by AsusTuf on 2024. 02. 13..
//

#pragma once
#include "../Figures/Figure.h"


class Cell {
public:
    Cell() = default;
    Cell(int x, int y, int pixelSize);
    ~Cell();
    void removeFigureFromCell();
    void addFigureToCell(std::shared_ptr<Figure> figure);
    std::shared_ptr<Figure> getFigureOnCell();

private:
    std::shared_ptr<Figure> figure = nullptr;
    int x{0};
    int y{0};
};
