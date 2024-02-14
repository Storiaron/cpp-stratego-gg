//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class Paladin : public Figure {
public:
    explicit Paladin(PlayerColor color) : Figure("Paladin", 35, -10, 1, 1, 1, 80, {AttackType::MELEE, AttackType::HEAL}, AttackType::LIFESTEAL, color){};
};


//TODO: TOGGLE BETWEEN ATK=-10 (FOR ENEMY) AND ATK=7 (FOR ALLY) DEPENDING ON WHO IS BEING TARGETED