#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <map>
#include <string>
#include "Piece.h"

class Player
{

public:

	Player(std::string name, Color color);
	~Player();

	std::string getName() const;
	Color getColor() const;
	void setColor(Color color);
	std::map<std::string,Piece*> getListPieces() const;
	std::map<std::string,Piece*> getCapturedPieces() const;
	void initPieceList();
	void updateCapturedList(Piece* p);
	void updateListPiece(std::string name);
	bool canTake(Piece* p) const;
	bool canEat(Piece* p) const;
	bool isChess() const;
	bool isMatt() const;
	void printListPiece() const;
	void printCapturedPiece() const;

private:

	std::string m_name;
	Color m_color;
	std::map <std::string,Piece*> m_listPieces;
	std::map <std::string,Piece*> m_capturedPieces;
};

#endif
