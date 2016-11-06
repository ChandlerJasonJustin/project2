//
//  Player.cpp
//

#include "Player.hpp"

Player& Player::operator=(const Player& p) {
      this->setName(p.playerName);
      this->setPostion(p.getPostion());
      this->die = p.die;
      return *this;
}

int Player::rollDieAndMove() {
   this->die.roll();
   if ((this->getPostion() + this->die.getFaceValue()) <= 100) this->setPostion(this->getPostion() + this->die.getFaceValue());
   return this->getPostion();
}
