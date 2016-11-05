//
//  GameBoard.hpp
//

#pragma once

#include <stdexcept>

#include "ExtendableVector.h"

const int OUTSIDE_BOARD = -1;
const int BOARD_SIZE = 101;

class GameBoard {
public:   
   enum Ladders { ONE = 1, FOUR = 4, NINE = 9, TWENTY_ONE = 21, TWENTY_EIGHT = 28, THIRTY_SIX = 36, FIFTY_ONE = 51, SEVENTY_ONE = 71, EIGHTY = 80 };
   
   enum Chutes { SIXTEEN = 16, FORTY_SEVEN = 47, FORTY_NINE = 49, FIFTY_SIX = 56, SIXTY_TWO = 62, SIXTY_FOUR = 64, EIGHTY_SEVEN = 87, NINETY_THREE = 93, NINETY_FIVE = 95, NINETY_EIGHT = 98 };
   
   // Build the gameboard
   // TO DO: implement this function
   void buildBoard();
   
   GameBoard() {
      // TODO: implement this function properly
      throw std::logic_error("not implemented yet");
   }
   
   // If player lands on chutes or ladders, returns the new position.
   // Otherwise, returns the player's current position.
   // If the player's position is outside of the gameboard, throws index out of bounds exception
   // TO DO: implement this function properly
    int checkChutesLadders(int position) 
    {
      if ((position < 0) || (position >= BOARD_SIZE)) 
      {
         throw range_error("index out of bounds");
      }
      
      switch (position) 
      {
            case GameBoard::ONE: // Ladder
                return(38);
                break;
            case GameBoard::FOUR: // Ladder
                return(14);
                break;
            case GameBoard::NINE: // Ladder
                return(31);
                break;
            case GameBoard::SIXTEEN: // Chute
                return(6);
                break;
            case GameBoard::TWENTY_ONE: // Ladder
                return(42);
                break;
            case GameBoard::TWENTY_EIGHT: // Ladder
                return(84);
                break;
            case GameBoard::THIRTY_SIX: // Ladder
                return(44);
                break;
            case GameBoard::FORTY_SEVEN: // Chute
                return(26);
                break;
            case GameBoard::FORTY_NINE: // Chute
                return(11);
                break;
            case GameBoard::FIFTY_ONE: // Ladder
                return(67);
                break;
            case GameBoard::SIXTY_TWO: // Chute
                return(19);
                break;
            case GameBoard::FIFTY_SIX: // Chute
                return(53);
                break;
            case GameBoard::SIXTY_FOUR: // Chute
                return(60);
                break;
            case GameBoard::SEVENTY_ONE: // Ladder
                return(91);
                break;
            case GameBoard::EIGHTY: // Ladder
                return(100);
                break;
            case GameBoard::EIGHTY_SEVEN: // Chute
                return(24);
                break;
            case GameBoard::NINETY_THREE: // Chute
                return(73);
                break;
            case GameBoard::NINETY_FIVE: // Chute
                return(75);
                break;
            case GameBoard::NINETY_EIGHT: // Chute
                return(78);
                break;
            default:
                return(position);
                break;
           }
        }
    }
   
private:
   // TO DO: add storage for squares including square of chutes and ladders
   // Requirement: use ExtendableVector to store the square
   ExtendableVector *Spaces;
};
