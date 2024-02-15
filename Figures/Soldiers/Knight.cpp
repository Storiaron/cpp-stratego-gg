//
// Created by AsusTuf on 2024. 02. 12..
//

#include "Knight.h"
void Knight::defend(const std::shared_ptr<Figure> &attacker) {
  if(isResistant(attacker)) {
    currentHp += attacker->getDamage();
  }
  attacker->defend(shared_from_this());
}
