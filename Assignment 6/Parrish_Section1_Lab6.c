//Lab 6 Phone Book
//William Benton Parrish
//10/01/2014


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct entry
{
	char fName[15];
	char lName[15];
	char phone[15];
	
}entry;

void addFriend(entry*,int*);
void delFriend(entry*,int*);
void showBook(entry*,int*);




main()
{
	int selection = 0;
	int entryNum = 0;
	entry *phoneBook;
	phoneBook = (entry*)malloc(sizeof(entry));
	do
	{
		printf("\nPhone Book\n[1]\tAdd Friend\n[2]\tDelete Friend\n[3]\tShow Phone Book\n[0]\tExit\n:");
		scanf("%d",&selection);		
		switch(selection)
		{
		case 1:
			{
			 printf("\nYou have selected \"Add Friend\".");
			 entryNum++;
			 addFriend(phoneBook,&entryNum);
			 
			 break;
			}
		case 2:
			{
			 printf("\nYou have selected \"Delete Friend\".");
			 
			 delFriend(phoneBook,&entryNum);
			 break;
			}
		case 3:
			{
			 printf("\nYou have selected \"Show Phone Book\".");
			 showBook(phoneBook,&entryNum);
			 
			 break;
			}
		case 0:
			{
			 printf("\nYou have selected \"Exit\".");
			 printf("\nHave a nice day!");
			 free(phoneBook);
			 break;
			}
		default:
			{
				printf("\nINVALID OPTION!");
				break;
			}
		
		}
		
		
	}while (selection!=0);
}
void addFriend(entry*phoneBook,int * entryNum)
{
	if (*entryNum==0)
	{
		
	phoneBook = (entry*)realloc(phoneBook, (sizeof(entry)*2));
	}
	else if (*entryNum>0)
	{
		phoneBook = (entry*)realloc(phoneBook, (sizeof(entry)*(*entryNum))+sizeof(entry));
	}
	
	
	if(phoneBook!=NULL)
	{
		
	
		printf("\nEntry Number: %d",*entryNum);
		printf("\nFirst Name: ");
		scanf("%s",phoneBook[*entryNum].fName);
		printf("\nLast Name: ");
		scanf("%s",phoneBook[*entryNum].lName);
		printf("\nPhone Number (Format: xxx-xxxx): ");
		scanf("%s",phoneBook[*entryNum].phone);
	}
	else
	{
		printf("\nNOT ENOUGH MEMORY!");
	}
}
void delFriend(entry*phoneBook,int * entryNum)
{
	int num;
	int delNum;
	char tempFName[15]={'\0'};
	char tempLName[15]={'\0'};
	char tempPhone[15]={'\0'};
	int selection=0;
	printf("\nFirst Name: ");
	scanf("%s",tempFName);
	printf("\nLast Name: ");
	scanf("%s",tempLName);
	for(num=0;num<=*entryNum+1;num++)
	{
		if (strcmp(tempFName,phoneBook[num].fName)==0&&strcmp(tempLName,phoneBook[num].lName)==0)
		{
			delNum=num;
			printf("\nDelete Entry Number:%d\nFirst Name:\t%s\nLast Name:\t%s\nPhone Number:\t%s",num,phoneBook[num].fName,phoneBook[num].lName,phoneBook[num].phone);
			printf("\n\n[1]\tYes\n[2]\tNo\n: ");
			scanf("%d",&selection);
			switch(selection)
			{
				case 1:
					{
						for(num=delNum+1;num<=*entryNum+1;num++)//Shift all entries after deleted entry up
						{
							strcpy(phoneBook[num-1].fName,phoneBook[num].fName);
							strcpy(phoneBook[num-1].lName,phoneBook[num].lName);
							strcpy(phoneBook[num-1].phone,phoneBook[num].phone);
							
						}
						*entryNum=*entryNum-1;
							
						if (*entryNum!=0)
						{				
						phoneBook = (entry*)realloc(phoneBook, (sizeof(entry)*(*entryNum+1)));
						
						}
						else if (entryNum>0)
						{
							phoneBook = (entry*)realloc(phoneBook, 2*(sizeof(entry)));
						}
						break;
					}
				case 2:
					{
						printf("Deletion Cancelled!");
						break;
					}
			}
			break;
			
		}
		else if (num>*entryNum)
		{
			printf("No matching entry found!");
		}
	}
	
}
void showBook(entry*phoneBook,int* entryNum)
{
	int num;
	for (num=1;num<=*entryNum;num++)
	{
		printf("\nEntry Number: %d\nFirst Name:\t%s\nLast Name:\t%s\nPhone Number:\t%s\n",num,phoneBook[num].fName,phoneBook[num].lName,phoneBook[num].phone);
	}
}

