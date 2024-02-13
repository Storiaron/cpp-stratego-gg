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


class Figure
        : public std::enable_shared_from_this<Figure> {
public:
    Figure(const std::string& name, int currentHp, int damage, int movement,
           int minAttackRange, int maxAttackRange, int price,
           std::vector<AttackType> attackTypes,
           AttackType resistance, PlayerColor color);
    virtual void attack(const std::shared_ptr<Figure>& target);
    virtual void defend(const std::shared_ptr<Figure>& attacker);
    int getPrice() const;
    int getMovement() const;
    int getDamage() const;
    std::vector<AttackType> getAttackTypes() const;
    FigureStats getStats();
    bool isWithinAtkRange(int range) const;
    bool isWithinMovementRange(int range) const;

protected:
    FigureStats stats;
    std::string name;
    int currentHp;
    int damage;
    int movement;
    int minAttackRange;
    int maxAttackRange;
    int price;
    std::vector<AttackType> attackTypes;
    AttackType resistance;
    PlayerColor color;

    void initializeStats();
    void updateCurrentHpStat();
};
