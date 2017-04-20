/*************************ackermann.c****************************
Student Name: Erik Zorn - Wallentin  Student Number: 0864583
Date: Fri, Sept.26 / 2014              Course Name: CIS2520
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

//Function Prototypes
int ackermann(int m, int n);

//Everything is done in main, if you want to compile and test just this remove the comments below
/*
int main()
{
   int ackermannResult = 0;
   int userInput1 = 0;
   int userInput2 = 0;
   
   printf("Ackermann function: Enter two numbers (Below 4 for a quick result)\n");
   printf("Please enter number 1: \n");
   scanf("%d", &userInput1);
   printf("Please enter number 2: \n");
   scanf("%d", &userInput2);
   
   //Call Ackermann Function
   ackermannResult = ackermann(userInput1,userInput2);
   printf("Ackermann Result: %d\n", ackermannResult);
   
   return 0;
}*/

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