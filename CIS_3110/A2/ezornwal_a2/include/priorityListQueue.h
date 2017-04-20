#ifndef BOOL_H
#define BOOL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
enum {false, true};

/* types of thread states */
#define new 1
#define ready 2
#define running 3
#define blocked 4
#define terminated 5
typedef int state;

struct Node {
    int data;
    struct Node * next;
};
typedef struct Node node;
typedef node * front;

struct Burst {
    int burstNumber;
    int cpuTime;
    int ioTime;
    struct Burst * next;
};
typedef struct Burst execBurst;
typedef execBurst * BurstList;

struct Thread {
    int threadNumber;
    int arrivalTime;
    int processNumber;
    int threadCPUtime;
    int threadIOtime;
	
    struct Thread * next;
    struct Burst * nextBurst;
    state stateType;
};
typedef struct Thread stateThread;
typedef stateThread * ThreadList;

struct Process {
    struct Process * next;
    struct Thread * nextThread;
    int numOfThreads;
};
typedef struct Process stateProcess;
typedef stateProcess * ProcessList;

/* Priority Queue functions */

/*----
Purpose: Add the first element in the priority queue
Parameters: struct Burst ** theFront (front of the priority queue), struct Burst ** rear (back of the priority queue)
Return: VOID
----*/
void insertNode(struct Burst ** theFront, struct Burst **rear, int value);

/*----
Purpose: Delete the first element in the priority queue
Parameters: struct Burst ** theFront (front of the priority queue), struct Burst ** rear (back of the priority queue)
Return: VOID
----*/
void deleteNode(struct Burst ** theFront, struct Burst **rear);

/*----
Purpose: Sorts all the data when given an array of integers
Parameters: int list[]( array to sort ), int n (the number to sort)
Return: VOID
----*/
void bubbleSort(int list[], int num);

/*----
Purpose: Prints out all the data in the Priority Queue for the thread contents - CPU info
Parameters: struct Burst * theFront (the burst list )
Return: VOID
----*/
void printThreadContents(struct Burst * theFront);

/*----
Purpose: Prints out all the threads in the Priority Queue for the thread contents
Parameters: struct Thread * threadToEnqueue (the thread list )
Return: VOID
----*/
void printThread(struct Thread * threadToEnqueue);

/*----
Purpose: Checks if the list is empty or not, returns true if empty. Otherwise returns false if not empty.
Parameters: front queue(the list)
Return: return true(empty), return false(not empty)
----*/
bool isEmpty(front theList);

#endif


