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

	void Board::addPiece(Piece* p, int i, int j)
	{
		if(m_board[i][j]==NULL && i<8 && j<8 )
		{
			m_board[i][j]=p;
		}
	}

	bool Board::isEmpty(int i,int j) const
	{
		return m_board[i][j]==NULL;
	}

	bool Board::isEmptyBetween(int i, int j, int k, int l) const
	{
		int n,m;
		if(k-i==0) // horizontal move
		{
			if(l-j>0) // from left to right
			{
				for(n=j+1;n<l;n++)
				{
					if(!isEmpty(i,n))
					{
						return false;
					}
				}
			}
			else // from right to left
			{
				for(n=j-1;n>l;n--)
				{
					if(!isEmpty(i,n))
					{
						return false;
					}
				}
			}

		}
		else if(l-j==0) // vertical move
		{
			if(k-i>0) // from down to up
			{
				for(m=i+1;m<k;m++)
				{
					if(!isEmpty(m,j))
					{
						return false;
					}
				}
			}
			else // from up to down
			{
				for(m=i-1;m>k;m--)
				{
					if(!isEmpty(m,j))
					{
						return false;
					}
				}
			}

		}
		else // diagonal move
		{
			// from down/left to up/right
			if(k-i>0 && l-j>0)
			{
				for(n=1;n<k-i;n++)
				{
					if(!isEmpty(i+n,j+n))
					{
						return false;
					}
				}
			}
			// from down/right to up/left
			else if(k-i>0 && l-j<0)
			{
				for(n=1;n<k-i;n++)
				{
					if(!isEmpty(i+n,j-n))
					{
						return false;
					}
				}
			}
			// from up/left to down/right
			else if(k-i<0 && l-j>0 )
			{
				for(n=1;n<abs(k-i);n++)
				{
					if(!isEmpty(i-n,j+n))
					{
						return false;
					}
				}
			}
			// from up/right to down/left
			else if(k-i<0 && l-j<0)
			{
				for(n=1;n<abs(k-i);n++)
				{
					if(!isEmpty(i-n,j-n))
					{
						return false;
					}
				}
			}
		}
		return 1;
	}

	void Board::print(Orientation o) const
	{
		char rankIndex[8] = {'1','2','3','4','5','6','7','8'};
		char filesIndex[8] = {'a','b','c','d','e','f','g','h'};
		if (o == BACK)
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
