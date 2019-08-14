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
	std::map<std::string,Piece*>& getListPieces();
	std::map<std::string,Piece*>& getCapturedPieces();
	void initPieceList();
	void addToCapturedList(Piece* p);
	void removeToCapturedList(std::string name);
	void addToListPiece(Piece* p);
	void removeToListPiece(std::string name);
	bool canTake(Piece* p) const;
	bool canEat(Piece* p) const;
	bool getIsChess() const;
	bool getIsMatt() const;
	void printListPiece() const;
	void printCapturedPiece() const;

private:

	std::string m_name;
	Color m_color;
	bool m_isChess;
	bool m_isMatt;
	std::map <std::string,Piece*> m_listPieces;
	std::map <std::string,Piece*> m_capturedPieces;
};

#endif
