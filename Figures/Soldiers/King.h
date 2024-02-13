//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class King : public Figure {
public:
    explicit King(PlayerColor color) : Figure(FigureName::KING, 100, 0, 1, 0, 0, 0, {AttackType::NONE}, AttackType::HEAL, color){};
};
