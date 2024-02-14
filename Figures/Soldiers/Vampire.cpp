//
// Created by AsusTuf on 2024. 02. 12..
//

#include "Vampire.h"
void Vampire::attack(const std::shared_ptr<Figure> &target) {
  if ( std::find(attackTypes.begin(), attackTypes.end(), target->getResistance()) != attackTypes.end()) {
    currentHp += damage;
  }
  target->defend(shared_from_this());
}
