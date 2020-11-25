#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BITS 8

/* 
 * Brady Lange
 * 3/5/18
 * File: binary-calc.c
 * This program calculates (addition or subtraction) of two 8 bit binary numbers and returns the result in binary
 */

// Calling function prototypes to allow main to see the functions
void subtract(char number1[], char number2[], char equals[]);
void addition(char number1[], char number2[], char equals[]);

int main(int argc, char *argv[])
{

	// 2 Bin numbers and a result
	char number1[BITS];
	char number2[BITS];
	char equals[BITS];

	// Counter
	int i;

	// Retrieving the binary bits from each number
	while(argv[1][i] != '\0')
	{
		number1[i] = argv[1][i];
		number2[i] = argv[2][i];
		i++;
	}

	// Addition function call if the operator is "+"
	if((strcmp(argv[3], "+")) == 0)
	{
		addition(number1, number2, equals);
	}

	// Subtraction function call if operator is "-"
	else 
		if((strcmp(argv[3], "-")) == 0)           
		{ 
			subtraction(number1, number2, equals);
		}

	return 0;

} // End of main function


// Binary Addition (Adding binary bits together)
void addition(char number1[], char number2[], char equals[])
{
	// Counter
	int i = 0;
	// Storing how many bits are being carried during addition
	int carry = 0;

	for(i = BITS - 1; i >= 0; i--)
	{
		if(number1[i] == '0' && number2[i] == '0' && carry == 0)
		{
			carry = 0;
			equals[i] = '0';
		}
		else 
			if(number1[i] == '0' && number2[i] == '0' && carry == 1)
			{
				carry  = 0;
				equals[i] = '1';
			}
			else 
				if(((number1[i] == '1' && number2[i] == '0') || (number1[i] == '0' && number2[i] == '1')) && carry == 0)
				{
					equals[i] = '1';
					carry = 0;
				}
				else 
					if(((number1[i] == '1' && number2[i] == '0') || (number1[i] == '0' && number2[i] == '1')) && carry == 1)
					{
						equals[i] = '0';
						carry = 1;
					}
					else 
						if(number1[i] == '1' && number2[i] == '1' && carry == 1)
						{
							carry = 1;
							equals[i] = '1';
						}
						else 
							if(number1[i] == '1' && number2[i] == '1' && carry == 0)
							{
								carry = 1;
								equals[i] = '0';
							}
	}

		// Handling underflow and overflow errors
		if(number1[0] == '1' && number2[0] == '1' && equals[0] == '0')
		{
			printf("Underflow error: Two negative numbers don't equal a positive.");
			exit(1);
		}
		else 
			if(number1[0] == '0' && number2[0] == '0' && equals[0] == '1')
			{
				printf("Overflow error: Two positive numbers don't equal a negative.");
				exit(1);
			}
			else 
			{
				printf("\nThe two binary numbers equal: ");
				for(i = 0; i <= BITS - 1 ; i++)
				{
					printf("%c", equals[i]);
				}
			}
	

} // End of function addition

// Binary subtraction (Subtracting binary numbers)
void subtraction(char number1[], char number2[], char equals[])
{
	int i = 0;
	
	// If the first number is negative enter
	if(number1[0] == '1')
	{
		// Flip the bits (1's complement)
		for(i = BITS - 1; i >= 0; i--)
		{
			if(number1[i] == '0')
				number1[i] = '1';
			else
				number1[i] = '0';
		}
	
		// 2's complement - add 1 to the binary number
		for(i = BITS - 1; i >= 0; i--)
		{
			if(number1[i] == '0')
			{
				number1[i] = '1';
				break;
			}
			else
				number1[i] = '0';
		}
	}
	
	// If the second number is negative or positive enter 
	if(number2[0] == '1' || number2[0] == '0')
	{
		// Flip the bits (1's complement)
		for(i = BITS - 1; i >= 0; i--)
		{

			if(number2[i] == '0')
				number2[i] = '1';
			else
				number2[i] = '0';
		}
		
		// 2's complement - add 1 to the binary number
		for(i = BITS - 1; i >= 0; i--)
		{
			if(number1[i] == '0')
			{
				number1[i] = '1';
				break;
			}
			else
				number1[i] = '0';
		}
	}

	//Use the addition function to add the binary numbers together after they have been altered 
	addition(number1, number2, equals);

} //End of function subtract





