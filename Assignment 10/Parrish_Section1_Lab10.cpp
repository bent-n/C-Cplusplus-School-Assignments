//Lab 10 3d Tic-Tac-Toe
//William Benton Parrish
//11/20/2014

/*In the C++ programming language write a program
capable of playing 3D Tic-Tac-Toe against the user. Your program should use OOP concepts in
its design. Use Inheritance to create a derived class from your Lab #9 Tic-Tac-Toe class. You
can use ASCII art to generate and display the 3x3x3 playing board. The program should
randomly decide who goes first computer or user. Your program should know and inform the
user if an illegal move was made (cell already occupied). The program should also keep the
score and announce if one of the players wins or if a draw is achieved. While it is desirable for
your program to play a strong game, this is not an Artificial Intelligence course so if your
program does not play at a world champion level you will not be penalized for it.
The object of a 3D-TTT is to get as many 3-in-a-row as possible. You win just like in traditional
TTT, except you can also win by getting 3-in-a-raw down each board. Imagine the boards as
placed on top of each other*/

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
class Board3d: public Board
{

	public:
		Tile tileB1;
		Tile tileB2;
		Tile tileB3;
		Tile tileB4;
		Tile tileB5;
		Tile tileB6;
		Tile tileB7;
		Tile tileB8;
		Tile tileB9;
		Tile tileC1;
		Tile tileC2;
		Tile tileC3;
		Tile tileC4;
		Tile tileC5;
		Tile tileC6;
		Tile tileC7;
		Tile tileC8;
		Tile tileC9;
		Board3d();
		void showBoard(void);
		bool tileChoose(bool, int);
		bool gameCheck(bool);
};


int main()
{
	Board3d board;
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
				selection=(rand()%27)+1;
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
Board3d::Board3d()
{
	Board();
	
	tileB1.set(10);
	tileB2.set(11);
	tileB3.set(12);
	tileB4.set(13);
	tileB5.set(14);
	tileB6.set(15);
	tileB7.set(16);
	tileB8.set(17);
	tileB9.set(18);
	
	tileC1.set(19);
	tileC2.set(20);
	tileC3.set(21);
	tileC4.set(22);
	tileC5.set(23);
	tileC6.set(24);
	tileC7.set(25);
	tileC8.set(26);
	tileC9.set(27);
}
void Board3d::showBoard()
{
		cout<<endl<<"|--------|--------|--------|"<<endl;
		cout<<"|  ("<<tile1.state<<")   |  ("<<tile2.state<<")   |  ("<<tile3.state<<")   |"<<endl<<"|   1    |   2    |   3    |"<<endl;
		cout<<"|--------|--------|--------|"<<endl;
		cout<<"|  ("<<tile4.state<<")   |  ("<<tile5.state<<")   |  ("<<tile6.state<<")   |"<<endl<<"|   4    |   5    |   6    |"<<endl;
		cout<<"|--------|--------|--------|"<<endl;
		cout<<"|  ("<<tile7.state<<")   |  ("<<tile8.state<<")   |  ("<<tile9.state<<")   |"<<endl<<"|   7    |   8    |   9    |"<<endl;
		cout<<"|--------|--------|--------|"<<endl;

		cout<<endl<<"\t\t|--------|--------|--------|"<<endl;
		cout<<"\t\t|  ("<<tileB1.state<<")   |  ("<<tileB2.state<<")   |  ("<<tileB3.state<<")   |"<<endl<<"\t\t|   10   |   11   |   12   |"<<endl;
		cout<<"\t\t|--------|--------|--------|"<<endl;
		cout<<"\t\t|  ("<<tileB4.state<<")   |  ("<<tileB5.state<<")   |  ("<<tileB6.state<<")   |"<<endl<<"\t\t|   13   |   14   |   15   |"<<endl;
		cout<<"\t\t|--------|--------|--------|"<<endl;
		cout<<"\t\t|  ("<<tileB7.state<<")   |  ("<<tileB8.state<<")   |  ("<<tileB9.state<<")   |"<<endl<<"\t\t|   16   |   17   |   18   |"<<endl;
		cout<<"\t\t|--------|--------|--------|"<<endl;

		cout<<endl<<"\t\t\t\t|--------|--------|--------|"<<endl;
		cout<<"\t\t\t\t|  ("<<tileC1.state<<")   |  ("<<tileC2.state<<")   |  ("<<tileC3.state<<")   |"<<endl<<"\t\t\t\t|   19   |   20   |   21   |"<<endl;
		cout<<"\t\t\t\t|--------|--------|--------|"<<endl;
		cout<<"\t\t\t\t|  ("<<tileC4.state<<")   |  ("<<tileC5.state<<")   |  ("<<tileC6.state<<")   |"<<endl<<"\t\t\t\t|   22   |   23   |   24   |"<<endl;
		cout<<"\t\t\t\t|--------|--------|--------|"<<endl;
		cout<<"\t\t\t\t|  ("<<tileC7.state<<")   |  ("<<tileC8.state<<")   |  ("<<tileC9.state<<")   |"<<endl<<"\t\t\t\t|   25   |   26   |   27   |"<<endl;
		cout<<"\t\t\t\t|--------|--------|--------|"<<endl;
	
}	
bool Board3d::tileChoose(bool playerTurn, int selection)
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
			case 10:
				{
					return tileB1.playerChoose();
					break;
				}
			case 11:
				{
					return tileB2.playerChoose();
					break;
				}
			case 12:
				{
					return tileB3.playerChoose();
					break;
				}
			case 13:
				{
					return tileB4.playerChoose();
					break;
				}
			case 14:
				{
					return tileB5.playerChoose();
					break;
				}
			case 15:
				{
					return tileB6.playerChoose();
					break;
				}
			case 16:
				{
					return tileB7.playerChoose();
					break;
				}
			case 17:
				{
					return tileB8.playerChoose();
					break;
				}
			case 18:
				{
					return tileB9.playerChoose();
					break;
				}
			case 19:
				{
					return tileC1.playerChoose();
					break;
				}
			case 20:
				{
					return tileC2.playerChoose();
					break;
				}
			case 21:
				{
					return tileC3.playerChoose();
					break;
				}
			case 22:
				{
					return tileC4.playerChoose();
					break;
				}
			case 23:
				{
					return tileC5.playerChoose();
					break;
				}
			case 24:
				{
					return tileC6.playerChoose();
					break;
				}
			case 25:
				{
					return tileC7.playerChoose();
					break;
				}
			case 26:
				{
					return tileC8.playerChoose();
					break;
				}
			case 27:
				{
					return tileC9.playerChoose();
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
			case 10:
				{
					return tileB1.computerChoose();
					break;
				}
			case 11:
				{
					return tileB2.computerChoose();
					break;
				}
			case 12:
				{
					return tileB3.computerChoose();
					break;
				}
			case 13:
				{
					return tileB4.computerChoose();
					break;
				}
			case 14:
				{
					return tileB5.computerChoose();
					break;
				}
			case 15:
				{
					return tileB6.computerChoose();
					break;
				}
			case 16:
				{
					return tileB7.computerChoose();
					break;
				}
			case 17:
				{
					return tileB8.computerChoose();
					break;
				}
			case 18:
				{
					return tileB9.computerChoose();
					break;
				}
			case 19:
				{
					return tileC1.computerChoose();
					break;
				}
			case 20:
				{
					return tileC2.computerChoose();
					break;
				}
			case 21:
				{
					return tileC3.computerChoose();
					break;
				}
			case 22:
				{
					return tileC4.computerChoose();
					break;
				}
			case 23:
				{
					return tileC5.computerChoose();
					break;
				}
			case 24:
				{
					return tileC6.computerChoose();
					break;
				}
			case 25:
				{
					return tileC7.computerChoose();
					break;
				}
			case 26:
				{
					return tileC8.computerChoose();
					break;
				}
			case 27:
				{
					return tileC9.computerChoose();
					break;
				}
			default:
				{
					return 0;
				}
			
		}
		
		
		
	}
	
	
}
bool Board3d::gameCheck(bool playerTurn)
{
	int endGame=0;
	char empty=' ';
	char player='X';
	int playerScore=0;
	int computerScore=0;
	//BOARD A POSSIBILITIES
	if (tile1.state==tile2.state&&tile1.state==tile3.state&&tile1.state!=empty)
	{
		if(tile1.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile1.state==tile4.state&&tile1.state==tile7.state&&tile1.state!=empty)
	{
		if(tile1.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile1.state==tile5.state&&tile1.state==tile9.state&&tile1.state!=empty)
	{
		if(tile1.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile2.state==tile5.state&&tile2.state==tile8.state&&tile2.state!=empty)
	{
		if(tile2.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile3.state==tile5.state&&tile3.state==tile7.state&&tile3.state!=empty)
	{
		if(tile3.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		};
		
	}
	if (tile3.state==tile6.state&&tile3.state==tile9.state&&tile3.state!=empty)
	{
		if(tile3.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile4.state==tile5.state&&tile4.state==tile6.state&&tile4.state!=empty)
	{
		if(tile4.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile7.state==tile8.state&&tile7.state==tile9.state&&tile7.state!=empty)
	{
		if(tile7.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	//BOARD B POSSIBILITIES
	if (tileB1.state==tileB2.state&&tileB1.state==tileB3.state&&tileB1.state!=empty)
	{
		if(tileB1.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tileB1.state==tileB4.state&&tileB1.state==tileB7.state&&tileB1.state!=empty)
	{
		if(tileB1.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tileB1.state==tileB5.state&&tileB1.state==tileB9.state&&tileB1.state!=empty)
	{
		if(tileB1.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tileB2.state==tileB5.state&&tileB2.state==tileB8.state&&tileB2.state!=empty)
	{
		if(tileB2.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tileB3.state==tileB5.state&&tileB3.state==tileB7.state&&tileB3.state!=empty)
	{
		if(tileB3.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		};
		
	}
	if (tileB3.state==tileB6.state&&tileB3.state==tileB9.state&&tileB3.state!=empty)
	{
		if(tileB3.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tileB4.state==tileB5.state&&tileB4.state==tileB6.state&&tileB4.state!=empty)
	{
		if(tileB4.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tileB7.state==tileB8.state&&tileB7.state==tileB9.state&&tileB7.state!=empty)
	{
		if(tileB7.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	//BOARD C POSSIBILITIES
	if (tileC1.state==tileC2.state&&tileC1.state==tileC3.state&&tileC1.state!=empty)
	{
		if(tileC1.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tileC1.state==tileC4.state&&tileC1.state==tileC7.state&&tileC1.state!=empty)
	{
		if(tileC1.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tileC1.state==tileC5.state&&tileC1.state==tileC9.state&&tileC1.state!=empty)
	{
		if(tileC1.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tileC2.state==tileC5.state&&tileC2.state==tileC8.state&&tileC2.state!=empty)
	{
		if(tileC2.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tileC3.state==tileC5.state&&tileC3.state==tileC7.state&&tileC3.state!=empty)
	{
		if(tileC3.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		};
		
	}
	if (tileC3.state==tileC6.state&&tileC3.state==tileC9.state&&tileC3.state!=empty)
	{
		if(tileC3.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tileC4.state==tileC5.state&&tileC4.state==tileC6.state&&tileC4.state!=empty)
	{
		if(tileC4.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tileC7.state==tileC8.state&&tileC7.state==tileC9.state&&tileC7.state!=empty)
	{
		if(tileC7.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	//MULTI BOARD POSSIBILITIES
	if (tile1.state==tileB1.state&&tile1.state==tileC1.state&&tile1.state!=empty)
	{
		if(tile1.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile1.state==tileB2.state&&tile1.state==tileC3.state&&tile1.state!=empty)
	{
		if(tile1.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile1.state==tileB4.state&&tile1.state==tileC7.state&&tile1.state!=empty)
	{
		if(tile1.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile1.state==tileB5.state&&tile1.state==tileC9.state&&tile1.state!=empty)
	{
		if(tile1.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile2.state==tileB2.state&&tile2.state==tileC2.state&&tile2.state!=empty)
	{
		if(tile2.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile2.state==tileB5.state&&tile2.state==tileC8.state&&tile2.state!=empty)
	{
		if(tile2.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile3.state==tileB3.state&&tile3.state==tileC3.state&&tile3.state!=empty)
	{
		if(tile3.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		};
		
	}
	if (tile3.state==tileB2.state&&tile3.state==tileC1.state&&tile3.state!=empty)
	{
		if(tile3.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		};
		
	}
	if (tile3.state==tileB6.state&&tile3.state==tileC9.state&&tile3.state!=empty)
	{
		if(tile3.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		};
		
	}
	if (tile3.state==tileB5.state&&tile3.state==tileC7.state&&tile3.state!=empty)
	{
		if(tile3.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		};
		
	}
	if (tile4.state==tileB4.state&&tile4.state==tileC4.state&&tile4.state!=empty)
	{
		if(tile4.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		};
		
	}
	if (tile4.state==tileB5.state&&tile4.state==tileC6.state&&tile4.state!=empty)
	{
		if(tile4.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		};
		
	}
	if (tile5.state==tileB5.state&&tile5.state==tileC5.state&&tile5.state!=empty)
	{
		if(tile5.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		};
		
	}
	if (tile6.state==tileB6.state&&tile6.state==tileC6.state&&tile6.state!=empty)
	{
		if(tile6.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		};
		
	}
	if (tile6.state==tileB5.state&&tile6.state==tileC4.state&&tile6.state!=empty)
	{
		if(tile6.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		};
		
	}
	if (tile7.state==tileB7.state&&tile7.state==tileC7.state&&tile7.state!=empty)
	{
		if(tile7.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile7.state==tileB4.state&&tile7.state==tileC1.state&&tile7.state!=empty)
	{
		if(tile7.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile7.state==tileB8.state&&tile7.state==tileC9.state&&tile7.state!=empty)
	{
		if(tile7.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile7.state==tileB5.state&&tile7.state==tileC3.state&&tile7.state!=empty)
	{
		if(tile7.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile8.state==tileB8.state&&tile8.state==tileC8.state&&tile8.state!=empty)
	{
		if(tile8.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile8.state==tileB5.state&&tile8.state==tileC2.state&&tile8.state!=empty)
	{
		if(tile8.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile9.state==tileB9.state&&tile9.state==tileC9.state&&tile9.state!=empty)
	{
		if(tile9.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile9.state==tileB6.state&&tile9.state==tileC3.state&&tile9.state!=empty)
	{
		if(tile9.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile9.state==tileB8.state&&tile9.state==tileC7.state&&tile9.state!=empty)
	{
		if(tile9.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	if (tile9.state==tileB5.state&&tile9.state==tileC1.state&&tile9.state!=empty)
	{
		if(tile9.state==player)
		{
			playerScore++;
		}
		else
		{
			computerScore++;
		}
		
	}
	//GAME OVER
	if (tile1.state!=empty&&tile2.state!=empty&&tile3.state!=empty&&tile4.state!=empty&&tile5.state!=empty&&tile6.state!=empty&&tile7.state!=empty&&tile8.state!=empty&&tile9.state!=empty&&tileB1.state!=empty&&tileB2.state!=empty&&tileB3.state!=empty&&tileB4.state!=empty&&tileB5.state!=empty&&tileB6.state!=empty&&tileB7.state!=empty&&tileB8.state!=empty&&tileB9.state!=empty&&tileC1.state!=empty&&tileC2.state!=empty&&tileC3.state!=empty&&tileC4.state!=empty&&tileC5.state!=empty&&tileC6.state!=empty&&tileC7.state!=empty&&tileC8.state!=empty&&tileC9.state!=empty)
	{
		endGame=1;
	}
	else
	{
		endGame=0;
	}
	
	if (endGame==1)
	{
		cout<<endl<<"GAME OVER";
		cout<<endl<<"Player Score: "<<playerScore<<endl<<"Computer Score: "<<computerScore;
		if(playerScore>computerScore)
		{
			cout<<endl<<"Congratulations You WON!";
			return 1;
		}
		else if(computerScore>playerScore)
		{
			cout<<endl<<"Sorry you LOST!";
			return 1;
		}
		else if(playerScore==computerScore)
		{
			cout<<endl<<"PLAYER AND COMPUTER TIED!";
			return 1;
		}
		
	}
	else
	{
		cout<<endl<<"Player Score: "<<playerScore<<endl<<"Computer Score: "<<computerScore;
		return 0;
	}
}
