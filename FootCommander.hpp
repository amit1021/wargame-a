#include <iostream>
#include "Soldier.hpp"

class FootCommander : public Soldier
{

public:
    FootCommander(int player) : Soldier(100,10,player){} 
    ~FootCommander();
};
