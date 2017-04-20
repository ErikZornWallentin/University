/************************* dog_info.c ****************************
Student Name: Erik Zorn - Wallentin       Student Number: 0864583
Date: Thur, Oct.03 / 2013                 Course Name: CIS1500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

/*
	This program was created during my 1st year of Software Engineering at University of Guelph.
	It is a very simple script for an assignment in my CIS*1500 class.
	Since this is a script I did in 1st year of University, this is not a current representation of my skill after graduating University of Guelph in Software Engineering.
	
	The script is about getting dog information from the user.

	The program will ask the user for several inputs and the first two need characters from keyboard.
	Next the first input from user requires a first and last name to work properly, the dog's name does not.
	After the user gives unput to the dog's name, everything else will require numbers for the program to work properly.
	When the user input is done, it will do some background work and output all the data to the screen.

*/

#include <stdio.h>

int main(){
	char ownerName[10] = "";            /* Owner name */
	char ownerLastName[10] = "";        /* Owner last name */
	char dogName[10] = "";              /* Dog's name */
	double dogWeight = 0;               /* Dog's weight */
	double stayLength = 0;              /* Days stayed */
	double price = 0;                   /* Price of dog */
	double total = 0;                   /* Total cost of dog's stay */	

	/* Getting all the inputs from the user */
	printf("\nPlease enter the owner's name (firstname lastname with 2 inputs using a space): ");
	scanf("%s %s",ownerName, ownerLastName);
	printf("Please enter the dog's name: ");
	scanf("%s",dogName);
	printf("Please enter the dog's weight: ");
	scanf("%lf",&dogWeight);
	printf("Please enter the length of stay: ");
	scanf("%lf",&stayLength);

	/* Here is the calculations for the dogWeight, the pounds of dog determines how much it will cost */
	if (dogWeight < 25){
		price = 25;
	}

	if (dogWeight > 25 && dogWeight < 80){
		price = 30;
	}
	
	if (dogWeight > 80){
		price = 35;
	}
	
	/* This calculates the total cost of visit */
	total = price * stayLength;  

	/* Printing all the information to the screen */
	printf("\nOwner name: %s %s\n", ownerName, ownerLastName);
	printf("Dog name: %s\n", dogName);
	printf("Dog weight: %.0lflbs\n", dogWeight);
	printf("Stay length: %.0lf days\n", stayLength);
	printf("The cost per day is: %.0lf\n", price);
	printf("The total cost of the visit is: $%.0lf\n", total);

	return 0;
}