#include <iostream>
#include "Game.h"

using namespace std;

	Game::Game(string player1, string player2)
	{
		m_player1 = new Player(player1,WHITE);
		m_currentPlayer = m_player1;
		m_player2 = new Player(player2,BLACK);
		m_adversary = m_player2;
		m_board = new Board();
		m_board->initBoard(m_player1->getListPieces());
		m_board->initBoard(m_player2->getListPieces());
	}

	Game::~Game()
	{
		delete m_player1;
		m_player1 = 0;
		delete m_player2;
		m_player2 = 0;
		delete m_board;
		m_board = 0;
	}

	void Game::nextPlayer()
	{
		if(m_currentPlayer->getName()==m_player1->getName())
		{
			m_currentPlayer = m_player2;
			m_adversary = m_player1;
		}
		else
		{
			m_currentPlayer = m_player1;
			m_adversary = m_player2;
		}
	}

	bool Game::canMove(int i, int j, int k, int l) const
	{
		if (m_board->isValidPosition(i,j,k,l))
		{
			if(!m_board->isEmpty(i,j))
			{
				if(m_currentPlayer->canTake(m_board->getPiece(i,j)))
				{
					if(m_board->isEmpty(k,l)  || m_currentPlayer->canEat(m_board->getPiece(k,l)) )
					{
						return m_board->getPiece(i,j)->canMove(i,j,k,l,m_board);
					}
					else
					{
						cout << "Cette pièce ne peut pas être capturé" << endl;
					}
				}
				else
				{
					cout << "Cette piece ne peut pas être déplacé" << endl;
					return false;
				}
			}
			else
			{
				cout << "il n'y a pas de piece à déplacer sur cette case" << endl;
				return false;
			}
		}
		else
		{
			cout << "la position n'existe pas sur le plateau" << endl;
			return false;
		}
		return false;
	 }

	 void Game::move(int i, int j,int k,int l)
	 {
	 	if(!m_board->isEmpty(k,l))
	 	{
	 		m_currentPlayer->updateCapturedList(m_board->getPiece(k,l));
	 		m_adversary->updateListPiece(m_board->getPiece(k,l)->getName());
	 	}
	 	m_board->move(i,j,k,l);
	 	m_board->getPiece(k,l)->setFirstMove();
	 }

	 Board* Game::getBoard() const
	 {
	 	return m_board;
	 }

