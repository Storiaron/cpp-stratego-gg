//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once


#include "../Figures/Figure.h"

class Player {
public:
    Player(PlayerColor color);
    void spendGold(int amount);
    bool canGoldBeSpent(int amount) const;
    void addFigure(const Figure& figure);
    PlayerColor getColor();

private:
    std::vector<Figure> figures;
    PlayerColor color;
    int gold = 350;
};
