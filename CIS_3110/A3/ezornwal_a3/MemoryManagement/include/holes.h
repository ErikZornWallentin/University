/************************* holes.h ****************************
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Simulates memory is of size 128MB */
#define MEM_SIZE 128

typedef int bool;
enum {false, true};

struct Node 
{
	char pid;                    /* The process ID                                         */
	int size;                    /* Size of the process in MB range 1-128                  */
	int swapCounter;             /* Counts the times process has been swapped, 3 is limit  */
	int memoryLocation;          /* Process location in memory                             */
	
	struct Node * next;          /* To next process                                        */
};
typedef struct Node node;
typedef node * head;

/* Global variables to keep track of mem usage, the average of mem and the total loads ! */
float cumulativeMemUsage = 0.0;
int memUsageCounter = 0;

float averageProcesses = 0.0;
int averageProcessesCounter = 0;

float averageMemoryNotUsed = 0.0;
int averageMemoryNotUsedCounter = 0;

int totalLoads = 0;

/*----
Purpose: Prints out the menu for the user to see
Parameters: VOID ( NOTHING )
Return: VOID ( NOTHING )
----*/
void printMenu();

/*----
Purpose: Prints out the elements in the node that are in the queue
Parameters: head normQueue ( the normal queue list )
Return: VOID ( NOTHING )
----*/
void printQueue(head normQueue);

/*----
Purpose: Resets all the global variables to allow the user to use any menu option at any time
Parameters: VOID ( NOTHING )
Return: VOID ( NOTHING )
----*/
void resetEverything();

/*----
Purpose: Removes the first node in the normal queue
Parameters: head normQueue ( the normal queue list )
Return: head normQueue (returns a pointer to the new head of the list, which is the 2nd node is now the 1st node)
----*/
head removeFirst(head normQueue);

/*----
Purpose: Gets the first node in the normal queue
Parameters: head normQueue ( the normal queue list )
Return: node ( pointing to the FIRST node in the list )
----*/
node * getFront(head normQueue);

/*----
Purpose: Gets the last node in the normal queue
Parameters: head normQueue ( the normal queue list )
Return: node ( pointing to the LAST node in the list )
----*/
node * getBack (head normQueue);

/*----
Purpose: Inserts node to the back
Parameters: head normQueue ( the normal queue list ), node * nextAdded ( next node to add)
Return: head normQueue ( returns a pointer to the new head of the list )
----*/
head insertNode(head normQueue, node * nextAdded);

/*----
Purpose: Removes from the back
Parameters: head normQueue ( the normal queue list ),
Return: head normQueue ( returns a pointer to the new head of the list )
----*/
head removeFromBack(head normQueue);

/*----
Purpose: This is used to continuously make a new copy of the queue so I can use when I want to switch my menu option -Duplicate of the file queue!
Parameters: head normQueue ( the normal queue list ),
Return: head normQueue ( returns a pointer to the new head of the list )
----*/
head duplicate(head normQueue);

/*----
Purpose: This function is to print all the details for the loaded pid or final results!
Parameters: bool checker ( checks false to display pid loaded stuff, true to display final info)
            int memory[] ( the memory array in 128 memory size), node ** memoryQue ( the loaded process )
Return: VOID ( NOTHING )
----*/
void printInfo(bool checker, int memory[], node ** memoryQue, head memQueu);

/*----
Purpose: This function is to create the memory queue and add processes onto it
Parameters: head memQue (head to the memory que), node ** processToPutIn (process that is being put in)
Return: head memQue ( returns a pointer to the new head of the list )
----*/
head createMemQue(head memQue, node ** processToPutIn);

/*----
Purpose: This function is to find the oldest process and remove it from memory que
Parameters: head memQue (head to the memory que)
Return: head memQue ( returns a pointer to the new head of the list )
----*/
node * removeOldestProcess(node ** memoryQue);

/*----
Purpose: This function is to do the FIRST fit algorithm
Parameters: head normQueue ( head of the normal queue list ), node** memQue(element to memory que)
Return: head memQue ( returns a pointer to the new head of the list )
----*/
int firstFitAlgorithm(head normQue, node **memoryQue);

/*----
Purpose: This function is to do the BEST fit algorithm
Parameters: head normQueue ( head of the normal queue list ), node** memQue(element to memory que)
Return: head memQue ( returns a pointer to the new head of the list )
----*/
int bestFitAlgorithm(head normQue, node **memoryQue);

/*----
Purpose: This function is to do the WORST fit algorithm
Parameters: head normQueue ( head of the normal queue list ), node** memQue(element to memory que)
Return: head memQue ( returns a pointer to the new head of the list )
----*/
int worstFitAlgorithm(head normQue, node **memoryQue);

/*----
Purpose: This function is to do the NEXT fit algorithm
Parameters: head normQueue ( head of the normal queue list ), node** memQue(element to memory que)
Return: head memQue ( returns a pointer to the new head of the list )
----*/
int nextFitAlgorithm(head normQue, node **memoryQue);
