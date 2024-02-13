//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class Knight : public Figure {
public:
    explicit Knight(PlayerColor color) : Figure(FigureName::KNIGHT, 25, -10, 1, 1, 1, 50, {AttackType::MELEE}, AttackType::LIFESTEAL, color){};
};


//TODO: RETALIATION!!