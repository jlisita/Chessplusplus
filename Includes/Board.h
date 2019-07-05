#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "Piece.h"

class Board
{

public:

	Board();

	~Board();



private:

	Piece* m_board[8][8];

};


#endif