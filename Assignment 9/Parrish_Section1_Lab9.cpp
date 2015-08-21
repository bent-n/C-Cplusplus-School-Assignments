//Lab 9 Tic-Tac-Toe
//William Benton Parrish
//11/3/2014

/*In the C++ programming language write a program
capable of playing Tic-Tac-Toe against the user. Your program should use OOP concepts in its
design. You can use ASCII art to generate and display the 3x3 playing board. The program
should randomly decide who goes first computer or user. Your program should know and inform
the user if an illegal move was made (cell already occupied). The program should also announce
if one of the players wins or if a draw is achieved. While it is desirable for your program to play
a strong game, this is not an Artificial Intelligence course so if your program does not play at a
world champion level you will not be penalized for it.*/

#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;

class Tile
{
	private:		
		
		int location;
		bool unoccupied;
		
	public:
		void set(int);
		char state;
		
	 	bool playerChoose(void);
		bool computerChoose(void);
		
};
class Board
{
	public:
		Tile tile1;
		Tile tile2;
		Tile tile3;
		Tile tile4;
		Tile tile5;
		Tile tile6;
		Tile tile7;
		Tile tile8;
		Tile tile9;
		Board();
		void showBoard(void);
		bool tileChoose(bool, int);
		bool gameCheck(bool);
};
int main()
{
	Board board;
	srand(time(NULL));
	//bool playerTurn=1;
	bool playerTurn=(rand()%2);
	bool gameOver=0;
	int selection;
	bool endTurn;
	while(gameOver==0)
	{
		board.showBoard();
		do
		{
			if(playerTurn)
			{
				cout<<endl<<"Player's Turn!"<<endl<<"Choose a Tile: ";
				cin>>selection;
				endTurn=board.tileChoose(playerTurn, selection);
				if (endTurn==0)
				{
					cout<<endl<<"Invalid Choice"<<endl<<"Please Choose Again";
				}
				else if (endTurn)
				{
					gameOver=board.gameCheck(playerTurn);
					playerTurn=0;
				}
			
			}
			else
			{
				cout<<endl<<"Computer's Turn";
				selection=(rand()%9)+1;
				endTurn=board.tileChoose(playerTurn, selection);
				if(endTurn)
				{
					gameOver=board.gameCheck(playerTurn);
					playerTurn=1;
				}
			}	
				
		
		}while(endTurn==0);
	
		
	}
	
	board.showBoard();
	
	
	return 0;
}



void Tile::set(int num)
{
	location=num;
	unoccupied=1;
	state=' ';
}
bool Tile::playerChoose()
{
	if(unoccupied)
	{
		state='X';
		unoccupied=0;	
		return 1;
	}
	else
	{
		return 0;
	}
	
}
bool Tile::computerChoose()
{
	if(unoccupied)
	{
		state='O';
		unoccupied=0;
		return 1;	
	}
	else
	{
		return 0;
	}
	
}

Board::Board()
{
	tile1.set(1);
	tile2.set(2);
	tile3.set(3);
	tile4.set(4);
	tile5.set(5);
	tile6.set(6);
	tile7.set(7);
	tile8.set(8);
	tile9.set(9);
}
void Board::showBoard()
{
		cout<<endl<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<tile1.state<<")  |  ("<<tile2.state<<")  |  ("<<tile3.state<<")  |"<<endl<<"|   1   |   2   |   3   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<tile4.state<<")  |  ("<<tile5.state<<")  |  ("<<tile6.state<<")  |"<<endl<<"|   4   |   5   |   6   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<tile7.state<<")  |  ("<<tile8.state<<")  |  ("<<tile9.state<<")  |"<<endl<<"|   7   |   8   |   9   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
	
}
bool Board::tileChoose(bool playerTurn, int selection)
{
	
	if(playerTurn)
	{
		switch(selection)
		{
			case 1:
				{
					return tile1.playerChoose();
					break;
				}
			case 2:
				{
					return tile2.playerChoose();
					break;
				}
			case 3:
				{
					return tile3.playerChoose();
					break;
				}
			case 4:
				{
					return tile4.playerChoose();
					break;
				}
			case 5:
				{
					return tile5.playerChoose();
					break;
				}
			case 6:
				{
					return tile6.playerChoose();
					break;
				}
			case 7:
				{
					return tile7.playerChoose();
					break;
				}
			case 8:
				{
					return tile8.playerChoose();
					break;
				}
			case 9:
				{
					return tile9.playerChoose();
					break;
				}
			default:
				{
					return 0;
				}
			
		}
	}
	else
	{
		switch(selection)
		{
			case 1:
				{
					return tile1.computerChoose();
					break;
				}
			case 2:
				{
					return tile2.computerChoose();
					break;
				}
			case 3:
				{
					return tile3.computerChoose();
					break;
				}
			case 4:
				{
					return tile4.computerChoose();
					break;
				}
			case 5:
				{
					return tile5.computerChoose();
					break;
				}
			case 6:
				{
					return tile6.computerChoose();
					break;
				}
			case 7:
				{
					return tile7.computerChoose();
					break;
				}
			case 8:
				{
					return tile8.computerChoose();
					break;
				}
			case 9:
				{
					return tile9.computerChoose();
					break;
				}
			default:
				{
					return 0;
				}
			
		}
		
		
		
	}
	
	
}
bool Board::gameCheck(bool playerTurn)
{
	int endGame=0;
	char empty=' ';
	if (tile1.state==tile2.state&&tile1.state==tile3.state&&tile1.state!=empty)
	{
		endGame=1;
		
	}
	else if (tile1.state==tile4.state&&tile1.state==tile7.state&&tile1.state!=empty)
	{
		endGame=1;
		
	}
	else if (tile1.state==tile5.state&&tile1.state==tile9.state&&tile1.state!=empty)
	{
		endGame=1;
		
	}
	else if (tile2.state==tile5.state&&tile2.state==tile8.state&&tile2.state!=empty)
	{
		endGame=1;
		
	}
	else if (tile3.state==tile5.state&&tile3.state==tile7.state&&tile3.state!=empty)
	{
		endGame=1;
		
	}
	else if (tile3.state==tile6.state&&tile3.state==tile9.state&&tile3.state!=empty)
	{
		endGame=1;
		
	}
	else if (tile4.state==tile5.state&&tile4.state==tile6.state&&tile4.state!=empty)
	{
		endGame=1;
		
	}
	else if (tile7.state==tile8.state&&tile7.state==tile9.state&&tile7.state!=empty)
	{
		endGame=1;
		
	}
	else if (tile1.state!=empty&&tile2.state!=empty&&tile3.state!=empty&&tile4.state!=empty&&tile5.state!=empty&&tile6.state!=empty&&tile7.state!=empty&&tile8.state!=empty&&tile9.state!=empty&&endGame!=1)
	{
		endGame=2;
	}
	else
	{
		endGame=0;
	}
	
	if (endGame==1)
	{
		cout<<endl<<"GAME OVER";
		if(playerTurn)
		{
			cout<<endl<<"Congratulations You WON!";
			return 1;
		}
		else
		{
			cout<<endl<<"Sorry you LOST!";
			return 1;
		}
		
	}
	else if (endGame==2)
	{
		cout<<endl<<"GAME OVER"<<endl<<"PLAYER AND COMPUTER TIED!";
	}
	else
	{
		return 0;
	}
}
