#ifndef GAME_H
#define GAME_H

#include <string>
#include "Player.h"
#include "Board.h"

class Game
{

public:

	Game(std::string player1, std::string player2);

	~Game();

	void nextPlayer();

	bool canMove(Player* player,int i, int j, int k, int l) const;

	bool canMoveWithoutChess(int i, int j, int k, int l) const;

	void move(int i, int j,int k,int l);

	Board* getBoard() const;

	Player* getCurrentPlayer() const;

	bool testChess() const;

	bool testMatt() const;

private:

	Player* m_player1;
	Player* m_player2;
	Player* m_currentPlayer;
	Player* m_adversary;
	Board* m_board;

};

#endif