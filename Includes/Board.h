#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <map>
class Piece;

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

	void initBoard(std::map<std::string,Piece*>listPieces);

	bool isEmpty(int i,int j) const;

	bool isEmptyBetween(int i, int j, int k, int l) const;

	bool isValidPosition(int i, int j, int k, int l) const;

	void print(Orientation o) const;


private:

	Piece* m_board[8][8];

};


#endif
