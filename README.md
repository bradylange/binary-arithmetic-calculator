# binary-arithmetic-calculator
C binary arithmetic calculator with inputs of two binary values and one mathematical operator.

Brady Lange

03/7/2018

Op Sys Programming

Assignment 2

## `src/binary_add_sub_calc.c
This program takes two 8-bit binary numbers and an operator which is either + or -.
Based upon the operator a calculation will be executed with binary arithmetic. 
Calculations that lead to overflows or underflows will be handled. The program consists
of 2 functions addition and subtraction which operate as their name would with 
binary numbers. If the input contains a '+' the addition function will be called otherwise if
its a '-' a subtraction function will be called. In the addition function if else 
statements in a loop compare each position in the two numbers with each other.
In the subtraction function the bits are flipped always on the second number and then one
is added to it. If the first number is negative it will receive 2's complement as well.
After the bits have been flipped the addition function is called to calculate the 
result.

Input: `a.out 00000010 00000011 +`

Output: `00000101`

## `src/binary_calc.c`
This program extends `src/binary_add_sub_calc.c` in which the operator can be +, -, x, /, or %.
Based upon the operator a calculation will be executed with binary arithmetic.
Calculations that lead to overflows or underflows will be handled.

Input: `a.out 00000100 00000010 x`

Output: `00001000`

## Issues:
- `binary_add_sub_calc.c`: Did not print result
- `binary_calc.c`: Incomplete