//Lab 4 Function Calculator
//William Benton Parrish
//9/23/2014


#include<stdio.h>
//Function Prototypes
float addTwoNumbers(float,float);
float subTwoNumbers(float,float);
float multTwoNumbers(float,float);
float divTwoNumbers(float,float);
int modTwoNumbers(int,int);
int primeFactor(int);
int factorial(int);
float powerOf (float,int);
int fibonacci (int);
// my function?
//end prototypes

main()
{
	int selection = 0;
	int c=0;
	
	do //begin do while
	{
		float x=0;
		float y=0;
		float fResult=0;
		int ix=0;
		int iy=0;
		int iResult=0;
		int factor=0;
		int temp=0;
		int*pResult=0;
	printf("\nCalculator Menu\n\n");
	printf("[1]\tAddition\n");
	printf("[2]\tSubtraction\n");
	printf("[3]\tMultiplication\n");
	printf("[4]\tDivision\n");
	printf("[5]\tModulus (Integers Only)\n");
	printf("[6]\tPrime Test (Integers Only)\n");
	printf("[7]\tFactorial (Integers Only)\n");
	printf("[8]\tPower\n");
	printf("[9]\tFibonacci Sequence\n");
	printf("[0]\tExit\n");
		
	printf("\nPlease Select an option: ");
	scanf("%d",&selection);
	
	switch(selection)
	{
		case 1://Addition
			{
				printf("\nYou have selected \"Addition\"");
				printf("\nx + y = ?");
				printf("\nPlease input a value for \"x\": ");
				scanf("%f",&x);
				printf("\nPlease input a value for \"y\": ");
				scanf("%f",&y);
				addTwoNumbers(x,y);
				printf("\n-------------------------------------------");
				break;
			}
		case 2://Subtraction
			{
				printf("\nYou have selected \"Subtraction\"");
				printf("\nx - y = ?");
				printf("\nPlease input a value for \"x\": ");
				scanf("%f",&x);
				printf("\nPlease input a value for \"y\": ");
				scanf("%f",&y);
				subTwoNumbers(x,y);
				printf("\n-------------------------------------------");
				break;
			}
		case 3://Multiplication
			{
				printf("\nYou have selected \"Multiplication\"");
				printf("\nx * y = ?");
				printf("\nPlease input a value for \"x\": ");
				scanf("%f",&x);
				printf("\nPlease input a value for \"y\": ");
				scanf("%f",&y);
				multTwoNumbers(x,y);
				printf("\n-------------------------------------------");
				break;
			}
		case 4://Division
			{
				printf("\nYou have selected \"Division\"");
				printf("\nx // y = ?");
				printf("\nPlease input a value for \"x\": ");
				scanf("%f",&x);
				printf("\nPlease input a value for \"y\": ");
				scanf("%f",&y);
				divTwoNumbers(x,y);
				printf("\n-------------------------------------------");
				break;
			}
		case 5://Modulus
			{
				printf("\nYou have selected \"Modulus\"");
				printf("\nx %% y = ?");
				printf("\nPlease input an integer value for \"x\": ");
				scanf("%d",&ix);
				printf("\nPlease input an integer value for \"y\": ");
				scanf("%d",&iy);
				modTwoNumbers(ix,iy);
				printf("\n-------------------------------------------");
				break;
			}
		case 6://Prime Test
			{
				printf("\nYou have selected \"Prime Test\"");
				printf("\nTest if x is prime");
				printf("\nPlease input an integer value for \"x\": ");
				scanf("%d",&ix);
				primeFactor(ix);
				printf("\n-------------------------------------------");
				break;
			}
			case 7://Factorial
			{
				printf("\nYou have selected \"Factorial\"");
				printf("\nx!");
				printf("\nPlease input an integer value for \"x\": ");
				scanf("%d",&ix);	
				factorial(ix);
				printf("\n-------------------------------------------");
				break;	
					
			}
			case 8://Power
			{
				printf("\nYou have selected \"Power\"");
				printf("\nx to the power of y");
				printf("\nPlease input a value for \"x\": ");
				scanf("%f",&x);
				printf("%f",x);
				printf("\nPlease input an integer value for \"y\": ");
				scanf("%d",&ix);
				powerOf(x,ix);
				printf("\n-------------------------------------------");
				break;
			}
			case 9://Fibonacci
			{
				printf("\nYou have selected \"Fibonacci Sequence\"");
				printf("\nDisplay the Fibonacci Sequence up to and including n=x");
				printf("\nPlease input an integer value for \"x\": ");
				scanf("%d",&ix);	
				fibonacci(ix);
				printf("\n-------------------------------------------");
				break;				
			}
			case 0://Exit
			{
				printf("\nHave a nice day!");
				printf("\n-------------------------------------------");
				break;
			}
			default://Invalid
			{
				printf("\nInvalid Option!\nPlease sekect a valid option!");
				printf("\n-------------------------------------------");
				break;
			}
	}
	
	
	
	}while(selection!=0);
	
	return 0;
}
//function definitions
float addTwoNumbers(float num1,float num2)
{
	printf("\n%.3f + %.3f = %.3f\n",num1,num2,num1+num2);
	return num1+num2;
}
float subTwoNumbers(float num1,float num2)
{
	printf("\n%.3f - %.3f = %.3f\n",num1,num2,num1-num2);
	return num1-num2;
}
float multTwoNumbers(float num1,float num2)
{
	printf("\n%.3f * %.3f = %.3f\n",num1,num2,num1*num2);
	return num1*num2;
}
float divTwoNumbers(float num1,float num2)
{
	printf("\n%.3f / %.3f = %.3f\n",num1,num2,num1/num2);
	return num1/num2;
}
int modTwoNumbers(int num1,int num2)
{
	printf("\n%d %% %d = %d\n",num1,num2,num1%num2);
	return num1%num2;
}


int primeFactor(int num1)
{
	int notPrime=0;
	int c;
	for(c=2; c<=num1/2;++c)
	{//begin for
		if(num1%c==0 && notPrime==0)
		{//begin if
			notPrime=1;
			break;											
		}//end if
		else if(num1%c!=0&&notPrime==0)
		{//begin else
			notPrime=0;									
		}//end else
	
	}//end for	
	if (notPrime==1)
	{
		printf("\n%d is not a prime number!",num1);
		printf("\n%d * %d = %d",c,num1/c,num1);
		return c;
	}
	else if (notPrime==0)
	{
		printf("\n%d is a prime number!",num1);
		return 0;
	}
	}
int factorial(int num1)
{
	int c;
	int result=num1;
	c=num1;
	printf("\n%d",c);
	for(c=num1;c>1;c)
	{
		c=c-1;
		printf(" * %d",c);
	}
	for(c=num1;c>=1;c--)
	{
		result=(result*(--num1));
		if (num1==1)
		{
			break;
		}
	}
	if(result<0)
	{
		printf("\n\nNumber is TOO BIG!!!");
	}
	else
	{
		printf("\n= %d",result);
	}
	return result;
}
float powerOf(float num1,int num2)
{
	float result=num1;
	int c=num2;
	for(c;c>1;c--)	
	{
		result=num1*result;
	}
	if (result<0&&num1>0)
	{
		printf("\n\nNumber is TOO BIG!!!");
	}
		printf("\n%f to the power of %d = %f",num1,num2,result);
	return result;
	
	
}
int fibonacci(int num1)
{
	int fibArray[num1];
	int c=0;
	
	int x=1;
	int y=1;
	int temp=0;
	fibArray[0]=0;
	fibArray[1]=1;
	fibArray[2]=1;
	num1++;
	for (c=3;c<=num1;c++)
	{
		temp=x;
		fibArray[c]=x+y;
		x=x+y;
		y=temp;
		
	}
	printf("\n[n]\tFibonacci Value");
	for(c=0;c<num1;c++)
	{
		printf("\n[%d]\t%d",c,fibArray[(c)]);
	}
	return fibArray[c];
}
