//
//  ChutesAndLaddersGame.cpp
//

#include <iostream>
#include <string>

#include "ChutesAndLaddersGame.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;


ChutesAndLaddersGame::ChutesAndLaddersGame(int nPlayers) : winner("no winner") 
{
   playerQueue = new ArrayQueue<Player>(nPlayers);
   Jason = new Player("Jason Chandler");
   Justin = new Player("Justin Chandler");
   playerQueue->enqueue(*Jason);
   playerQueue->enqueue(*Justin);
}


ChutesAndLaddersGame::~ChutesAndLaddersGame() 
{      
   while(!(playerQueue->empty()))
      {
         playerQueue->dequeue();
      }
   delete playerQueue;
   delete Jason;
   delete Justin;
}


void ChutesAndLaddersGame::resetGame() {
      while(!(playerQueue->empty()))
   {
      playerQueue->dequeue();
   }
   winner = "no winner";
   Jason->setPostion(0);
   Justin->setPostion(0);
   playerQueue->enqueue(*Jason);
   playerQueue->enqueue(*Justin);
}


void ChutesAndLaddersGame::playGame() {
   while(getWinner() == "no winner")
   {
      Player currentPlayer = playerQueue->front();
      currentPlayer.rollDieAndMove();
      int newLocation = currentPlayer.getPostion();
      newLocation = gameBoard.checkChutesLadders(newLocation);
      currentPlayer.setPostion(newLocation);
      if (currentPlayer.getPostion() == 100) winner = currentPlayer.getName();
      playerQueue->dequeue();
      playerQueue->enqueue(currentPlayer);
   }
   cout << getWinner() << " is the winner!" << endl;
   return;
   
}
