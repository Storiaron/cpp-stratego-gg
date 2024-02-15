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
    void addFigure(std::shared_ptr<Figure> figure);
    void setReady();
    bool getIsReady();
    PlayerColor getColor();

private:
    std::vector<std::shared_ptr<Figure>> figures;
    PlayerColor color;
    bool isReady{false};
    int gold = 350;
};
