//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class Sorcerer : public Figure {
public:
    explicit Sorcerer(PlayerColor color) : Figure(FigureName::SORCERER, 5, -10, 1, 1, 3, 30, {AttackType::RANGE}, AttackType::NONE, color){};
};
