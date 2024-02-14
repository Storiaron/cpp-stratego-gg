//
// Created by AsusTuf on 2024. 02. 12..
//

#include "Paladin.h"
void Paladin::attack(const std::shared_ptr<Figure> &target) {
  if(target->getPlayerColor() == color) {
    damage = 7;
  }
  else {
    damage = -10;
  }
  target->defend(shared_from_this());
}
