//Lab 5 Story
//William Benton Parrish
//10/02/2014


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct userInfo
{
	char name[15];
	int age;
	char pro1[15];
	char pro2[15];
	char pro3[15];
	char pro4[15];	
	char color[15];
	char music[15];
}userInfo;

typedef struct storyElements
{
	int storyLine;
	char vehicle[15];
	char phone[15];
	char drink[15];
	char person[30];
	char quote[100];
	char location[15];	
}storyElements;

void storyRandomizer(storyElements*);
void userIdentity(userInfo*);


main()
{
	
	srand(time(NULL));
	userInfo *user;
	storyElements *story;
	user = (userInfo*)malloc(sizeof(userInfo));
	story = (storyElements*)malloc(sizeof(storyElements));
	storyRandomizer(story);
	userIdentity(user);
	
	printf("\n\nToday is the first day of fall break and %s is preparing for one of the greatest weeks of %s life.",user[0].name,user[0].pro2);
	printf(" %s is about to embark on an all expenses paid trip to %s, which is somewhere %s has always wanted to go, that %s had won when %s turned %d!",user[0].name,story[0].location,user[0].pro3,user[0].pro3,user[0].pro3,user[0].age);
	printf(" However before %s can get a move on, %s has to do some chores to get %s affairs in order",user[0].pro3,user[0].pro3,user[0].pro2);
	printf(" %s starts off %s day with a tall glass of %s.  Feeling invigorated from aforementioned glass of %s, %s gets all of %s chores done almost immediately! \nUsing %s %s %s %s rushes to the airport while blaring %s and hops on a plane but not before making sure %s has %s %s %s.  It's like %s always says %s!",user[0].name,user[0].pro2,story[0].drink,story[0].drink,user[0].name,user[0].pro2,user[0].pro2,user[0].color,story[0].vehicle,user[0].name,user[0].music,user[0].pro3,user[0].pro2,user[0].color,story[0].phone,story[0].person,story[0].quote);
	
	
}

void storyRandomizer(storyElements*story)
{
	int num1=(rand()%2)+1;
	int num2=(rand()%3)+1;
	int num3=(rand()%3)+1;
	int num4=(rand()%3)+1;
	int num5=(rand()%3)+1;
	int num6=(rand()%3)+1;
	int num7=(rand()%3)+1;
	
	story[0].storyLine=num1;
	
	switch(num2)
	{
		case 1:
			{
				strcpy(story[0].vehicle,"bicycle");
				break;
			}
		case 2:
			{
				strcpy(story[0].vehicle,"car");
				break;
			}
		case 3:
			{
				strcpy(story[0].vehicle,"van");
				break;
			}
	}
	switch(num3)
	{
		case 1:
			{
				strcpy(story[0].phone,"iPhone 6");
				break;
			}
		case 2:
			{
				strcpy(story[0].phone,"flip phone");
				break;
			}
		case 3:
			{
				strcpy(story[0].phone,"Samsung Galaxy");
				break;
			}
	}
	switch(num4)
	{
		case 1:
			{
				strcpy(story[0].drink,"whiskey");
				break;
			}
		case 2:
			{
				strcpy(story[0].drink,"orange juice");
				break;
			}
		case 3:
			{
				strcpy(story[0].drink,"milk");
				break;
			}
	}
	switch(num5)
	{
		case 1:
			{
				strcpy(story[0].person,"Professor Yampolskiy");
				break;
			}
		case 2:
			{
				strcpy(story[0].person,"Uncle Billy");
				break;
			}
		case 3:
			{
				strcpy(story[0].person,"President Obama");
				break;
			}
	}
	switch(num6)
	{
		case 1:
			{
				strcpy(story[0].quote,"\"Better to be prepared than to be scared\"");
				break;
			}
		case 2:
			{
				strcpy(story[0].quote,"\"Don't be dumb\"");
				break;
			}
		case 3:
			{
				strcpy(story[0].quote,"\"Never forget your phone\"");
				break;
			}
	}
	switch(num7)
	{
		case 1:
			{
				strcpy(story[0].location,"Mars");
				break;
			}
		case 2:
			{
				strcpy(story[0].location,"Antarctica");
				break;
			}
		case 3:
			{
				strcpy(story[0].location,"Rome");
				break;
			}
	}
	
	
	
	
	
	
	
}

void userIdentity(userInfo*user)
{
	int selection=0;
	printf("\nPlease enter your first name: ");
	scanf("%s",user[0].name);
	printf("\nPlease enter your age: ");
	scanf("%d",&user[0].age);
	printf("\nWhich pronouns do you prefer?\n[1]\tHe, Himself, His\n[2]\tShe, Herself, Her\n[3]\tThey, Themself, Their\n");
	
	
	do
	{
		selection=0;
		printf("\nSelect an Option: ");
		scanf("%d",&selection);
		switch (selection)
		{
			case 1:
				{
					strcpy(user[0].pro1,"himself");
					strcpy(user[0].pro2,"his");
					strcpy(user[0].pro3,"he");
					strcpy(user[0].pro4,"him");
					break;								
				}
			case 2:
				{
					strcpy(user[0].pro1,"herself");
					strcpy(user[0].pro2,"her");
					strcpy(user[0].pro3,"she");
					strcpy(user[0].pro4,"her");
					break;					
					
				
				}
			case 3:
				{
					strcpy(user[0].pro1,"themself");
					strcpy(user[0].pro2,"their");
					strcpy(user[0].pro3,"they");
					strcpy(user[0].pro4,"them");
					break;					
				
				}
			default:
				{
					printf("INVALID OPTION!");
					break;
				}
		}
	}while(selection!=1&&selection!=2&&selection!=3);
	
	printf("\nPlease input your favorite color: ");
	scanf("%s",user[0].color);
	printf("\nPlease input your favorite genre of music: ");
	scanf("%s",user[0].music);
	
	
	
}
