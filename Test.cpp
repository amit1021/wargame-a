#include <iostream>
#include "doctest.h"
#include "Board.hpp"
#include "DemoGame.hpp"

using namespace WarGame;

TEST_CASE("Test 1")
{
			WarGame::Board b = new Board(4,4);
			// Add soldiers for player 1:
			assert(!board.has_soldiers(1));
			board[{0,1}] = new FootSoldier(1);
			board[{0,3}] = new FootCommander(1);
			board[{0,5}] = new FootSoldier(1);
			assert(board.has_soldiers(1));

			// Add soldiers for player 2:
			assert(!board.has_soldiers(2));
			board[{7,1}] = new FootSoldier(2);
			board[{7,3}] = new FootCommander(2);
			board[{7,5}] = new FootSoldier(2);

}
