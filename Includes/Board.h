#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "Piece.h"

class Board
{

public:

	Board();

	~Board();

	Piece* getPiece(int i, int j) const;

	void print(Color player) const;



private:

	Piece* m_board[8][8];

};


#endif