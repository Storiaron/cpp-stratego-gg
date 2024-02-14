//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class Cavalier : public Figure {
public:
    explicit Cavalier(PlayerColor color) : Figure(FigureName::CAVALIER, 20, -15, 3, 1, 1, 40, {AttackType::MELEE}, AttackType::NONE, color){};
};
