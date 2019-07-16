#include <iostream>
#include "Game.h"

using namespace std;

	Game::Game(string player1, string player2)
	{
		m_player1 = new Player(player1);
		m_player2 = new Player(player2);
		m_board = new Board();
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
		}
		else
		{
			m_currentPlayer = m_player1;
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
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		return false;
	}

