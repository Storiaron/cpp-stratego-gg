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

void Player::addFigure(std::shared_ptr<Figure> figure) {
    figures.push_back(figure);
}

PlayerColor Player::getColor() {
    return color;
}

bool Player::getIsReady() {
    return isReady;
}

void Player::setReady() {
    isReady = true;
}
