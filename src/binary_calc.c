#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BITS 8

/* Brady Lange
 * 3/6/18
 * File: binary-calc2.c
 * This program calculates two binary numbers with +, -, x, /, and % using binary arithmetic
 */

// Calling function prototypes to allow main to see the functions
void subtract(char number1[], char number2[], char equals[]);
void addition(char number1[], char number2[], char equals[]);
void multiplication(char number1[], char number2[], char equals[]);
void division(char number1[], char number2[], char equals[]);
void modulus(char number1[], char number2[], char equals[]);

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
		else
			if((strcmp(argv[3], "x")) == 0)
			{
				multiplication(number1, number2, equals);
			}
			else
				if((strcmp(argv[3], "/")) == 0)
				{
					division(number1, number2, equals);
				}
				else
					if((strcmp(argv[3], "%")) == 0)
					{
						modulus(number1, number2, equals);
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
							// Handling underflow and overflow errors
							else 
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
										for(i = 0; i <= BITS ; i++)
										{
											printf("%c", equals[i]);
										}
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

// This function gets the modulus of the two binary numbers
void modulus(char number1[], char number2[], char equals[])
{
	int i = 0;
	
	for(i = BITS - 1; i >= 0; i--)
	{
		if(number1[i] % number2[i] == 0)
			equals[i] = '0';
		else
			if(number[i] % == 1)
				equals[i] = '1';
			else
			{
				printf("Modulus Function: An error has occured!");
				exit(1);
			}
	}
		
	
}

// This function multiplies the two binary numbers 
void multiplication(char number1[], char number2[], char equals[])
{
	int i = 0;
	int k = 0;
	int count = 0;
	
	// These arrays are used to add two binary numbers at a time
	char tempAdd[BITS];
	char firstAdd[BITS];
	char sAdd[BITS];
	char tAdd[BITS];
	char fAdd[BITS];
	char fif[BITS];
	char sixAdd[BITS];
	char sevAdd[BITS];
	char eigAdd[BITS];
	
	// Alorithm to add each binary number together
	for(k = BITS - 1; k >= 0; k--)
	{
		i = 0;
		for(i = BITS - 1; i >= 0; i--)
		{
			if(count == 0)
				addition(number1, number2, equals);
			else
				addition(tempAdd, number2, equals);
			tempAdd[i] = equals[i];
			count++;
		}
		i = 0;
		for(i = BITS - 1; i >= 0; i--)
		{
			if(count == 8)
			{
				firstAdd[i] = tempAdd[i];
				tempAdd[i] = firstAdd[i];
			}	
			else
				if(count == 16)
				{
					sAdd[i] = tempAdd[i];
					tempAdd[i] = sAdd[i];
				}
				else
					if(count == 24)
						tAdd[i] = tempAdd[i];
					else
						if(count == 32)
							fAdd[i] = tempAdd[i];
						else
							if(count == 40)
								fifAdd[i] = tempAdd[i];
							else
								if(count == 48)
									sixAdd[i] = tempAdd[i];
								else
									if(count == 56)
										sevAdd[i] = tempAdd[i];
									else
										if(count == 64)
											eigAdd[i] = tempAdd[i];
						
		}
			
	}
	
	// Adding the results from above
	addition(firstAdd, sAdd, equals);
	addition(equals, tAdd, equals);
	addition(equals, fAdd, equals);
	addition(equals, fifAdd, equals);
	addition(equals, sixAdd, equals);
	addition(equals, sevAdd, equals);
	addition(equals, eigAdd, equals);
	
	
}

// This function divides the two binary numbers
void division(char number1[], char number2[], char equals[])
{
	int i = 0;
	for(i = BITS - 1; i >= 0; i--)
	{
		
	}
	
	// Call the subtraction function
	
	// Call the modulus function 
}

