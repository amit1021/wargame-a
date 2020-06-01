#include "FootSoldier.hpp"
#include "Board.hpp"

using namespace std;
using namespace WarGame;

void FootSoldier::shoot(Soldier s, std::pair<int, int> source)
{
    Soldier target = Board::getTarget(source.first, source.second,Board b);
    
}