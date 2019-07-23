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

Player::Player(string name, Color color) : m_name(name), m_color(color)
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
map<string,Piece*> Player::getListPieces() const
{
	return m_listPieces;
}
map<string,Piece*> Player::getCapturedPieces() const
{
	return m_capturedPieces;
}

void Player::initPieceList()
{
	if(m_color==WHITE)
	{
			m_listPieces.insert(std::pair<string,Piece*>("Pawn1",new Pawn(m_color,1,0)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn2",new Pawn(m_color,1,1)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn3",new Pawn(m_color,1,2)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn4",new Pawn(m_color,1,3)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn5",new Pawn(m_color,1,4)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn6",new Pawn(m_color,1,5)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn7",new Pawn(m_color,1,6)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn8",new Pawn(m_color,1,7)));
			m_listPieces.insert(std::pair<string,Piece*>("Rook1",new Rook(m_color,0,0)));
			m_listPieces.insert(std::pair<string,Piece*>("Rook2",new Rook(m_color,0,7)));
			m_listPieces.insert(std::pair<string,Piece*>("Knight1",new Knight(m_color,0,1)));
			m_listPieces.insert(std::pair<string,Piece*>("Knight2",new Knight(m_color,0,6)));
			m_listPieces.insert(std::pair<string,Piece*>("Bishop1",new Bishop(m_color,0,2)));
			m_listPieces.insert(std::pair<string,Piece*>("Bishop2",new Bishop(m_color,0,5)));
			m_listPieces.insert(std::pair<string,Piece*>("King",new King(m_color,0,3)));
			m_listPieces.insert(std::pair<string,Piece*>("Queen",new Queen(m_color,0,4)));
	}
	else
	{
			m_listPieces.insert(std::pair<string,Piece*>("Pawn1",new Pawn(m_color,6,0)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn2",new Pawn(m_color,6,1)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn3",new Pawn(m_color,6,2)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn4",new Pawn(m_color,6,3)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn5",new Pawn(m_color,6,4)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn6",new Pawn(m_color,6,5)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn7",new Pawn(m_color,6,6)));
			m_listPieces.insert(std::pair<string,Piece*>("Pawn8",new Pawn(m_color,6,7)));
			m_listPieces.insert(std::pair<string,Piece*>("Rook1",new Rook(m_color,7,0)));
			m_listPieces.insert(std::pair<string,Piece*>("Rook2",new Rook(m_color,7,7)));
			m_listPieces.insert(std::pair<string,Piece*>("Knight1",new Knight(m_color,7,1)));
			m_listPieces.insert(std::pair<string,Piece*>("Knight2",new Knight(m_color,7,6)));
			m_listPieces.insert(std::pair<string,Piece*>("Bishop1",new Bishop(m_color,7,2)));
			m_listPieces.insert(std::pair<string,Piece*>("Bishop2",new Bishop(m_color,7,5)));
			m_listPieces.insert(std::pair<string,Piece*>("King",new King(m_color,7,3)));
			m_listPieces.insert(std::pair<string,Piece*>("Queen",new Queen(m_color,7,4)));

	}
}

void Player::updateCapturedList(Piece* p)
{
	m_capturedPieces.insert(std::pair<string,Piece*>(p->getName(),p));
}

bool Player::canTake(Piece* p) const
{
	return m_color==p->getColor();
}
bool Player::canEat(Piece* p) const
{
	return m_color!=p->getColor();
}
bool Player::isChess() const
{
	return false;
}
bool Player::isMatt() const
{
	return false;
}