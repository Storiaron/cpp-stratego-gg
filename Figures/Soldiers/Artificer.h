//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class Artificer : public Figure {
public:
    explicit Artificer(PlayerColor color) : Figure("Artificer", 10, -5, 1, 1, 1, 25, {AttackType::MELEE}, AttackType::RANGE, color){};
};
