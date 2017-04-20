/************************* holes.c ****************************
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

#include "holes.h"

int main(int argc, char * argv[]) 
{
	/* setup variables for the queue and node */
	node * createProcess = NULL;
	head headProcessQue = NULL;                   /* Head of the waiting queue */
	head tempQue = NULL;                          /* temp queue */
	head allocatedQue = NULL;                     /* Point to the queue processes that are allocated to memory */
	int n = 0;
	
	int result = 1;
	
	FILE * file = NULL;
	char buf[50][10];
	char * token;
	char userInput[20];
	bool isFirstProcess = true;
	
	if (argc != 2)
	{
		printf("ERROR: Please pass in a file as an argument!\n");
		exit(1);
	}
	
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("ERROR: Please pass in a proper file!\n");
		exit(1);
	}
	
	/* Parse the file */
	for(n = 0; (fgets(buf[n], 9, file) != NULL); n++)
	{
		if (isFirstProcess == true)
		{
			createProcess = malloc(sizeof(node));
			if (createProcess == NULL)
			{
				printf("ERROR: Unable to malloc memory for process!\n");
				exit(1);
			}
			headProcessQue = createProcess;
			
			token = strtok(buf[n], " ");

			/* Dereference token from char * to convert to char */
			headProcessQue->pid = *token;
			
			/* Get the process ID (a single letter) */
			
			while (token != NULL)
			{
				/* Get the process size (an integer) */
				//printf("TOKEN %d: %s\n", n, token);
				token = strtok(NULL, "\n");
				if (token != NULL)
				{
					headProcessQue->size = atoi(token);
				}
			}
			isFirstProcess = false;
		}
		else
		{
			createProcess = malloc(sizeof(node));
			if (createProcess == NULL)
			{
				printf("ERROR: Unable to malloc memory for process!\n");
				exit(1);
			}
			
			token = strtok(buf[n], " ");

			/* Dereference token from char * to convert to char */
			createProcess->pid = *token;
			
			/* Get the process ID (a single letter) */
			
			while (token != NULL)
			{
				/* Get the process size (an integer) */
				//printf("TOKEN %d: %s\n", n, token);
				token = strtok(NULL, "\n");
				if (token != NULL)
				{
					createProcess->size = atoi(token);
					headProcessQue = insertNode(headProcessQue, createProcess);
				}
			}
		}
	}
	
	fclose(file);
	/* End of file parsing */
	
	do
	{
		/* Reset everything on each menu option! */
		allocatedQue = NULL;
		tempQue = duplicate(headProcessQue);
		//tempQue = headProcessQue;
		
		/* Prompt the user for input from the menu given */
		printMenu();
		printf("> ");
		scanf("%s", userInput);
	    
		if (strcmp(userInput, "1") == 0)
		{
			printf("\n*****************************\n");
			printf("  Now simulating FIRST Fit!\n");
			printf("*****************************\n");
			result = firstFitAlgorithm(tempQue, &allocatedQue);
			
			resetEverything();
			
			if (result == 0)
			{
				printf("ERROR: Something went wrong inside FIRST Fit algorithm!\n");
			}
		}
		else if (strcmp(userInput, "2") == 0)
		{
			printf("\n*****************************\n");
			printf("  Now simulating BEST Fit!\n");
			printf("*****************************\n");
			result = bestFitAlgorithm(tempQue, &allocatedQue);
			
			resetEverything();
			
			if (result == 0)
			{
				printf("ERROR: Something went wrong inside BEST Fit algorithm!\n");
			}
		}
		else if (strcmp(userInput, "3") == 0)
		{
			printf("\n*****************************\n");
			printf("  Now simulating NEXT Fit!\n");
			printf("*****************************\n");
			result = nextFitAlgorithm(tempQue, &allocatedQue);
			
			resetEverything();
			
			if (result == 0)
			{
				printf("ERROR: Something went wrong inside NEXT Fit algorithm!\n");
			}
		}
		else if (strcmp(userInput, "4") == 0)
		{
			printf("\n*****************************\n");
			printf("  Now simulating WORST Fit!\n");
			printf("*****************************\n");
			result = worstFitAlgorithm(tempQue, &allocatedQue);
			
			resetEverything();
			
			if (result == 0)
			{
				printf("ERROR: Something went wrong inside WORST Fit algorithm!\n");
			}
		}
		else
		{
			if (strcmp(userInput, "5") != 0)
			{
				printf("Please give a proper menu option, numbers between 1-5!\n");
			}
		}	
	} while(strcmp(userInput, "5") != 0);
	
	
	printf("\nNow exiting the program...\n\n");
	/* Free up malloc calls */
	free(token);
	return 0;
}

void printMenu()
{
	printf("\nSimulation of 4 allocation strategies:\n");
	printf("1) First Fit\n");
	printf("2) Best Fit\n");
	printf("3) Next Fit\n");
	printf("4) Worst Fit\n");
	printf("5) EXIT Program\n");
}

void resetEverything()
{
	/* Reset all the global variables so we can continously keep simulating the memory queue from the file */
	cumulativeMemUsage = 0.0;
	memUsageCounter = 0;
	averageProcesses = 0.0;
	averageProcessesCounter = 0;
	averageMemoryNotUsed = 0.0;
	averageMemoryNotUsedCounter = 0;
	totalLoads = 0;
}

void printQueue(head normQueue)
{
	node * temp = NULL;
	temp = normQueue;
	
	printf("\nPRINTING - Queue to be simulated from File:\n\n");
	while(temp != NULL) 
	{
		printf("Process: %c, size in MB: %d, swap-counter: %d\n", temp->pid, temp->size, temp->swapCounter);
		temp = temp->next;
	}
	printf("\n");
}

head removeFirst(head normQueue) 
{
	/* Checks if the node front is null or not and checks if the next one is null or not, it will remove if they both aren't null */
	if(normQueue != NULL && normQueue->next != NULL)
	{
		normQueue = normQueue->next;
		return normQueue;
	}
	
	//printf("ERROR in removing first: The list given has no front node!\n");
	return NULL;
}

node * getFront(head normQueue)
{
	head temp = NULL;
	temp = normQueue;
	
	if(temp != NULL)
	{
		//printf("Returning FRONT!\n");
		return temp;
	}
	else 
	{
		//printf("ERROR: The list given has no front node!\n");
	}
	
	return NULL;
}

node * getBack (head normQueue)
{
	head temp;
	temp = normQueue;
	
	node * back;
	
	while(temp != NULL)
	{
		/* When you reach the next one null, the one we are on is the last node */
		if(temp->next == NULL)
		{
			back = temp;
			//printf("Returning BACK!\n");
			return back;
		}
		temp = temp->next;
	}
	return NULL;
}

head insertNode(head normQueue, node * nextAdded)
{
	node * back;
	
	if (normQueue == NULL)
	{
		printf("ERROR: There is no list!\n");
		return NULL;
	}
	if (nextAdded == NULL)
	{
		printf("ERROR: Added node is null!\n");
		return NULL;
	}
	
	back = getBack(normQueue);
	if(back != NULL)
	{
		back->next = nextAdded;
		nextAdded->next = NULL;
	}
	else
	{
		printf("ERROR: Cannot find proper place for back of queue!\n");
		return NULL;
	}
	
	return normQueue;
}

head removeFromBack(head normQueue)
{
	head temp = NULL;
	temp = normQueue;
	
	node * tempBack = NULL;
	node * newBack = NULL;
	
	if(temp == NULL)
	{
		return NULL;
	}
	
	tempBack = getBack(temp);
	if (tempBack == NULL)
	{
		return NULL;
	}
	
	while(temp != NULL)
	{
		if(tempBack == temp->next)
		{
			newBack = temp; /* Set the new back to the one before the last */
			newBack->next = NULL; /* NULL out the next element */
		}
		temp = temp->next;
	}
	return normQueue;
}

head duplicate(head normQueue) 
{
	head duplicate = NULL;
	head tempDuplicate = NULL;
	
	head temp = NULL;
	temp = normQueue;
	
	head tempHead; /* Pointer to the head of the duplicated list */
	
	duplicate = malloc(sizeof(node));
	if (duplicate == NULL)
	{
		printf("ERROR: Could not create memory with malloc! - IN DUPLICATE FUNCTION\n");
		return NULL;
	}
	tempHead = duplicate;
	
	/* Start copying everything - Create exact duplicate!! */
	while(temp != NULL) 
	{
		duplicate->pid = temp->pid; 
		duplicate->size = temp->size;
		duplicate->swapCounter = 0;
		duplicate->memoryLocation = 0;

		temp = temp->next;
		tempDuplicate = duplicate;
		
		duplicate = malloc(sizeof(node));
		if (duplicate == NULL)
		{
			printf("ERROR: Could not create memory with malloc! - IN DUPLICATE FUNCTION INNER\n");
			return NULL;
		}
		tempDuplicate->next = duplicate;

	}
	
	/* NULL out next after getting out of loop to find the end! */
	tempDuplicate->next = NULL;
	return tempHead;
}

/* Functions used in the simulator part */ 

head createMemQue(head memQueue, node ** processToPutIn) 
{
	if(memQueue == NULL) 
	{
		memQueue = *processToPutIn;
		memQueue->next = NULL;
	}
	else 
	{
		memQueue = insertNode(memQueue, *processToPutIn);
	}
	return memQueue;
}

void printInfo(bool checker, int memory[], node ** memoryQue, head memQueue)
{
	int n = 0;
	int memoryUsed = 0;
	int memoryNotUsed = 0;
	float memoryUsageAvg = 0;
	float cumulativeMemUsageResult = 0.0;
	int numOfProcesses = 0;
	float averageProcessesResult = 0.0;
	float averageMemoryNotUsedResult = 0.0;
	
	int holesCount = 0;
	bool holesCheck = false;
	
	node * temp = NULL;
	temp = memQueue;
	
	node * temp2 = NULL;
	temp2 = memQueue;
	
	//printf("\nPRINTING - Memory Queue:\n");
	while(temp != NULL) 
	{
		//printf("Process: %c, size in MB: %d, swap-counter: %d\n", temp->pid, temp->size, temp->swapCounter);
		numOfProcesses++;
		temp = temp->next;
	}
	
	/* Process is loading in memory, print out the info */
	if (checker == false)
	{
		/* Count the total memory that is used and not used */
		for (n = 0; n < MEM_SIZE; n++)
		{	
			if (memory[n] == true)
			{
				memoryUsed++;
			}
			else
			{
				memoryNotUsed++;
			}
		}
		
		/* Count the holes in memory */
		for (n = 0; n < MEM_SIZE; n++)
		{	
			if (memory[n] == true)
			{
				holesCheck = false;
			}
			else
			{
				if (holesCheck == false)
				{
					holesCount++;
					holesCheck = true;
				}
			}
		}
		
		/* Get the memory usage average */
		memoryUsageAvg = (float)memoryUsed / MEM_SIZE;
	
		/* Get the cumulative memory usage average */
		cumulativeMemUsage = cumulativeMemUsage + memoryUsageAvg;
		memUsageCounter++;
		cumulativeMemUsageResult = cumulativeMemUsage / memUsageCounter;
		
		/* Make it more readable in % format */
		memoryUsageAvg = memoryUsageAvg * 100;
		cumulativeMemUsageResult = cumulativeMemUsageResult * 100;
		
		temp2 = getBack(memQueue);
		
		printf("pid = %c loaded, #processes = %d, #holes = %d #sizeOfMemNotUsed = %d, %%memusage = %.1f, cumulative %%mem = %.2f!\n", temp2->pid, numOfProcesses, holesCount, memoryNotUsed, memoryUsageAvg, cumulativeMemUsageResult);
		
		averageProcesses = averageProcesses + numOfProcesses;
		averageProcessesCounter++;
		
		averageMemoryNotUsed = averageMemoryNotUsed + holesCount;
		averageMemoryNotUsedCounter++;
		
		totalLoads++;
	}
	else
	{
		averageProcessesResult = (float)averageProcesses / averageProcessesCounter;
		averageMemoryNotUsedResult = (float)averageMemoryNotUsed / averageMemoryNotUsedCounter;
		
		cumulativeMemUsageResult = cumulativeMemUsage / memUsageCounter;
		cumulativeMemUsageResult = cumulativeMemUsageResult * 100;
		
		printf("Total loads = %d, average #processes = %.1f, average #holes = %.1f, cumulative %%mem = %.1f\n", totalLoads, averageProcessesResult, averageMemoryNotUsedResult, cumulativeMemUsageResult);
	}
}

node * removeOldestProcess(node ** memoryQue)
{
	head temp = NULL;
	temp = *memoryQue;
	
	/* Add a swap counter so we keep track of how many times it has been swapped! If its 3 it will no longer be used in the simulation */
	temp->swapCounter = temp->swapCounter + 1;
	*memoryQue = removeFirst(*memoryQue);
	
	return temp;
}


int firstFitAlgorithm(head normQue, node **memoryQue)
{
	int n = 0;
	
	int memory[MEM_SIZE] = {false};          /* Memory size is 128 MB, 0 represents nothing in slot but anything else means there is something! */
	int memoryAvailableSize = 0;
	int memoryAvailableLocation = 0;         /* Default to the first location in memory is free! */
	
	node * processInMemory = NULL;
	node * oldestProcess = NULL;
	bool processSuccess = false;
	
	/* Print out the file contents before starting! */
	printQueue(normQue);
	
	do 
	{
		/* Reset everything at the start */
		memoryAvailableSize = 0;
		processSuccess = false;
		
		/* get the front of the normal queue (file data) - ALWAYS, if there is nothing left everything is done!*/
		processInMemory = getFront(normQue);
		if (processInMemory == NULL)
		{
			/* Nothing is left to do... */
			printInfo(true, memory, &processInMemory, *memoryQue);
			printf("\n\n*****************************************\n");
			printf("  FIRST fit algorithm is now complete!!!\n");
			printf("*****************************************\n");
			
			return 1;
		}
		
		/* Search the memory which is size 128! */
		for (n = 0; n < MEM_SIZE; n++)
		{
			if(memory[n] == 0)
			{
				memoryAvailableSize++;
				if (memoryAvailableSize == 1)
				{
					memoryAvailableLocation = n;
				}
			}
			else
			{
				memoryAvailableSize = 0;
			}
			
			if (memoryAvailableSize == processInMemory->size)
			{
				//printf("REACHED ENOUGH ROOM AT N: %d!\n", memoryAvailableSize);
				normQue = removeFirst(normQue);
				
				processInMemory->memoryLocation = memoryAvailableLocation;
				
				//printf("Process: %c with size: %d inserted at: %d!\n\n", processInMemory->pid, processInMemory->size, memoryAvailableLocation);
				
				/* Fill up slots to full with the process */
				//printf("N ENDS AT: %d!\n", n);
				for ( n = memoryAvailableLocation; n < memoryAvailableLocation + processInMemory->size; n++)
				{
					//printf("FILLED AT N: %d!\n", n);
					memory[n] = true;
					//printf("memory[%d]!\n", memory[n]);
				}
				
				
				/* For some reason this makes sure I don't crash */
				for (n = 0; n < MEM_SIZE; n++)
				{	
					//Only print stuff not filled!
					if (memory[n] == 0)
					{
						//printf("MEMORY[ %d ] = %d!!!\n", n, memory[n]);
					}
				}
		
				//printf("ABOUT TO ENTER CREATEQ\n");
				*memoryQue = createMemQue(*memoryQue, &processInMemory);
				printInfo(false, memory, &processInMemory, *memoryQue);
				
				processSuccess = true;
			}
		}
		
		/* Search for the oldest process to swap out if it cannot be placed in the memory */
		if (processSuccess != true)
		{
			//printf("ENTERING REPLACE!\n");
			oldestProcess = removeOldestProcess(memoryQue);

			for(n = oldestProcess->memoryLocation; n < (oldestProcess->size + oldestProcess->memoryLocation); n++)
			{
				memory[n] = false;
				//printf("first_fit: CLEARING MEMORY [%d]\n", n);
			}
			//printf("OUTSIDE: CHECK 1!\n");
			if(oldestProcess->swapCounter <= 2)
			{
				normQue = insertNode(normQue, oldestProcess);
				//printf("OUTSIDE: CHECK 2!\n");
				//printf("first_fit: Process %c has been added to the normQue\n", oldestProcess->pid);
			}
			else
			{
				/* Print out process that is over 3 and cant be put back in! */
				//printf("*****Process has been swapped 3 times or more!!*****\n");
			}
		}	
	} while(processInMemory != NULL);
	
	return 1;
}

int bestFitAlgorithm(head normQue, node **memoryQue)
{
	int n = 0;
	
	int memory[MEM_SIZE] = {false};          /* Memory size is 128 MB, 0 represents nothing in slot but anything else means there is something! */
	int memoryAvailableSize = 0;
	int memoryAvailableLocation = 0;     /* Default to the first location in memory is free! */
	
	node * processInMemory = NULL;
	node * oldestProcess = NULL;
	bool processSuccess = false;
	bool foundHole = false;

	int differenceOfResult = 0;
	int smallNum = 0;
	int newLocation = 0;
	
	/* Print out the file contents before starting! */
	printQueue(normQue);
	
	do 
	{
		/* Reset everything at the start */
		smallNum = MEM_SIZE;
		memoryAvailableSize = 0;
		processSuccess = false;
		foundHole = false;
		
		/* get the front of the normal queue (file data) - ALWAYS, if there is nothing left everything is done!*/
		processInMemory = getFront(normQue);
		if (processInMemory == NULL)
		{
			/* Nothing is left to do... */
			printInfo(true, memory, &processInMemory, *memoryQue);
			printf("\n\n*****************************************\n");
			printf("  BEST fit algorithm is now complete!!!\n");
			printf("*****************************************\n");
			return 1;
		}
		
		/* Search the memory which is size 128! */
		for (n = 0; n < MEM_SIZE; n++)
		{
			if(memory[n] == 0) 
			{
				memoryAvailableSize++;
				if (memoryAvailableSize == 1)
				{
					memoryAvailableLocation = n;
				}
			}
			else 
			{
				memoryAvailableSize = 0;
			}
			
			//Check the spot ahead of current slot
			if(memory[n+1] == true) 
			{
				if(memoryAvailableSize >= processInMemory->size) 
				{
					//Set the flag to load it
					foundHole = true; 
					differenceOfResult = memoryAvailableSize - processInMemory->size;
					
					if(differenceOfResult < smallNum) 
					{		
						smallNum = differenceOfResult;
						newLocation = memoryAvailableLocation;
						//printf("Smallest Num: %d, New location: %d\n", smallNum, newLocation);
					}
				}
			}
		}
		
		/* load it in!! */
		if((memoryAvailableSize >= processInMemory->size)  &&  (foundHole == false)) 
		{ 
			smallNum = memoryAvailableSize - processInMemory->size;
			newLocation = memoryAvailableLocation;
			
			foundHole = true; // Set it so it can load the process
		}
		
		// Put it in if there is a hole large enough
		if(foundHole == true) 
		{
			normQue = removeFirst(normQue);
			processInMemory->memoryLocation = newLocation;

			// Setting all the memory spots to true ( full )
			for( n = newLocation ; n < (newLocation + processInMemory->size) ; n++) 
			{
				memory[n] = true;
			}
			
			*memoryQue = createMemQue(*memoryQue, &processInMemory);
			printInfo(false, memory, &processInMemory, *memoryQue);
			processSuccess = true;
		}
		
		/* Search for the oldest process to swap out if it cannot be placed in the memory */
		if (processSuccess != true)
		{
			//printf("ENTERING REPLACE!\n");
			oldestProcess = removeOldestProcess(memoryQue);
			
			for(n = oldestProcess->memoryLocation; n < (oldestProcess->size + oldestProcess->memoryLocation); n++)
			{
				memory[n] = false;
				//printf("first_fit: CLEARING MEMORY [%d]\n", n);
			}
			//printf("OUTSIDE: CHECK 1!\n");
			if(oldestProcess->swapCounter <= 2)
			{
				normQue = insertNode(normQue, oldestProcess);
				//printf("OUTSIDE: CHECK 2!\n");
				//printf("first_fit: Process %c has been added to the normQue\n", oldestProcess->pid);
			}
			else
			{
				/* Print out process that is over 3 and cant be put back in! */
				//printf("*****Process has been swapped 3 times or more!!*****\n");
			}
		}	
	} while(processInMemory != NULL);
	
	return 1;
}

int worstFitAlgorithm(head normQue, node **memoryQue)
{
	int n = 0;
	
	int memory[MEM_SIZE] = {false};          /* Memory size is 128 MB, 0 represents nothing in slot but anything else means there is something! */
	int memoryAvailableSize = 0;
	int memoryAvailableLocation = 0;     /* Default to the first location in memory is free! */
	
	node * processInMemory = NULL;
	node * oldestProcess = NULL;
	bool processSuccess = false;
	bool foundHole = false;

	int differenceOfResult = 0;
	int bigNum = 0;
	int newLocation = 0;
	
	/* Print out the file contents before starting! */
	printQueue(normQue);
	
	do 
	{
		/* Reset everything at the start */
		bigNum = 0;
		memoryAvailableSize = 0;
		processSuccess = false;
		foundHole = false;
		
		/* get the front of the normal queue (file data) - ALWAYS, if there is nothing left everything is done!*/
		processInMemory = getFront(normQue);
		if (processInMemory == NULL)
		{
			/* Nothing is left to do... */
			printInfo(true, memory, &processInMemory, *memoryQue);
			printf("\n\n*****************************************\n");
			printf("  WORST fit algorithm is now complete!!!\n");
			printf("*****************************************\n");
			return 1;
		}
		
		/* Search the memory which is size 128! */
		for (n = 0; n < MEM_SIZE; n++)
		{
			if(memory[n] == 0) 
			{
				memoryAvailableSize++;
				if (memoryAvailableSize == 1)
				{
					memoryAvailableLocation = n;
				}
			}
			else 
			{
				memoryAvailableSize = 0;
			}
			
			//Check the spot ahead of current slot
			if(memory[n+1] == true) 
			{
				if(memoryAvailableSize >= processInMemory->size) 
				{
					//Set the flag to load it
					foundHole = true; 
					differenceOfResult = memoryAvailableSize - processInMemory->size;
					
					if(differenceOfResult > bigNum) 
					{		
						bigNum = differenceOfResult;
						newLocation = memoryAvailableLocation;
						//printf("Smallest Num: %d, New location: %d\n", smallNum, newLocation);
					}
				}
			}
		}
		
		/* load it in!! */
		if((memoryAvailableSize >= processInMemory->size)  &&  (foundHole == false)) 
		{ 
			bigNum = memoryAvailableSize - processInMemory->size;
			newLocation = memoryAvailableLocation;
			
			foundHole = true; // Set it so it can load the process
		}
		
		// Put it in if there is a hole large enough
		if(foundHole == true) 
		{
			normQue = removeFirst(normQue);
			processInMemory->memoryLocation = newLocation;

			// Setting all the memory spots to true ( full )
			for( n = newLocation ; n < (newLocation + processInMemory->size) ; n++) 
			{
				memory[n] = true;
			}
			
			*memoryQue = createMemQue(*memoryQue, &processInMemory);
			printInfo(false, memory, &processInMemory, *memoryQue);
			processSuccess = true;
		}
		
		/* Search for the oldest process to swap out if it cannot be placed in the memory */
		if (processSuccess != true)
		{
			//printf("ENTERING REPLACE!\n");
			oldestProcess = removeOldestProcess(memoryQue);
			
			for(n = oldestProcess->memoryLocation; n < (oldestProcess->size + oldestProcess->memoryLocation); n++)
			{
				memory[n] = false;
				//printf("first_fit: CLEARING MEMORY [%d]\n", n);
			}
			//printf("OUTSIDE: CHECK 1!\n");
			if(oldestProcess->swapCounter <= 2)
			{
				normQue = insertNode(normQue, oldestProcess);
				//printf("OUTSIDE: CHECK 2!\n");
				//printf("first_fit: Process %c has been added to the normQue\n", oldestProcess->pid);
			}
			else
			{
				/* Print out process that is over 3 and cant be put back in! */
				//printf("*****Process has been swapped 3 times or more!!*****\n");
			}
		}	
	} while(processInMemory != NULL);
	
	return 1;
}

int nextFitAlgorithm(head normQue, node **memoryQue)
{
	int n = 0;
	
	int memory[MEM_SIZE] = {false};          /* Memory size is 128 MB, 0 represents nothing in slot but anything else means there is something! */
	int memoryAvailableSize = 0;
	int memoryAvailableLocation = 0;         /* Default to the first location in memory is free! */
	
	node * processInMemory = NULL;
	node * oldestProcess = NULL;
	bool processSuccess = false;

	int checkAgain = 0;
	
	/* Print out the file contents before starting! */
	printQueue(normQue);
	
	do 
	{
		/* Reset everything at the start */
		memoryAvailableSize = 0;
		processSuccess = false;
		checkAgain = 0;
		
		/* get the front of the normal queue (file data) - ALWAYS, if there is nothing left everything is done!*/
		processInMemory = getFront(normQue);
		if (processInMemory == NULL)
		{
			/* Nothing is left to do... */
			printInfo(true, memory, &processInMemory, *memoryQue);
			printf("\n\n*****************************************\n");
			printf("  NEXT fit algorithm is now complete!!!\n");
			printf("*****************************************\n");
			
			return 1;
		}
		do {
			if (checkAgain == 1)
			{
				memoryAvailableLocation = 0;
				memoryAvailableSize = 0;
			}
			/* Search the memory which is size 128! */
			for (n = memoryAvailableLocation; n < MEM_SIZE; n++)
			{
				if(memory[n] == 0)
				{
					memoryAvailableSize++;
					if (memoryAvailableSize == 1)
					{
						memoryAvailableLocation = n;
					}
				}
				else
				{
					memoryAvailableSize = 0;
				}
				
				if (memoryAvailableSize == processInMemory->size)
				{
					//printf("REACHED ENOUGH ROOM AT N: %d!\n", memoryAvailableSize);
					normQue = removeFirst(normQue);
					
					processInMemory->memoryLocation = memoryAvailableLocation;
					
					//printf("Process: %c with size: %d inserted at: %d!\n\n", processInMemory->pid, processInMemory->size, memoryAvailableLocation);
					
					/* Fill up slots to full with the process */
					//printf("N ENDS AT: %d!\n", n);
					for ( n = memoryAvailableLocation; n < memoryAvailableLocation + processInMemory->size; n++)
					{
						//printf("FILLED AT N: %d!\n", n);
						memory[n] = true;
						//printf("memory[%d]!\n", memory[n]);
					}
					
					/* For some reason this makes sure I don't crash */
					for (n = 0; n < MEM_SIZE; n++)
					{	
						//Only print stuff not filled!
						if (memory[n] == 0)
						{
							//printf("MEMORY[ %d ] = %d!!!\n", n, memory[n]);
						}
					}
			
					//printf("ABOUT TO ENTER CREATEQ\n");
					*memoryQue = createMemQue(*memoryQue, &processInMemory);
					printInfo(false, memory, &processInMemory, *memoryQue);
					
					processSuccess = true;
				}
			}
			checkAgain++;
		} while( processSuccess == false && checkAgain < 2 );
		
		/* Search for the oldest process to swap out if it cannot be placed in the memory */
		if (processSuccess != true)
		{
			//printf("ENTERING REPLACE!\n");
			oldestProcess = removeOldestProcess(memoryQue);

			for(n = oldestProcess->memoryLocation; n < (oldestProcess->size + oldestProcess->memoryLocation); n++)
			{
				memory[n] = false;
				//printf("first_fit: CLEARING MEMORY [%d]\n", n);
			}
			//printf("OUTSIDE: CHECK 1!\n");
			if(oldestProcess->swapCounter <= 2)
			{
				normQue = insertNode(normQue, oldestProcess);
				//printf("OUTSIDE: CHECK 2!\n");
				//printf("first_fit: Process %c has been added to the normQue\n", oldestProcess->pid);
			}
			else
			{
				/* Print out process that is over 3 and cant be put back in! */
				//printf("*****Process has been swapped 3 times or more!!*****\n");
			}
		}	
	} while(processInMemory != NULL);
	
	return 1;
}