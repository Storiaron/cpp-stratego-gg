//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class BabyDragon : public Figure {
public:
    explicit BabyDragon(PlayerColor color) : Figure("BabyDragon", 50, -15, 1, 1, 3, 100, {AttackType::RANGE}, AttackType::NONE, color){};
};


//TODO: FRIENDLY FIRE!!