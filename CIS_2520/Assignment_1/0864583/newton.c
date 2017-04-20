/*************************newton.c****************************
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
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Function Prototypes
void nonRecursionFunc(double x, double a, double epsilon, clock_t begin1, clock_t end1, double timeTaken1);
void recursionFunc(double x, double a, double epsilon, clock_t begin2, clock_t end2, double timeTaken2);

//Everything is done in main, if you want to compile and test just this remove the comments below
/*
int main()
{
    double number = 0;
    double epsilon = 0.000001; //10^-2 to 10^-6 accuracy of epsilon using 10^-6
    
	//Setup clock variables to calculate the time taken
    clock_t begin1, begin2, end1, end2;
    double timeTaken1, timeTaken2;
    
    printf("Calculate square root of x by Newtons Method\n");
    printf("Please enter a number: \n");
    scanf("%lf", &number);
    
    double calculate1 = number / 2; //initial calculation
	
	//Call the non-recursion and recursion functions for Newton's Method
    nonRecursionFunc(number, calculate1, epsilon, begin1, end1, timeTaken1);
    recursionFunc(number, calculate1, epsilon, begin2, end2, timeTaken2);
    
    return 0;
}*/

/*----
Purpose: The purpose of this function is to calculate the non-recursion method of square root for newton's method 
         and calculates the time taken to do it.
Parameters: double x (number to square root), double a( first part of calculation for newton's method), double epsilon (accuracy), 
            clock_t (begin1 and end1 of clock variables), double timeTaken1 (the total time taken for function)
Return: void (nothing)
----*/
void nonRecursionFunc(double x, double a, double epsilon, clock_t begin1, clock_t end1, double timeTaken1)
{	
	begin1 = clock();
	
    while ((a * a - x) >= epsilon)
    {
        a = ( a + x / a ) / 2;
    }
    
    end1 = clock();
    timeTaken1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    
    printf("Non-recursion result: %f\n", a);
    printf("Non-recursion Time Taken: %f ms\n", timeTaken1);
}

/*----
Purpose: The purpose of this function is to calculate the recursion method of square root for newton's method 
         and calculates the time taken to do it.
Parameters: double x (number to square root), double a( first part of calculation for newton's method), double epsilon (accuracy), 
            clock_t (begin2 and end2 of clock variables), double timeTaken2 (the total time taken for function)
Return: void (nothing)
----*/
void recursionFunc(double x, double a, double epsilon, clock_t begin2, clock_t end2, double timeTaken2)
{
    begin2 = clock();
   
    if ((a * a - x) <= epsilon)
    {
    	end2 = clock();
    	timeTaken2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    	
        printf("Recursion result: %f\n", a);
        printf("Recursion Time Taken: %f ms\n", timeTaken2);
    }
    else
    {
        a = ( a + x / a ) / 2;
        recursionFunc(x,a,epsilon, begin2, end2, timeTaken2);
    }
}