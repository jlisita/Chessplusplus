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

	bool canMove(int i, int j, int k, int l) const;

private:

	Player* m_player1;
	Player* m_player2;
	Player* m_currentPlayer;
	Board* m_board;

};

#endif