/*************************q2.c****************************
Student Name: Erik Zorn - Wallentin  Student Number: 0864583
Date: Mon, Oct.13 / 2014             Course Name: CIS2520
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Global variables
int stack[100];
int top = -1;

//function prototypes
void push(int result);
int pop();

int main (int argc, char *argv[])
{  
                      
    char * userInput;
    int n = 0;
	int firstNum = 0;
	int secondNum = 0;
	char value = '0';
	char pusher = '0';
	char nullTerm = '0';
    
	if (argc == 2)
	{
		userInput = argv[1];

		while( ( value = userInput[n] ) != '\0')
		{
			if( isdigit(value) )
			{
				/* Push the char and null terminator */
				pusher = value - nullTerm;
				push(pusher);
			}
			else
			{
				/* Pop secondNum and firstNum onto the stack */
				secondNum = pop();
				firstNum = pop();
				
				if (value == '+')
				{
					push(firstNum + secondNum);
				}
				else if (value == '-')
				{
					push(firstNum - secondNum);	
				}
				else if (value == '/')
				{
					push(firstNum / secondNum);	
				}
				else if (value == '*')
				{
					push(firstNum * secondNum);	
				}
			}
			
			n = n + 1;
		}

		printf("Postfix Expression: %s\n", userInput);
		printf("Evaluated Result: %d\n", stack[top]);
	}
	else if (argc >= 3)
	{
		printf("ERROR: Too many arguments found, try only 1 expression with no spaces!\n"); /* Exit the program */
	}
	else
	{
		printf("ERROR: No arguments were found, please give a postfix expression!\n"); /* Exit the program */
	}
	return 0;
}

/*----
Purpose: Function to push the value into the stack
Parameters: int result (the operation result does calculation before entering function)
Return: nothing
----*/
void push(int result)
{
	top++;
    stack[top] = result;
}
 
/*----
Purpose: Function to return a popped value
Parameters: nothing
Return: int (return the popped value)
----*/
int pop()
{
    int value = 0;
	
	value = stack[top];
	top--;
	
	return value;
}