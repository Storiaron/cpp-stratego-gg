//
// Created by AsusTuf on 2024. 02. 12..
//

#pragma once

#include <string>
#include <vector>
#include <memory>
#include "../Enums/AttackType.h"
#include "../Enums/PlayerColor.h"
#include "FigureStats.h"
#include "../Enums/FigureName.h"


class Figure
        : public std::enable_shared_from_this<Figure> {
public:
    Figure() = default;
    Figure(FigureName name, int currentHp, int damage, int movement,
           int minAttackRange, int maxAttackRange, int price,
           std::vector<AttackType> attackTypes,
           AttackType resistance, PlayerColor color);
    virtual void attack(const std::shared_ptr<Figure>& target);
    virtual void defend(const std::shared_ptr<Figure>& attacker);
    int getPrice() const;
    int getMovement() const;
    int getDamage() const;
    FigureName getName() const;
    std::vector<AttackType> getAttackTypes() const;
    FigureStats getStats();
    bool isWithinAtkRange(int range) const;
    bool isWithinMovementRange(int range) const;
    bool getIsDead();

protected:
    FigureStats stats;
    FigureName name{};
    int currentHp{0};
    int damage{0};
    int movement{0};
    int minAttackRange{0};
    int maxAttackRange{0};
    int price{0};
    std::vector<AttackType> attackTypes{};
    AttackType resistance{};
    PlayerColor color{};

    bool isDead{false};

    void initializeStats();
    void updateCurrentHpStat();
};
