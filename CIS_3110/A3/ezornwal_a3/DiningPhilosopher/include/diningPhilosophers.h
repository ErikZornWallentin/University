/************************* diningPhilosophers.h ****************************
Student Name: Erik Zorn - Wallentin  Student Number: 0864583
Date: Fri, March.27 / 2015           Course Name: CIS*3110
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <semaphore.h>
#include <sys/wait.h>

/*-------
Purpose: Creates the Philosopher's states of thinking, hungry and eating
Parameters: THINKING, HUNGRY, EATING
Return: int values that would represent the enum's
-------*/
enum {THINKING, HUNGRY, EATING } * philoState;

/*-------
Purpose: Function that simulates the Philosopher's getting ready to eat
Parameters: int i (the slot the loop is in *philosopher*), int numOfPhilo ( the total philosopher's )
Return: VOID ( NOTHING )
-------*/
void pickup_chopsticks(int i, int numOfPhilo);

/*-------
Purpose: Function that simulates the Philosopher's getting ready to start thinking again and finish eating
Parameters: int i (the slot the loop is in *philosopher*), int numOfPhilo ( the total philosopher's )
Return: VOID ( NOTHING )
-------*/
void putdown_chopsticks(int i, int numOfPhilo);

/*-------
Purpose: Function that that checks the state of Philosopher's around the Philosopher getting ready to eat
Parameters: int i (the slot the loop is in *philosopher*), int numOfPhilo ( the total philosopher's )
Return: VOID ( NOTHING )
-------*/
void check(int i, int numOfPhilo);
