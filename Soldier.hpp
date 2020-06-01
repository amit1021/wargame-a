#pragma once
#include <iostream>
#include "Board.hpp"
#include <bits/stdc++.h>


class Soldier
{
public:
    int pointHealth;
    int pointDamage;
    int player;

    Soldier(int pointHealth, int pointDamage, int player)
    {
        this->player = player;
        this->pointHealth = pointHealth;
        this->pointDamage = pointDamage;
    }
    

Soldier &getTarget(int i1, int j1 , Board *board)
{
  int min = INT_MAX;
  int diff = 0;
  std::pair<int, int> target;
  for (size_t i = 0; i < board->getBoard().size(); i++)
  {
    for (size_t j = 0; j < board->getBoard()[0].size(); j++)
    {
      if (board->getBoard()[i][j])
      {
        int t = i + j - (i1 + j1);
        diff = abs(t);
        if (diff < min && diff != 0)
        {
          min = diff;
          target = {i, j};
        }
      }
    }
  }
  return *board->getBoard()[target.first][target.second];
}


};