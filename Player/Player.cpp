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

void Player::removeFigure(const std::shared_ptr<Figure>& figure) {
    figures.erase(std::remove(figures.begin(), figures.end(), figure), figures.end());
}

std::vector<std::shared_ptr<Figure>> Player::getFigures() {
    return figures;
}

bool Player::isKingDefeatedOrLastFigure() {
    bool isKingDead = checkIfKingIsDefeated();
    bool onlyKingAndWallsLive = checkIfKingAndWallsRemainOnly();
    return isKingDead || onlyKingAndWallsLive;
}

bool Player::checkIfKingAndWallsRemainOnly() {
    bool onlyKingAndWallsRemain = true;
    for(const std::shared_ptr<Figure>& figure : figures) {
        if (figure->getStats().name != GetFigureNameText(KING) || figure->getStats().name != GetFigureNameText(WALL)) {
             onlyKingAndWallsRemain = false;
        }
    }
    return onlyKingAndWallsRemain;
}

bool Player::checkIfKingIsDefeated() {
    bool kingDefeated = true;
    for(const std::shared_ptr<Figure>& figure : figures) {
        if (figure->getStats().name == GetFigureNameText(KING)) {
            kingDefeated = false;
        }
    }
    return kingDefeated;
}
