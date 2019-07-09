#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "Piece.h"

enum Orientation
{
	FRONT, BACK
};

class Board
{

public:

	Board();

	~Board();

	Piece* getPiece(int i, int j) const;

	void addPiece(Piece* p, int i, int j);

	bool isEmpty(int i,int j) const;

	bool isEmptyBetween(int i, int j, int k, int l) const;

	void print(Orientation o) const;


private:

	Piece* m_board[8][8];

};


#endif
