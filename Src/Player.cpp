#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(string name) : m_name(name)
{
}

Player::~Player()
{
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