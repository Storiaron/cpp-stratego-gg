//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once
#include "../Figure.h"

class Vampire : public Figure {
public:
    explicit Vampire(PlayerColor color) : Figure(FigureName::VAMPIRE, 35, -3, 1, 1, 1, 20, {AttackType::LIFESTEAL}, AttackType::HEAL, color){};
    void attack(const std::shared_ptr<Figure> &target) override;
};
