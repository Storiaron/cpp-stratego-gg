//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class Paladin : public Figure {
public:
    explicit Paladin(PlayerColor color) : Figure(FigureName::PALADIN, 35, -10, 1, 1, 1, 80, {AttackType::MELEE, AttackType::HEAL}, AttackType::LIFESTEAL, color){};
    void attack(const std::shared_ptr<Figure> &target) override;

};