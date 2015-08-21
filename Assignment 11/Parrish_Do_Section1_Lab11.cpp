//Lab 11 3d Tic-Tac-Toe PARTNER PROJECT
//William Benton Parrish
//Brandon Do
//12/04/2014

/*Ability to work in teams is essential for a successful
career in computer science. Begin this lab by finding a partner who has completed lab#10. You
can work with anyone registered for CECS130 from either Tuesday or Thursday lab section.
Your assignment is to create (in the C++ programming language using good OOP principles
(namespaces, etc.)) a Competition class which inherits from yours and your partner’s 3D TTT
classes. Assuming both 3DTTT classes have a function which asks computer to make a move it
should be possible with very little rewriting to create a competition between two computer
players. Set it up so the two game bots play 10 games in a row against each other and a winner is
determined and announced at the end of this competition. Give your computer players names
which correspond to the names of the two programmers who created them.*/

#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include <windows.h>
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
class ParrBoard: public Board
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
		ParrBoard();
		void showBoard(void);
		bool tileChoose(bool, int);
		bool gameCheck(bool);
};
class DoBoard
{
	public:
		Tile tile1a;
		Tile tile2a;
		Tile tile3a;
		Tile tile4a;
		Tile tile5a;
		Tile tile6a;
		Tile tile7a;
		Tile tile8a;
		Tile tile9a;
		Tile tile1b;
		Tile tile2b;
		Tile tile3b;
		Tile tile4b;
		Tile tile5b;
		Tile tile6b;
		Tile tile7b;
		Tile tile8b;
		Tile tile9b;
		Tile tile1c;
		Tile tile2c;
		Tile tile3c;
		Tile tile4c;
		Tile tile5c;
		Tile tile6c;
		Tile tile7c;
		Tile tile8c;
		Tile tile9c;
		
		DoBoard();
		//void showBoard(void);
		//bool tileChoose(bool, int);
		bool gameCheck(bool);
};
class ProBoard: public DoBoard, public ParrBoard
{
	public:
	ProBoard();
	int gameCheck(bool);
	void clearBoard(void);
};
int main()
{
	ProBoard board;
	srand(time(NULL));
	//bool playerTurn=1;
	bool playerTurn=(rand()%2);
	int gameOver=0;
	int selection;
	bool endTurn;
	while(gameOver!=1)
	{
		board.showBoard();
		do
		{
			if(playerTurn)
			{
				cout<<endl<<"Benton's Turn!";
				selection=(rand()%27)+1;
				endTurn=board.tileChoose(playerTurn, selection);
				 if (endTurn)
				{
					gameOver=board.gameCheck(playerTurn);
					playerTurn=0;
				}
			
			}
			else
			{
				//Sleep(5000);
				cout<<endl<<"Brandon's Turn";
				selection=(rand()%27)+1;
				endTurn=board.tileChoose(playerTurn, selection);
				if(endTurn)
				{
					gameOver=board.gameCheck(playerTurn);
					playerTurn=1;
				}
			}	
			if (gameOver==2)
			{
				board.showBoard();
				board.clearBoard();
			}	
		
		}while(endTurn==0);
	
		
	}
	
	
	
	
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
ParrBoard::ParrBoard()
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
void ParrBoard::showBoard()
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
bool ParrBoard::tileChoose(bool playerTurn, int selection)
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
bool ParrBoard::gameCheck(bool playerTurn)
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
DoBoard::DoBoard()
{
	tile1a.set(1);
	tile2a.set(2);
	tile3a.set(3);
	tile4a.set(4);
	tile5a.set(5);
	tile6a.set(6);
	tile7a.set(7);
	tile8a.set(8);
	tile9a.set(9);
	tile1b.set(1);
	tile2b.set(2);
	tile3b.set(3);
	tile4b.set(4);
	tile5b.set(5);
	tile6b.set(6);
	tile7b.set(7);
	tile8b.set(8);
	tile9b.set(9);
	tile1c.set(1);
	tile2c.set(2);
	tile3c.set(3);
	tile4c.set(4);
	tile5c.set(5);
	tile6c.set(6);
	tile7c.set(7);
	tile8c.set(8);
	tile9c.set(9);
}
/*void DoBoard::showBoard()
{
		//Board A
		cout<<endl<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<tile1a.state<<")  |  ("<<tile2a.state<<")  |  ("<<tile3a.state<<")  |"<<endl<<"|   1a   |   2a   |   3a   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<tile4a.state<<")  |  ("<<tile5a.state<<")  |  ("<<tile6a.state<<")  |"<<endl<<"|   4a   |   5a   |   6a   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<tile7a.state<<")  |  ("<<tile8a.state<<")  |  ("<<tile9a.state<<")  |"<<endl<<"|   7a   |   8a   |   9a   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
		//Board B
		cout<<endl<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<tile1b.state<<")  |  ("<<tile2b.state<<")  |  ("<<tile3b.state<<")  |"<<endl<<"|   1b   |   2b   |   3b   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<tile4b.state<<")  |  ("<<tile5b.state<<")  |  ("<<tile6b.state<<")  |"<<endl<<"|   4b   |   5b   |   6b   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<tile7b.state<<")  |  ("<<tile8b.state<<")  |  ("<<tile9b.state<<")  |"<<endl<<"|   7b   |   8b   |   9b   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
		//Board C
		cout<<endl<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<tile1c.state<<")  |  ("<<tile2c.state<<")  |  ("<<tile3c.state<<")  |"<<endl<<"|   1c   |   2c   |   3c   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<tile4c.state<<")  |  ("<<tile5c.state<<")  |  ("<<tile6c.state<<")  |"<<endl<<"|   4c   |   5c   |   6c   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<tile7c.state<<")  |  ("<<tile8c.state<<")  |  ("<<tile9c.state<<")  |"<<endl<<"|   7c   |   8c   |   9c   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
}*/
/*bool DoBoard::tileChoose(bool playerTurn, int selection)
{
	int subselection;
	
	if(playerTurn)
	{
		switch(selection)
		{
			case 1:
				{
					cout<<endl<<"What board do you want to place on, [1]A, [2]B, or [3]C?"<<endl;
					switch(subselection)
					{
						case 1:
							{
							return tile1a.playerChoose();
							break;
							}
						case 2:
							{
							return tile1b.playerChoose();
							break;
							}
						case 3:
							{
							return tile1c.playerChoose();
							break;
							}
						default:
							{
							return 0;
							}
					}
				}
			case 2:
				{
					cout<<endl<<"What board do you want to place on, [1]A, [2]B, or [3]C?"<<endl;
					switch(subselection)
					{
						case 1:
							{
							return tile2a.playerChoose();
							break;
							}
						case 2:
							{
							return tile2b.playerChoose();
							break;
							}
						case 3:
							{
							return tile2c.playerChoose();
							break;
							}
						default:
							{
							return 0;
							}
					}
				}
			case 3:
				{
						cout<<endl<<"What board do you want to place on, [1]A, [2]B, or [3]C?"<<endl;
					switch(subselection)
					{
						case 1:
							{
							return tile3a.playerChoose();
							break;
							}
						case 2:
							{
							return tile3b.playerChoose();
							break;
							}
						case 3:
							{
							return tile3c.playerChoose();
							break;
							}
						default:
							{
							return 0;
							}
					}
				}

			case 4:
				{
						cout<<endl<<"What board do you want to place on, [1]A, [2]B, or [3]C?"<<endl;
					switch(subselection)
					{
						case 1:
							{
							return tile4a.playerChoose();
							break;
							}
						case 2:
							{
							return tile4b.playerChoose();
							break;
							}
						case 3:
							{
							return tile4c.playerChoose();
							break;
							}
						default:
							{
							return 0;
							}
					}
				}
			case 5:
				{
						cout<<endl<<"What board do you want to place on, [1]A, [2]B, or [3]C?"<<endl;
					switch(subselection)
					{
						case 1:
							{
							return tile5a.playerChoose();
							break;
							}
						case 2:
							{
							return tile5b.playerChoose();
							break;
							}
						case 3:
							{
							return tile5c.playerChoose();
							break;
							}
						default:
							{
							return 0;
							}
					}
				}
			case 6:
				{
						cout<<endl<<"What board do you want to place on, [1]A, [2]B, or [3]C?"<<endl;
					switch(subselection)
					{
						case 1:
							{
							return tile6a.playerChoose();
							break;
							}
						case 2:
							{
							return tile6b.playerChoose();
							break;
							}
						case 3:
							{
							return tile6c.playerChoose();
							break;
							}
						default:
							{
							return 0;
							}
					}
				}
			case 7:
				{
						cout<<endl<<"What board do you want to place on, [1]A, [2]B, or [3]C?"<<endl;
					switch(subselection)
					{
						case 1:
							{
							return tile7a.playerChoose();
							break;
							}
						case 2:
							{
							return tile7b.playerChoose();
							break;
							}
						case 3:
							{
							return tile7c.playerChoose();
							break;
							}
						default:
							{
							return 0;
							}
					}
				}
			case 8:
				{
						cout<<endl<<"What board do you want to place on, [1]A, [2]B, or [3]C?"<<endl;
					switch(subselection)
					{
						case 1:
							{
							return tile8a.playerChoose();
							break;
							}
						case 2:
							{
							return tile8b.playerChoose();
							break;
							}
						case 3:
							{
							return tile8c.playerChoose();
							break;
							}
						default:
							{
							return 0;
							}
					}
				}
			case 9:
				{
						cout<<endl<<"What board do you want to place on, [1]A, [2]B, or [3]C?"<<endl;
					switch(subselection)
					{
						case 1:
							{
							return tile9a.playerChoose();
							break;
							}
						case 2:
							{
							return tile9b.playerChoose();
							break;
							}
						case 3:
							{
							return tile9c.playerChoose();
							break;
							}
						default:
							{
							return 0;
							}
					}
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
					return tile1a.computerChoose();
					break;
				}
			case 2:
				{
					return tile2a.computerChoose();
					break;
				}
			case 3:
				{
					return tile3a.computerChoose();
					break;
				}
			case 4:
				{
					return tile4a.computerChoose();
					break;
				}
			case 5:
				{
					return tile5a.computerChoose();
					break;
				}
			case 6:
				{
					return tile6a.computerChoose();
					break;
				}
			case 7:
				{
					return tile7a.computerChoose();
					break;
				}
			case 8:
				{
					return tile8a.computerChoose();
					break;
				}
			case 9:
				{
					return tile9a.computerChoose();
					break;
				}
			case 10:
				{
					return tile1b.computerChoose();
					break;
				}
			case 11:
				{
					return tile2b.computerChoose();
					break;
				}
			case 12:
				{
					return tile3b.computerChoose();
					break;
				}
			case 13:
				{
					return tile4b.computerChoose();
					break;
				}
			case 14:
				{
					return tile5b.computerChoose();
					break;
				}
			case 15:
				{
					return tile6b.computerChoose();
					break;
				}
			case 16:
				{
					return tile7b.computerChoose();
					break;
				}
			case 17:
				{
					return tile8b.computerChoose();
					break;
				}
			case 18:
				{
					return tile9b.computerChoose();
					break;
				}
			case 19:
				{
					return tile1c.computerChoose();
					break;
				}
			case 20:
				{
					return tile2c.computerChoose();
					break;
				}
			case 21:
				{
					return tile3c.computerChoose();
					break;
				}
			case 22:
				{
					return tile4c.computerChoose();
					break;
				}
			case 23:
				{
					return tile5c.computerChoose();
					break;
				}
			case 24:
				{
					return tile6c.computerChoose();
					break;
				}
			case 25:
				{
					return tile7c.computerChoose();
					break;
				}
			case 26:
				{
					return tile8c.computerChoose();
					break;
				}
			case 27:
				{
					return tile9c.computerChoose();
					break;
				}
			default:
				{
					return 0;
				}	
		}
	}
	
	
}*/
bool DoBoard::gameCheck(bool playerTurn)
{
	int playerPoint=0;
	int computerPoint=0;
	char empty=' ';
	if (tile1a.state==tile2a.state&&tile1a.state==tile3a.state&&tile1a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}
					
	}
	else if (tile1b.state==tile2b.state&&tile1b.state==tile3b.state&&tile1b.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}		
	}
	else if (tile1c.state==tile2c.state&&tile1c.state==tile3c.state&&tile1c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}		
	else if (tile1a.state==tile4a.state&&tile1a.state==tile7a.state&&tile1a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile1b.state==tile4b.state&&tile1b.state==tile7b.state&&tile1b.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile1c.state==tile4c.state&&tile1c.state==tile7c.state&&tile1c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile1a.state==tile5a.state&&tile1a.state==tile9a.state&&tile1a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile1b.state==tile5b.state&&tile1b.state==tile9b.state&&tile1b.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile1c.state==tile5c.state&&tile1c.state==tile9c.state&&tile1c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile3a.state==tile5a.state&&tile3a.state==tile7a.state&&tile3a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile3b.state==tile5b.state&&tile3b.state==tile7b.state&&tile3b.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile3c.state==tile5c.state&&tile3c.state==tile7c.state&&tile3c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile3a.state==tile6a.state&&tile3a.state==tile9a.state&&tile3a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile3b.state==tile6b.state&&tile3b.state==tile9b.state&&tile3b.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile3c.state==tile6c.state&&tile3c.state==tile9c.state&&tile3c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}		
	}
	else if (tile4a.state==tile5a.state&&tile4a.state==tile6a.state&&tile4a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile4b.state==tile5b.state&&tile4b.state==tile6b.state&&tile4b.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile4c.state==tile5c.state&&tile4c.state==tile6c.state&&tile4c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile7a.state==tile8a.state&&tile7a.state==tile9a.state&&tile7a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}			
	}
	else if (tile7b.state==tile8b.state&&tile7b.state==tile9b.state&&tile7b.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile7c.state==tile8c.state&&tile7c.state==tile9c.state&&tile7c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile2a.state==tile5a.state&&tile2a.state==tile8a.state&&tile2a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile2b.state==tile5b.state&&tile2b.state==tile8b.state&&tile2b.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile2c.state==tile5c.state&&tile2c.state==tile8c.state&&tile2c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile1a.state==tile1b.state&&tile1a.state==tile1c.state&&tile1a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile2a.state==tile2b.state&&tile2a.state==tile2c.state&&tile2a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile3a.state==tile3b.state&&tile3a.state==tile3c.state&&tile3a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}	
	else if (tile4a.state==tile4b.state&&tile4a.state==tile4c.state&&tile4a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}	
	else if (tile5a.state==tile5b.state&&tile5a.state==tile5c.state&&tile5a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile6a.state==tile6b.state&&tile6a.state==tile6c.state&&tile6a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile7a.state==tile7b.state&&tile7a.state==tile7c.state&&tile7a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile8a.state==tile8b.state&&tile8a.state==tile8c.state&&tile8a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile9a.state==tile9b.state&&tile9a.state==tile9c.state&&tile9a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile1a.state==tile2b.state&&tile1a.state==tile3c.state&&tile1a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}	
	else if (tile1c.state==tile2b.state&&tile1c.state==tile3a.state&&tile1c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}		
	else if (tile4a.state==tile5b.state&&tile4a.state==tile6c.state&&tile4a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}	
	else if (tile4c.state==tile5b.state&&tile4c.state==tile6a.state&&tile4c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}	
	else if (tile7a.state==tile8b.state&&tile7a.state==tile9c.state&&tile7a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}	
	else if (tile7c.state==tile8b.state&&tile7c.state==tile9a.state&&tile7c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}	
	else if (tile1a.state==tile4b.state&&tile1a.state==tile4b.state&&tile1a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}	
	else if (tile1c.state==tile4b.state&&tile1c.state==tile7a.state&&tile1c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}	
	else if (tile2a.state==tile5b.state&&tile2a.state==tile8c.state&&tile2a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}	
	else if (tile2c.state==tile5b.state&&tile2c.state==tile8a.state&&tile2c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}	
	else if (tile3a.state==tile6b.state&&tile3a.state==tile9c.state&&tile3a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}	
	else if (tile3c.state==tile6b.state&&tile3c.state==tile9a.state&&tile3c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}	
	else if (tile1a.state==tile5b.state&&tile1a.state==tile9c.state&&tile1a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile1c.state==tile5b.state&&tile1c.state==tile9a.state&&tile1c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile3a.state==tile5b.state&&tile3a.state==tile7c.state&&tile3a.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
	else if (tile3c.state==tile5b.state&&tile3c.state==tile7a.state&&tile3c.state!=empty)
	{
		if (playerTurn)
		{
			playerPoint = playerPoint + 1;
		}
		else
		{
			computerPoint = computerPoint + 1;
		}	
	}
}
ProBoard::ProBoard()
{
	ParrBoard();
}
int ProBoard::gameCheck(bool playerTurn)
{
	int endGame=0;
	char empty=' ';
	char player='X';
	int playerScore=0;
	int computerScore=0;
	static int bentonGamesWon=0;
	static int brandonGamesWon=0;
	static int gamesPlayed=0;
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
	
	if (endGame==1&&gamesPlayed!=10)
	{
		ProBoard();
		cout<<endl<<"GAME OVER";
		gamesPlayed++;
		cout<<endl<<"Benton Score: "<<playerScore<<endl<<"Brandon Score: "<<computerScore;
		if(playerScore>computerScore)
		{
			cout<<endl<<"Congratulations, Benton! You WON!";
			bentonGamesWon++;
		
		}
		else if(computerScore>playerScore)
		{
			cout<<endl<<"Congratulations, Brandon! You WON!";
			brandonGamesWon++;
			
		}
		else if(playerScore==computerScore)
		{
			cout<<endl<<"BENTON AND BRANDON TIED!";
			bentonGamesWon++;
			brandonGamesWon++;
		
		}
		if(gamesPlayed!=10)
		{
		 cout<<endl<<"Games:"<<gamesPlayed;
		 //Sleep (5000);	
		return 2;
		}
	}
	if(gamesPlayed==10)
	{
		cout<<endl<<endl<<endl<<"Games:"<<gamesPlayed;
		cout<<endl<<"MATCH OVER";
		cout<<endl<<"Benton Match Score: "<<bentonGamesWon<<endl<<"Brandon Match Score: "<<brandonGamesWon<<endl<<"Draws: "<<bentonGamesWon+brandonGamesWon-gamesPlayed;
		if(bentonGamesWon>brandonGamesWon)
		{
			cout<<endl<<"Congratulations, Benton! You WON THE MATCH!";
			cout<<endl<<"BRANDON IS A LOSER!";
		}
		else if(brandonGamesWon>bentonGamesWon)
		{
			cout<<endl<<"Congratulations, BRANDON! You WON THE MATCH!";
			cout<<endl<<"BENTON IS A LOSER!";
		}
		else if(bentonGamesWon==brandonGamesWon)
		{
			cout<<endl<<"BENTON AND BRANDON TIED!";
			cout<<endl<<"Congratulations YOU BOTH WON!";
			cout<<endl<<"OR LOST!"<<endl<<"It depends on how you look at it.";	
		}
		
		return 1;
	}
	else
	{
		cout<<endl<<"Player Score: "<<playerScore<<endl<<"Computer Score: "<<computerScore;
		
		return 0;
	}
	
	
}
void ProBoard::clearBoard()
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
