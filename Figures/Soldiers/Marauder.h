//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class Marauder : public Figure {
public:
    explicit Marauder(PlayerColor color) : Figure(FigureName::MARAUDER, 20, -7, 1, 1, 1, 20, {AttackType::MELEE}, AttackType::NONE, color){};
};
