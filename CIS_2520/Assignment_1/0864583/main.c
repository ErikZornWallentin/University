/*************************main.c****************************
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
#include <string.h>
#include "carbon.c"
#include "ackermann.c"
#include "newton.c"

//Function Prototypes
void menu();


int main()
{
    char userInput = '0';         /* The main menu user input variable */
    int checker = 1;              /* Checks if user wants to quit or not variable in main menu */
            
    do
    {
        /* Call the main menu function to display the main menu */
        menu();
        userInput = getchar(); 
        
        if (userInput == '1') //Call the carbon.c function
        {
     		carbonFunc();
        }
        
        /* Call the ackermann.c function */
        else if (userInput == '2') 
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
        }
        
		/* Call the newton.c function */
        else if (userInput == '3')
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
        }
		        
        else if (userInput == 'q')
        {
            printf("Now quitting the program!\n");	
            checker = 0;	
        }
        
        else
        {
            printf("Incorrect input, try again!\n");		
        }
    }while(checker == 1);			
    
    return 0;
}

/* The main menu function */
void menu()
{ 	
    printf("\nPlease choose one of the following using (1,2,3):\n");
    printf("1) Carbon File\n");
    printf("2) Ackermann's Function\n");
    printf("3) Newton's Method\n");
    printf("Quit the program (q)\n");  
}