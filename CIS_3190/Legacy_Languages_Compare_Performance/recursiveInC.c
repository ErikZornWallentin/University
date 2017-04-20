/************************* recursiveInC.c ****************************
Student Name: Erik Zorn - Wallentin  Student Number: 0864583
Date: Thur, April.2 / 2015           Course Name: CIS*3190 (DE)
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

/* Program calculates ackermann function recursively in FORTRAN 90
   Takes in two numbers and calculates the result */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

/* Function Prototypes */
int ackermann(int m, int n);

int main()
{
	int ackermannResult = 0;
	int userInput1 = 0;
	int userInput2 = 0;
   
	printf("Ackermann function recursive in C: Enter two numbers (Below 4 for a quick result)\n");
	printf("Please enter number 1: \n");
	scanf("%d", &userInput1);
	printf("Please enter number 2: \n");
	scanf("%d", &userInput2);
   
	/* Starting the timer ! 1mil microseconds is 1 second! */
	clock_t launch = clock();
	/* Calling Ackermann Function to calculate the given numbers */
	ackermannResult = ackermann(userInput1,userInput2);
	
	// Stop timer
	clock_t done = clock();
	
	printf("Ackermann Result: %d\n", ackermannResult);
	
	double timeResult = (done - launch) / CLOCKS_PER_SEC;
	printf("Time taken to calculate in seconds: %f\n", timeResult);
	
	return 0;
}

/*----
Purpose: The purpose of this function is to calculate the result using Ackermann's Function.
Parameters: int m (the first number to calculate), int n (the second number to calculate)
Return: returns an integer
----*/
int ackermann(int m, int n)
{
	if (m == 0)
	{
		return n + 1;
	}
   
	if (m > 0 && n == 0) 
	{
		return ackermann (m - 1, 1);
	}
   
	return ackermann (m - 1, ackermann(m, n - 1));
}