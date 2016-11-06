//
//  Player.hpp
//

#pragma once

#include <stdio.h>
#include <string>

#include "Die.hpp"
#include "GameBoard.hpp"

using namespace std;

class Player {
public:
   Player() : playerName("no name"), position(0), die() {}
   
   Player(string name) {
      playerName = name;
      position = 0;
   }
   
   Player(const Player &p) {
      setName(p.playerName);
      setPostion(p.getPostion());
      die = p.die;
   }
   
   Player& operator=(const Player& p);
   
   ~Player() { }
   
   void setName(string name) { playerName = name; }
   void setPostion(int location) { position = location; }
   string getName() const { return playerName; }
   int getPostion() const { return position; }
   Die getDie() { return die; }
   
   int rollDieAndMove();
private:
   string playerName;
   int position;
   Die die;
};
