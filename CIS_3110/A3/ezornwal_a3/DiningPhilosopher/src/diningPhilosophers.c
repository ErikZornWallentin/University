/************************* diningPhilosophers.c ****************************
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

#include "diningPhilosophers.h"

sem_t sem;

int main(int argc, char * argv[])
{
	
	/* Declare a semaphore variable and initialize it to the value of 1 */
	sem_init(&sem, 0, 1);
	
	pid_t pid;
	
	int i = 0;
	
	int totalTimeEaten = 0;
	int numOfPhilo = 0;
	int numOfTimesToEat = 0;
	
	int status = 0;
	
	
	if(argc != 3) 
	{
		printf("ERROR: Please input a number greater than 2 for philosophers and how many times they should eat (1-1000)!\n");
		exit(1);
	}
	
	numOfPhilo = atoi(argv[1]);
	if ( numOfPhilo <= 2)
	{
		printf("ERROR: Number of Philosophers was less than 2! Please give a number greater than 2!\n");
		exit(1);
	}
	
	numOfTimesToEat = atoi(argv[2]);
	if (numOfTimesToEat > 1000 || numOfTimesToEat < 1)
	{
		printf("ERROR: How many times they should eat was not in between (1-1000)!\n");
		exit(1);
	}
	
	printf("There are %d philosophers and they will eat %d times.\n\n", numOfPhilo, numOfTimesToEat);
	
	philoState = malloc(sizeof(int) * numOfPhilo);
	if (philoState == NULL)
	{	
		printf("ERROR: Creating memory for the Philosopher's failed!\n");
		exit(1);
	}

	for(i = 0; i < numOfPhilo; i++) 
	{
		if ((pid = fork()) == 0)
		{
			while(totalTimeEaten < numOfTimesToEat) 
			{
				printf("Philosopher %d thinking\n", i + 1);
				
				/* Philosopher starts eating ! */
				pickup_chopsticks(i, numOfPhilo);
				
				sleep(1);
				/* Philosopher stops eating ! */
				putdown_chopsticks(i, numOfPhilo);
				
				totalTimeEaten = totalTimeEaten + 1;
			}
		}
	}

	while ((pid = wait(&status)) > 0)
    {
        //printf("Exit status of %d was %d (%s)\n", (int)wpid, status, (status > 0) ? "accept" : "reject");
    }
    
    /* Free up memory here */
    free(philoState);
	return 0;
}

void pickup_chopsticks(int i, int numOfPhilo) 
{
	philoState[i] = HUNGRY;
	
	check(i, numOfPhilo);
	if (philoState[i] != EATING)
	{
		sem_wait(&sem);
	}
}

void putdown_chopsticks(int i, int numOfPhilo) 
{
	philoState[i] = THINKING;
	
	//check((i + 1) % numOfPhilo, numOfPhilo);
	//check((i+(numOfPhilo - 1) % numOfPhilo), numOfPhilo);
	check(((i + (numOfPhilo - 1)) % numOfPhilo), numOfPhilo);
	check(((i + 1) % numOfPhilo), numOfPhilo);
}

void check(int i, int numOfPhilo) 
{
	int nextPhilo = 0;
	
	/* Check the philosopher's near the one that is given, so the one on the left and right of him/her */
	if ((philoState[i] == HUNGRY) && (philoState[(i + (numOfPhilo - 1)) % numOfPhilo] != EATING) && (philoState[(i + 1) % numOfPhilo] != EATING)) 
	{
		philoState[i] = EATING;
		nextPhilo = i + 1;
		
		printf("Philosopher %d eating\n", nextPhilo);
		sem_post(&sem);
		printf("Philosopher %d has stopped eating\n", nextPhilo);
	}
}
