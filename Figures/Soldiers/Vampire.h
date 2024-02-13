//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class Vampire : public Figure {
public:
    explicit Vampire(PlayerColor color) : Figure("Vampire", 35, -3, 1, 1, 1, 20, {AttackType::LIFESTEAL}, AttackType::HEAL, color){};
};
