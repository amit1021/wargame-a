#include <iostream>
#include "Board.hpp"

using namespace WarGame;

Soldier *&Board ::operator[](std::pair<int, int> location)
{
  return board[location.first][location.second];
}

// operator for reading which soldiers are on the game-board.
Soldier *Board ::operator[](std::pair<int, int> location) const
{
   return board[location.first][location.second];
}

void Board:: move(uint player_number, std::pair<int, int> source, MoveDIR direction)
{
    return;
}

// returns true iff the board contains one or more soldiers of the given player.
bool Board:: has_soldiers(uint player_number) const
{
    return true;
}