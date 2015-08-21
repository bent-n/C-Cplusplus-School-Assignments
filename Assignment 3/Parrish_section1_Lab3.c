// Lab 3 Simple Calculator
// William Benton Parrish
// 09/09/14
// Section 1


/*Write a computer program in C which will simulate a
calculator. Your calculator needs to support the five basic operations (addition, subtraction,
multiplication, division and modulus) plus primality testing (natural number is prime if it has no
non-trivial divisors).*/

#include <stdio.h>
main()
{
	int selection=0;
	float x=0;
	float y=0;
	int ix=0;
	int iy=0;
	int c; //counter
	int notPrime;
	
	
	do{ //Begin do while
		notPrime = 0;
		printf("\nCalculator Menu\n\n");
		printf("[1]\tAddition\n");
		printf("[2]\tSubtraction\n");
		printf("[3]\tMultiplication\n");
		printf("[4]\tDivision\n");
		printf("[5]\tModulus (Integers Only)\n");
		printf("[6]\tPrime Test (Integers Only)\n");
		printf("[7]\tExit\n");
		
		printf("\nPlease Select an option: ");
		scanf("%d",&selection);
		
		switch (selection){
			case 1:{//addition
				printf("\nYou have selected \"Addition\"");
				printf("\nx + y = ?");
				printf("\nPlease input a value for \"x\": ");
				scanf("%f",&x);
				printf("\nPlease input a value for \"y\": ");
				scanf("%f",&y);
				printf("\n%.3f + %.3f = %.3f\n",x,y,x+y);
				printf("\n-------------------------------------------");
				break;
			}//End addition
			case 2:{//subtraction
				printf("\nYou have selected \"Subtraction\"");
				printf("\nx - y = ?");
				printf("\nPlease input a value for \"x\": ");
				scanf("%f",&x);
				printf("\nPlease input a value for \"y\": ");
				scanf("%f",&y);
				printf("\n%.3f - %.3f = %.3f\n",x,y,x-y);
				printf("\n-------------------------------------------");
				break;
			}//end subtraction
			case 3:{//multiplication
				printf("\nYou have selected \"Multiplication\"");
				printf("\nx * y = ?");
				printf("\nPlease input a value for \"x\": ");
				scanf("%f",&x);
				printf("\nPlease input a value for \"y\": ");
				scanf("%f",&y);
				printf("\n%.3f * %.3f = %.3f\n",x,y,x*y);
				printf("\n-------------------------------------------");
				break;
			}//end multiplication
			case 4:{//division
				printf("\nYou have selected \"Division\"");
				printf("\nx // y = ?");
				printf("\nPlease input a value for \"x\": ");
				scanf("%f",&x);
				printf("\nPlease input a value for \"y\": ");
				scanf("%f",&y);
				printf("\n%.3f // %.3f = %.3f\n",x,y,x/y);
				printf("\n-------------------------------------------");
				break;
			}//end division
			case 5:{//modulus
				printf("\nYou have selected \"Modulus\"");
				printf("\nx %% y = ?");
				printf("\nPlease input an integer value for \"x\": ");
				scanf("%d",&ix);
				printf("\nPlease input an integer value for \"y\": ");
				scanf("%d",&iy);
				printf("\n%d %% %d = %d\n",ix,iy,ix%iy);
				printf("\n-------------------------------------------");
				break;
			}//end modulus
			case 6:{//prime test
				printf("\nYou have selected \"Prime Test\"");
				printf("\nTest if x is prime");
				printf("\nPlease input an integer value for \"x\": ");
				scanf("%d",&ix);
				for(c=2; c<=ix/2;++c){//begin for
					if(ix%c==0 && notPrime==0){//begin if
						notPrime=1;
						break;											
					}//end if
					else if(ix%c!=0&&notPrime==0){//begin else
						notPrime=0;									
					}//end else
				}//end for
				if(notPrime==1){//begin if
					printf("\n%d is not a prime number!",ix);
					printf("\n%d * %d = %d",c,ix/c,ix);
				}//end if
				else if(notPrime==0){//begin if
					printf("\n%d is a prime number!",ix);
					break;
				}//end if
				printf("\n-------------------------------------------");
				break;
			}//end prime test
			case 7:{//exit
				printf("\nHave a nice day!");
				break;
			}//end exit
			default:{//invalid
				printf("\nInvalid Option");
				printf("\n-------------------------------------------");
				break;
			}//end invalid
			
		}//end switch
		
		
	} while(selection!=7);//end do while
	return 0;
	
	
	
	
	
	
	
}
