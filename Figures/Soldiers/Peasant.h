//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class Peasant : public Figure {
public:
    explicit Peasant(PlayerColor color) : Figure("Peasant", 10, -5, 1, 1, 1, 5, {AttackType::MELEE}, AttackType::NONE, color){};
};
