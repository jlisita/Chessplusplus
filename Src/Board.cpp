#include <iostream>

#include "Board.h"
#include "Rook.h"

using namespace std;


	Board::Board()
	{

		for(int i=0; i< 8;++i)
		{
			for(int j = 0;j<8;++j)
			{
				m_board[i][j]=NULL;
			}
		}
	}

	Board::~Board()
	{

	}

	Piece* Board::getPiece(int i, int j) const
	{
		return m_board[i][j];
	}

	void Board::print(Color player) const
	{
		char rankIndex[8] = {'1','2','3','4','5','6','7','8'};
		char filesIndex[8] = {'a','b','c','d','e','f','g','h'};
		if (player == WHITE)
		{
			cout << "\n  |----|----|----|----|----|----|----|----|\n";
			for(int i(7);i>=0;--i)
			{
				cout << rankIndex[i] << " | ";
				for(int j(0);j<8;++j)
				{
					if(m_board[i][j]!=NULL)
					{
						cout << *m_board[i][j];
						cout << "  | ";
					}
					else
					{
						cout << "   | ";
					}
				}
				cout << "\n  |----|----|----|----|----|----|----|----|\n";

			}
			cout << "    ";
			for(int i(0);i<8;++i)
			{
				cout << filesIndex[i] << "    ";
			}
			cout << "\n";
		}
		else
		{
			cout << "\n  |----|----|----|----|----|----|----|----|\n";
			for(int i(0);i<8;++i)
			{
				cout << rankIndex[i] << " | ";
				for(int j(7);j>=0;--j)
				{
					if(m_board[i][j]!=NULL)
					{
						cout << *m_board[i][j];
						cout << "  | ";
					}
					else
					{
						cout << "   | ";
					}
				}
				cout << "\n  |----|----|----|----|----|----|----|----|\n";

			}
			cout << "    ";
			for(int i(7);i>=0;--i)
			{
				cout << filesIndex[i] << "    ";
			}
			cout << "\n";
		}
	}
