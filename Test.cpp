#include <iostream>
#include "doctest.h"
#include "Board.hpp"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace WarGame;
TEST_CASE("Test 1")
{
	Board board(4, 4);

	CHECK(board.has_soldiers(1) == false);
	CHECK(board.has_soldiers(2) == false);

	// Add soldiers for player 1:
	board[{0, 1}] = new FootSoldier(1);
	board[{0, 3}] = new FootCommander(1);
	board[{0, 2}] = new FootSoldier(1);

	// Add soldiers for player 2:

	board[{3, 1}] = new FootSoldier(2);
	board[{3, 2}] = new FootCommander(2);
	board[{3, 3}] = new FootSoldier(2);

	// check board init
	CHECK(board[{0, 1}]->pointHealth == 100);
	CHECK(board[{0, 2}]->pointHealth == 100);
	CHECK(board[{3, 1}]->pointHealth == 100);
	CHECK(board[{3, 3}]->pointHealth == 100);
	CHECK(board[{3, 2}]->pointHealth == 150);
	CHECK(board[{0, 3}]->pointHealth == 150);

	CHECK(board[{0, 1}]->pointDamage == 10);
	CHECK(board[{0, 2}]->pointDamage == 10);
	CHECK(board[{3, 1}]->pointDamage == 10);
	CHECK(board[{3, 3}]->pointDamage == 10);
	CHECK(board[{3, 2}]->pointDamage == 20);
	CHECK(board[{0, 3}]->pointDamage == 20);

	CHECK(board[{1, 1}] == nullptr);
	CHECK(board[{1, 2}] == nullptr);
	CHECK(board[{2, 3}] == nullptr);
	CHECK(board[{2, 2}] == nullptr);

	CHECK(board.has_soldiers(1) == true);
	CHECK(board.has_soldiers(2) == true);

	CHECK_THROWS((board[{3, 3}] == nullptr));
	CHECK_THROWS((board[{2, 2}] != nullptr));
	CHECK_THROWS((board[{1, 1}] != nullptr));

	//play

	board.move(1, {0, 1}, Board::MoveDIR::Up);
	//	CHECK(board[{1, 1}]->pointHealth > board[{3, 1}]->pointHealth);
	CHECK(board[{0, 1}] == nullptr);
	CHECK(board[{1, 1}] != nullptr);
	board.move(2, {3, 1}, Board::MoveDIR::Down);
	// CHECK(board[{2, 1}]->pointHealth == board[{1, 1}]->pointHealth);
	CHECK(board[{3, 1}] == nullptr);
	CHECK(board[{2, 1}] != nullptr);
	CHECK(board.has_soldiers(2) == true);
	board.move(1, {1, 1}, Board::MoveDIR::Right);
	// CHECK(board[{1, 2}]->pointHealth > board[{2, 1}]->pointHealth);
	CHECK(board[{1, 1}] == nullptr);
	CHECK(board[{1, 2}] != nullptr);
	CHECK(board.has_soldiers(1) == true);
	board.move(2, {3, 2}, Board::MoveDIR::Down);
	// CHECK(board[{2, 2}]->pointHealth > board[{0, 3}]->pointHealth);
	CHECK(board[{3, 2}] == nullptr);
	CHECK(board[{2, 2}] != nullptr);
	board.move(1, {0, 2}, Board::MoveDIR::Up);
	CHECK(board[{0, 2}]->pointHealth > board[{3, 2}]->pointHealth);
	board.move(2, {2, 2}, Board::MoveDIR::Right);
	CHECK(board[{0, 3}]->pointHealth == board[{3, 2}]->pointHealth);
	CHECK(board[{2, 2}] == nullptr);
	CHECK(board[{2, 3}] != nullptr);
	board.move(1, {1, 2}, Board::MoveDIR::Left);
	CHECK(board[{0, 1}]->pointHealth == board[{0, 1}]->pointHealth);
	CHECK(board[{1, 2}] == nullptr);
	CHECK(board[{1, 1}] != nullptr);
	board.move(2, {2, 3}, Board::MoveDIR::Left);
	CHECK(board[{2, 2}] == nullptr);
	CHECK(board[{2, 3}] != nullptr);
	CHECK_THROWS((board[{0, 1}]->pointHealth < board[{0, 3}]->pointHealth));
	CHECK_THROWS((board[{3,3}]->pointHealth != board[{0, 2}]->pointHealth));
	CHECK_THROWS((board[{0, 3}]->pointHealth > board[{3, 2}]->pointHealth));
	CHECK(board[{0, 1}]->pointHealth < board[{0, 2}]->pointHealth);
	CHECK(board[{3, 3}]->pointHealth > board[{0, 3}]->pointHealth);
	CHECK(board[{3, 3}]->pointHealth == board[{0, 2}]->pointHealth);
	CHECK(board.has_soldiers(1) == true);
}

TEST_CASE("Test 2")
{
	Board board(7, 7);

	CHECK(board.has_soldiers(1) == false);
	CHECK(board.has_soldiers(2) == false);

	//Add soldier player 1
	board[{0, 0}] = new Sniper(1);
	board[{0, 1}] = new FootCommander(1);
	board[{0, 2}] = new Paramedic(1);
	board[{0, 3}] = new FootSoldier(1);
	board[{0, 4}] = new ParamedicCommander(1);
	board[{0, 5}] = new SniperCommander(1);

	//Add soldier player 2
	board[{6, 0}] = new Sniper(2);
	board[{6, 1}] = new FootCommander(2);
	board[{6, 2}] = new Paramedic(2);
	board[{6, 3}] = new FootSoldier(2);
	board[{6, 4}] = new ParamedicCommander(2);
	board[{6, 5}] = new SniperCommander(2);

	CHECK(board.has_soldiers(1) == true);
	CHECK(board.has_soldiers(2) == true);

	// check board init
	CHECK(board[{0, 0}]->pointHealth == 100);
	CHECK(board[{0, 1}]->pointHealth == 150);
	CHECK(board[{0, 2}]->pointHealth == 100);
	CHECK(board[{0, 3}]->pointHealth == 100);
	CHECK(board[{0, 4}]->pointHealth == 200);
	CHECK(board[{0, 5}]->pointHealth == 120);

	CHECK(board[{0, 0}]->pointDamage == 50);
	CHECK(board[{0, 1}]->pointDamage == 20);
	CHECK(board[{0, 2}]->pointDamage == 50);
	CHECK(board[{0, 3}]->pointDamage == 10);
	CHECK(board[{0, 4}]->pointDamage == 100);
	CHECK(board[{0, 5}]->pointDamage == 100);

	CHECK(board[{6, 0}]->pointHealth == 100);
	CHECK(board[{6, 1}]->pointHealth == 150);
	CHECK(board[{6, 2}]->pointHealth == 100);
	CHECK(board[{6, 3}]->pointHealth == 100);
	CHECK(board[{6, 4}]->pointHealth == 200);
	CHECK(board[{6, 5}]->pointHealth == 120);

	CHECK(board[{6, 0}]->pointDamage == 50);
	CHECK(board[{6, 1}]->pointDamage == 20);
	CHECK(board[{6, 2}]->pointDamage == 50);
	CHECK(board[{6, 3}]->pointDamage == 10);
	CHECK(board[{6, 4}]->pointDamage == 100);
	CHECK(board[{6, 5}]->pointDamage == 100);

	CHECK(board[{1, 1}] == nullptr);
	CHECK(board[{2, 2}] == nullptr);
	CHECK(board[{5, 3}] == nullptr);
	CHECK(board[{3, 2}] == nullptr);
	CHECK(board[{2, 1}] == nullptr);
	CHECK(board[{5, 2}] == nullptr);
	CHECK(board[{6, 6}] == nullptr);
	CHECK(board[{2, 3}] == nullptr);

	CHECK_THROWS((board[{6, 3}] == nullptr));
	CHECK_THROWS((board[{6, 4}] == nullptr));
	CHECK_THROWS((board[{0, 3}] == nullptr));
	CHECK_THROWS((board[{0, 5}] == nullptr));
	CHECK_THROWS((board[{2, 2}] != nullptr));
	CHECK_THROWS((board[{4, 4}] != nullptr));

	//play
	board.move(1, {0, 5}, Board::MoveDIR::Up);
	CHECK(board[{0, 5}]->pointHealth > board[{6, 5}]->pointHealth);
	board.move(2, {6, 0}, Board::MoveDIR::Down);
	CHECK(board[{0, 0}]->pointHealth < board[{6, 0}]->pointHealth);
	CHECK(board[{0, 0}]->pointHealth < board[{6, 1}]->pointHealth);
	CHECK(board[{0, 0}]->pointHealth < board[{6, 3}]->pointHealth);
	CHECK(board[{0, 0}]->pointHealth > board[{6, 5}]->pointHealth);
	CHECK(board[{6, 0}] == nullptr);
	CHECK(board[{0, 5}] == nullptr);
	CHECK(board[{6, 0}] != nullptr);
	CHECK(board[{1, 5}] != nullptr);
}