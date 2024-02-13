//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class Cleric : public Figure {
public:
    explicit Cleric(PlayerColor color) : Figure(FigureName::CLERIC, 10, +5, 1, 1, 1, 50, {AttackType::HEAL}, AttackType::NONE, color){};
};
