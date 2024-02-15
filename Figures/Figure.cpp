//
// Created by AsusTuf on 2024. 02. 12..
//

#include "Figure.h"

#include <utility>

Figure::Figure(FigureName name, int currentHp, int damage, int movement, int minAttackRange, int maxAttackRange,
               int price, std::vector<AttackType> attackTypes, AttackType resistance, PlayerColor color) {
    this->name = name;
    this->currentHp = currentHp;
    this->damage = damage;
    this->movement = movement;
    this->minAttackRange = minAttackRange;
    this->maxAttackRange = maxAttackRange;
    this->price = price;
    this->attackTypes = std::move(attackTypes);
    this->resistance = resistance;
    this->color = color;

    initializeStats();
}

void Figure::attack(const std::shared_ptr<Figure>& target) {
    target->defend(shared_from_this());
}

void Figure::defend(const std::shared_ptr<Figure>& attacker) {
    if (isNotResistant(attacker)) {
        this->currentHp += attacker->getDamage();
        if (currentHp <= 0) {
            isDead = true;
        }
    }
}

int Figure::getPrice() const {
    return price;
}

int Figure::getMovement() const {
    return movement;
}

int Figure::getDamage() const {
    return damage;
}

bool Figure::isWithinAtkRange(int range) const {
    return minAttackRange <= range && range <= maxAttackRange;
}

std::vector<AttackType> Figure::getAttackTypes() const {
    return attackTypes;
}

FigureStats Figure::getStats() {
    updateCurrentHpStat();
    return stats;
}

void Figure::updateCurrentHpStat() {
    stats.currentHp = std::to_string(currentHp);
}

void Figure::initializeStats() {
    stats.name = GetFigureNameText(name);
    stats.currentHp = std::to_string(currentHp);
    stats.damage = std::to_string(damage);
    stats.resistance = GetAttackTypeText(resistance);
    stats.minAttackRange = std::to_string(minAttackRange);
    stats.maxAttackRange = std::to_string(maxAttackRange);
    stats.movement = std::to_string(movement);
    stats.price = std::to_string(price);
    stats.color = GetPlayerColorText(color);
    stats.attackTypes = "";
    for(int i = 0; i < attackTypes.size(); i++) {
        stats.attackTypes += GetAttackTypeText(attackTypes[i]);
        if (i != attackTypes.size() - 1) {
            stats.attackTypes += ", ";
        }
    }
}

bool Figure::isWithinMovementRange(int range) const {
    return range <= movement;
}

FigureName Figure::getName() const {
    return name;
}

bool Figure::getIsDead() {
    return isDead;
}

