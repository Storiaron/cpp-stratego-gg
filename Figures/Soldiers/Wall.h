//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class Wall : public Figure {
public:
    explicit Wall(PlayerColor color) : Figure("Wall", 1, 0, 0, 0, 0, 20, {AttackType::NONE}, AttackType::NONE, color){};
};

//TODO: IMMUNE TO ALL BUT ARTIFICER