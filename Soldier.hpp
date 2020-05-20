#pragma once
#include <iostream>

class Soldier
{
    public:
        int pointHealth;
        int pointDamage;
        int player;

        Soldier (int pointHealth, int pointDamage, int player)
        {
            this->player = player;
            this->pointHealth = pointHealth;
            this->pointDamage = pointDamage;
        }

};