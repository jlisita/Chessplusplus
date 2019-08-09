#include <iostream>
#include "Player.h"
#include "Pawn.h"
#include "Rook.h"
#include "Player.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"

using namespace std;

Player::Player(string name, Color color) : m_name(name), m_color(color), m_isChess(false)
{
	initPieceList();
	m_capturedPieces.clear();

}

Player::~Player()
{
	for(map<string,Piece*>::iterator it = m_listPieces.begin(); it != m_listPieces.end();++it)
	{
		delete it->second;
	}
	m_listPieces.clear();
	for(map<string,Piece*>::iterator it = m_capturedPieces.begin(); it != m_capturedPieces.end();++it)
	{
		delete it->second;
	}
	m_capturedPieces.clear();

}

string Player::getName() const
{
	return m_name;
}
Color Player::getColor() const
{
	return m_color;
}
void Player::setColor(Color color)
{
	m_color = color;
}
map<string,Piece*>& Player::getListPieces()
{
	return m_listPieces;
}
map<string,Piece*>& Player::getCapturedPieces()
{
	return m_capturedPieces;
}

void Player::initPieceList()
{
	if(m_color==WHITE)
	{
			m_listPieces.insert(std::pair<string,Piece*>("Pawn1",new Pawn(m_color,"Pawn1",1,0)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn2",new Pawn(m_color,"Pawn2",1,1)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn3",new Pawn(m_color,"Pawn3",1,2)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn4",new Pawn(m_color,"Pawn4",1,3)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn5",new Pawn(m_color,"Pawn5",1,4)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn6",new Pawn(m_color,"Pawn6",1,5)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn7",new Pawn(m_color,"Pawn7",1,6)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn8",new Pawn(m_color,"Pawn8",1,7)));
			m_listPieces.insert(std::pair<string,Piece*>("Rook1",new Rook(m_color,"Rook1",0,0)));
			m_listPieces.insert(std::pair<string,Piece*>("Rook2",new Rook(m_color,"Rook2",0,7)));
			m_listPieces.insert(std::pair<string,Piece*>("Knight1",new Knight(m_color,"Knight1",0,1)));
			m_listPieces.insert(std::pair<string,Piece*>("Knight2",new Knight(m_color,"Knight2",0,6)));
			m_listPieces.insert(std::pair<string,Piece*>("Bishop1",new Bishop(m_color,"Bishop1",0,2)));
			m_listPieces.insert(std::pair<string,Piece*>("Bishop2",new Bishop(m_color,"Bishop2",0,5)));
			m_listPieces.insert(std::pair<string,Piece*>("King",new King(m_color,"King",0,4)));
			m_listPieces.insert(std::pair<string,Piece*>("Queen",new Queen(m_color,"Queen",0,3)));
	}
	else
	{
			m_listPieces.insert(std::pair<string,Piece*>("Pawn1",new Pawn(m_color,"Pawn1",6,0)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn2",new Pawn(m_color,"Pawn2",6,1)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn3",new Pawn(m_color,"Pawn3",6,2)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn4",new Pawn(m_color,"Pawn4",6,3)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn5",new Pawn(m_color,"Pawn5",6,4)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn6",new Pawn(m_color,"Pawn6",6,5)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn7",new Pawn(m_color,"Pawn7",6,6)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn8",new Pawn(m_color,"Pawn8",6,7)));
			m_listPieces.insert(std::pair<string,Piece*>("Rook1",new Rook(m_color,"Rook1",7,0)));
			m_listPieces.insert(std::pair<string,Piece*>("Rook2",new Rook(m_color,"Rook2",7,7)));
			m_listPieces.insert(std::pair<string,Piece*>("Knight1",new Knight(m_color,"Knight1",7,1)));
			m_listPieces.insert(std::pair<string,Piece*>("Knight2",new Knight(m_color,"Knight2",7,6)));
			m_listPieces.insert(std::pair<string,Piece*>("Bishop1",new Bishop(m_color,"Bishop1",7,2)));
			m_listPieces.insert(std::pair<string,Piece*>("Bishop2",new Bishop(m_color,"Bishop2",7,5)));
			m_listPieces.insert(std::pair<string,Piece*>("King",new King(m_color,"King",7,4)));
			m_listPieces.insert(std::pair<string,Piece*>("Queen",new Queen(m_color,"Queen",7,3)));

	}
}

void Player::updateCapturedList(Piece* p)
{
	m_capturedPieces.insert(std::pair<string,Piece*>(p->getName(),p));
}

void Player::updateListPiece(std::string name)
{
	m_listPieces.erase(name);
}

bool Player::canTake(Piece* p) const
{
	return m_color==p->getColor();
}
bool Player::canEat(Piece* p) const
{
	return m_color!=p->getColor();
}
bool Player::getIsChess() const
{
	return m_isChess;
}

void Player::printListPiece() const
{
	for(map<string,Piece*>::const_iterator it = m_listPieces.begin(); it != m_listPieces.end();++it)
	{
		it->second->print(cout);
	}
	cout << endl;
}
void Player::printCapturedPiece() const
{
	for(map<string,Piece*>::const_iterator it = m_capturedPieces.begin(); it != m_capturedPieces.end();++it)
	{
		it->second->print(cout);
	}
	cout << endl;
}

