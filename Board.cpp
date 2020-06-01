#include <iostream>
#include "Board.hpp"
#include "FootSoldier.hpp"
 // #include <cstdlib>
using namespace std;
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

void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction)
{

  switch (direction)
  {
  case MoveDIR::Up:
    if (!board[source.first + 1][source.second])
    {
      board[source.first + 1][source.second] = board[source.first][source.second];
      board[source.first][source.second] = nullptr;
      //   board[source.first + 1][source.second]->shoot();
    }

    break;
  case MoveDIR::Down:
    if (!board[source.first - 1][source.second])
    {
      board[source.first - 1][source.second] = board[source.first][source.second];
      board[source.first][source.second] = nullptr;
      //   board[source.first - 1][source.second]->shoot();
    }
    break;

  case MoveDIR::Right:
    if (!board[source.first][source.second + 1])
    {
      board[source.first][source.second + 1] = board[source.first][source.second];
      board[source.first][source.second] = nullptr;
      //   shoot(board[source.first][source.second + 1]);
    }

    break;
  case MoveDIR::Left:
    if (!board[source.first][source.second - 1])
    {
      board[source.first][source.second - 1] = board[source.first][source.second];
      board[source.first][source.second] = nullptr;
      ///   board[source.first][source.second - 1]->shoot();
    }
    break;
  }

  return;
}

// returns true iff the board contains one or more soldiers of the given player.
bool Board::has_soldiers(uint player_number) const
{
  for (size_t i = 0; i < board.size(); i++)
  {
    for (size_t j = 0; j < board[0].size(); j++)
    {
      if (board[i][j] && (board[i][j]->player == player_number))
      {
        return true;
      }
    }
  }
}

int main()
{
  Board b(3, 3);
  b[{0, 0}] = new FootSoldier(1);
  b[{0, 2}] = new FootSoldier(2);
  b.move(1, {0, 0}, Board::MoveDIR::Up);

  std::cout << "{0,0}: " << b[{0, 0}] << std::endl;
  std::cout << "{1,0}: " << b[{1, 0}]->player << std::endl;
  std::cout << "{0,2}: " << b[{0, 2}]->player << std::endl;
  //std::cout << "{0,2}: " << b[{1, 0}]->getTarget(1, 0).player << std::endl;
}