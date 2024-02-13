//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class Archer : public Figure {
public:
    explicit Archer(PlayerColor color) : Figure("Archer", 10, -5, 2, 2, 4, 30, {AttackType::RANGE}, AttackType::NONE, color){};
};
