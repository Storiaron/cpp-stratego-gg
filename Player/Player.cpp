//
// Created by AsusTuf on 2024. 02. 12..
//

#include "Player.h"

Player::Player(PlayerColor color) {
    this->color = color;
}

void Player::spendGold(int amount) {
    if (canGoldBeSpent(amount)) {
        gold -= amount;
    }
}

bool Player::canGoldBeSpent(int amount) const {
    return gold >= amount;
}

void Player::addFigure(const Figure& figure) {
    figures.push_back(figure);
}

PlayerColor Player::getColor() {
    return color;
}
