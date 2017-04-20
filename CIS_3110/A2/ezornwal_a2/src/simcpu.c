/************************* simcpu.c ****************************
Student Name: Erik Zorn - Wallentin  Student Number: 0864583
Date: Fri, Feb.27 / 2015             Course Name: CIS*3110
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

#include <unistd.h>
//#include <process.h>
#include "priorityListQueue.h"

int main(int argc, char * argv[]) 
{	
	/* Process Info Variables: number_of_processes, thread_switch, process_switch */
	int numOfProcesses = 0;
	int threadSwitch = 0;
	int processSwitch = 0;

	
    execBurst * burst; /* All the burst data */	
    ProcessList pHead; /* Variable to hold the head of all the processes */
    ProcessList tempProcList;	
	stateProcess * processToEnqueue;
	
	ThreadList tempThreadList;
	stateThread * threadToEnqueue;
	
	int n = 0;
	int lineCounter = 0;
	
	FILE * checkStdin = stdin;
    char buf[400][60];
    int fileInput[400][60];
    
    int arrayOfThreads[100];
	//arrayOfThreads[0] = 53300;
	//arrayOfThreads[1] = 1000;
	//arrayOfThreads[2] = 20000;
	int arrayCounter = 0;
	
	/* Setup the priority Queue */
	struct Burst *theFront = NULL, *rear = NULL;
	
	int numOfProcess = 0;
	int maxNumOfThreads = 0;
	int onThread = 1;
	int maxNumOfCPU = 0;
	int onCPU = 1;
	bool firstProcCheck = true;
	
	/* Setup variables for the command line */
	bool detailMode = false;
	bool verboseMode = false;
	bool schedulingMode = false;  /* false is the default mode and that is FCFS scheduling, if true it will be Round Robin */
	int quantum = -1;              /* Quantum number for Round Robin */
	
	float totalTime = 0.0;
	float averageTurnaroundTime = 0.0;
	float cpuUtilization = 0;
	
	if(isatty(fileno(checkStdin)))
    {
        fprintf(stderr, "No stdin was given for program! Please try..(ex. simcpu < t1.txt)!!\n");
        exit(0);
    }

	/******* Check mode and info given from command line *******/
	if ( argv[1] != NULL) 
    {
        //printf( "ARGUMENT 1: %s\n", argv[1] );
		if(strcmp(argv[1], "-d") == 0)
		{
			/* Set detail mode ON */
			detailMode = true;
		}
		else if (strcmp(argv[1], "-r") == 0)
		{
			//printf( "ARGUMENT WIth -r: %s\n", argv[3] );
			if ( argv[2] != NULL)
			{
				/* Set the quantum from the -r which is right before */
				schedulingMode = true;
				quantum = atoi(argv[2]);
				if (quantum == 0 || quantum < 0)
				{
					printf("Please input a number after using -r in command line (ex. -r 50)!\n");
					exit(0);
				}
				//printf("QUANTUM: %d\n\n", quantum);
			}
			else
			{
				printf("Please input a number after using -r in command line (ex. -r 50)!\n");
				exit(0);
			}
		}
    }
	
	if ( argv[2] != NULL) 
    {	
		if (strcmp(argv[2], "-r") == 0)
		{
			//printf( "ARGUMENT WIth -r: %s\n", argv[3] );
			if ( argv[3] != NULL)
			{
				/* Set the quantum from the -r which is right before */
				schedulingMode = true;
				quantum = atoi(argv[3]);
				if (quantum == 0 || quantum < 0)
				{
					printf("Please input a number after using -r in command line (ex. -r 50)!\n");
					exit(0);
				}
				//printf("QUANTUM: %d\n\n", quantum);
			}
			else
			{
				printf("Please input a number after using -r in command line (ex. -r 50)!\n");
				exit(0);
			}
		}
		else if (strcmp(argv[2], "-v") == 0)
		{
			/* Set verbose mode ON */
			verboseMode = true;
		}
    }
	
	if ( argv[3] != NULL && quantum == -1) 
    {
        //printf( "ARGUMENT 3: %s\n", argv[3] );
		if(strcmp(argv[3], "-r") == 0)
		{
			if ( argv[4] != NULL)
			{
				/* Set the quantum from the -r which is right before */
				schedulingMode = true;
				quantum = atoi(argv[4]);
				if (quantum == 0 || quantum < 0)
				{
					printf("Please input a number after using -r in command line (ex. -r 50)!\n");
					exit(0);
				}
				//printf("QUANTUM: %d\n\n", quantum);
			}
			else
			{
				printf("Please input a number after using -r in command line (ex. -r 50)!\n");
				exit(0);
			}
		}
    }
	/******* End of checking info given from command line *******/
	
	for(n = 0; (fgets(buf[n], 59, checkStdin) != NULL); n++)
	{
		sscanf(buf[n], "%d%d%d", &fileInput[n][0], &fileInput[n][1], &fileInput[n][2]);
		//printf("GOT: %d, %d, %d!\n", fileInput[n][0], fileInput[n][1], fileInput[n][2]);
	}
	
	/* Setup start info from first line of stdin!! */
	numOfProcesses = fileInput[0][0];                          /* Get the number_of_processes     */
	threadSwitch = fileInput[0][1];                            /* Get the thread_switch           */
	processSwitch = fileInput[0][2];                           /* Get the process_switch          */
	lineCounter = n;                                           /* Keep track of the lines counted */
	
	/* Always 1 behind! */
	/* Setup first process and its threads */
	n = 1;
	numOfProcess = fileInput[n][0]; 
	maxNumOfThreads = fileInput[n][1];
	
	//printf("Num Of Process: %d, Max threads for process: %d!\n", numOfProcess, maxNumOfThreads);
	//printf("N START: %d\n", n);
	//printf("LINE COUNTER: %d\n\n\n", lineCounter);
	/* Begin parsing entire file into our priority queue!*/
	do
	{
		//printf("Process INFO: %d, %d, %d!--N ON ***%d***\n", fileInput[n][0], fileInput[n][1], fileInput[n][2], n);
		
		/****** Get the new process, after checking all the threads and their CPU ******/
		if (firstProcCheck == true)
		{
			pHead = malloc(sizeof(stateProcess));
			if (pHead != NULL)
			{
				pHead->numOfThreads = fileInput[1][1];                 /* Get the number_of_threads */
			}
			//firstProcCheck = false;
		}
		else
		{
			processToEnqueue = malloc(sizeof(stateProcess));
			if (processToEnqueue != NULL)
			{
				processToEnqueue->numOfThreads = fileInput[n][1];
				pHead->next = processToEnqueue;
			}
		}
		if (numOfProcesses < fileInput[n][0])
		{
			printf("Too many processes listed, please check the first number in the file equals the total processes!\n");
			printf("Expected: %d, Processors asked for: %d\n", numOfProcesses, fileInput[n][0]);
			exit(0);
		}
		/****** End of creating process ******/
		
		maxNumOfThreads = fileInput[n][1];
		n++;
		for( onThread = 1 ; onThread <= maxNumOfThreads ; onThread++ )
		{
			//printf("Thread INFO: %d, %d, %d!\n", fileInput[n][0], fileInput[n][1], fileInput[n][2]);
			maxNumOfCPU = fileInput[n][2];
			
			/****** Get the new thread ******/
			threadToEnqueue = malloc(sizeof(stateThread));
			if (threadToEnqueue != NULL)
			{
				threadToEnqueue->stateType = new;
				threadToEnqueue->threadNumber = fileInput[n][0];               /* Get the thread_number */
				threadToEnqueue->processNumber = fileInput[n-1][0];            /* Get the process_number */
				threadToEnqueue->arrivalTime = fileInput[n][1];                /* Get the arrival_time */
				
				/* Add THREAD into priority queue ! */
				arrayOfThreads[arrayCounter] = threadToEnqueue->arrivalTime;
				arrayCounter++;
				/* END of adding THREAD into priority queue !*/
				if (firstProcCheck == true)
				{
					pHead->nextThread = threadToEnqueue;
					firstProcCheck = false; 
				}
				else
				{
					pHead->nextThread->next = threadToEnqueue;                     /* Add thread to next process */
				}
			}
			/****** end of thread creation ******/
			n++;
			for( onCPU = 1 ; onCPU <= maxNumOfCPU ; onCPU++ )
			{
				//printf("IN BURSTS: %d, %d, %d!\n", fileInput[n][0], fileInput[n][1], fileInput[n][2]);
				
				/****** Get the CPU BURST INFO ******/
				burst = malloc(sizeof(execBurst));
				if (burst != NULL)
				{
					burst->burstNumber = fileInput[n][0];
					burst->cpuTime = fileInput[n][1];
					if (fileInput[n][2] > 9000 || fileInput[n][2] < 0)             /* Check if there is nothing in the 3rd slot, jibberish set to 0 */
					{
						burst->ioTime = 0;
					}
					else
					{
						burst->ioTime = fileInput[n][2];                           /* Get the io_time   */
					}
					totalTime = totalTime + burst->cpuTime + burst->ioTime;
					threadToEnqueue->nextBurst = burst;
				}
				/****** end of CPU BURST INFO ******/
				n++;
			}
			onCPU = 1;
		}
		onThread = 1;
	}while(n < lineCounter);
	
	/* Check the modes and data given from command line -- DO stuff and print out messages showing */
	if (detailMode == true)
	{
		printf("Detail Mode turned on!\n");
	}
	if (verboseMode == true)
	{
		printf("Verbose Mode turned on!\n");
	}
	if (quantum >= 0)
	{
		printf("Round Robin MODE ON with Quantum: %d\n", quantum);
	}
	if (detailMode == false && verboseMode == false && schedulingMode == false && quantum == -1)
	{
		printf("Using default mode: FCFS Scheduling!\n");
	}
	else if (schedulingMode == false)
	{
		printf("FCFS MODE ON!\n");
	}
	printf("Finished parsing file! Please check code for further info...\n\n");
	
	/**** Start calculating the Process/Thread data ****/
	/* Everything this spot works perfectly fine, just not 100% implemented */
	
	insertNode(&theFront,&rear,1);
	insertNode(&theFront,&rear,3);
	insertNode(&theFront,&rear,5);
	deleteNode(&theFront,&rear);
	//printThreadContents(theFront);
	//bubbleSort( arrayOfThreads, arrayCounter );
	
	/**** End of calculating Process/Thread data ****/
	
	
	averageTurnaroundTime = totalTime / 12;
	cpuUtilization = (totalTime - averageTurnaroundTime) / totalTime;
	
	/* Do FCFS scheduling */
	if (schedulingMode == false)
	{
		printf("FCFS:\n\n");
		if (detailMode == false && verboseMode == false)
		{
			
			printf("Total Time required is %.2f time units\n", totalTime);
			printf("Average Turnaround Time is %.2f time units\n", averageTurnaroundTime);
			printf("CPU Utilization is %.0f%%\n", cpuUtilization);
		}
	}
	/* Do Round Robin scheduling */
	else
	{
		printf("Round Robin (quantum = %d time units):\n\n", quantum);
		if (detailMode == false && verboseMode == false)
		{
			printf("Total Time required is %.2f time units\n", totalTime);
			printf("Average Turnaround Time is %.2f time units\n", averageTurnaroundTime);
			printf("CPU Utilization is %.0f%%\n", cpuUtilization);
		}
	}
	
	
	return 0;
}
