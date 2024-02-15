//
// Created by AsusTuf on 2024. 02. 12..
//

#include "Vampire.h"
void Vampire::attack(const std::shared_ptr<Figure> &target) {
  if (target->isNotResistant(shared_from_this())) {
    currentHp -= damage;
  }
  target->defend(shared_from_this());
}
