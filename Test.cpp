#include <iostream>
#include "doctest.h"
#include "Board.hpp"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"

using namespace WarGame;

	TEST_CASE("Test 1")
	{
			Board board(4, 4); 
			// Add soldiers for player 1:
			//assert(!board.has_soldiers(1));
			board[{0,1}] = new FootSoldier(1);
			board[{0,3}] = new FootCommander(1);
			board[{0,2}] = new FootSoldier(1);
			//assert(board.has_soldiers(1));

			// Add soldiers for player 2:
			//assert(!board.has_soldiers(2));
			board[{3,1}] = new FootSoldier(2);
			board[{3,2}] = new FootCommander(2);
			board[{3,2}] = new FootSoldier(2);

			board.move(1,{0,1}, Board::MoveDIR::Up);
			CHECK(board[{1,1}]->pointHealth > board[{3,1}]->pointHealth);

			

	}
