#include "priorityListQueue.h"

/*----
Purpose: Add the first element in the priority queue
Parameters: struct Burst ** theFront (front of the priority queue), struct Burst ** rear (back of the priority queue)
Return: VOID
----*/
void insertNode(struct Burst ** theFront, struct Burst **rear, int value)
{
    struct Burst * temp;
   
    temp = (struct Burst *)malloc(sizeof(struct Burst));
    if(temp==NULL)
    {
        printf("ERROR: Malloc failed!\n");
        exit(0);
    }
   
    temp->cpuTime = value;
    temp->next = NULL;
    if(*rear == NULL)
    {
        *rear = temp;
        *theFront = *rear;
    }
    else
    {
        (*rear)->next = temp;
        *rear = temp;
    }
}

/*----
Purpose: Delete the first element in the priority queue
Parameters: struct Burst ** theFront (front of the priority queue), struct Burst ** rear (back of the priority queue)
Return: VOID
----*/
void deleteNode(struct Burst ** theFront, struct Burst **rear)
{
    struct Burst *temp;
    
    if((*theFront == *rear) && (*rear == NULL))
    {
        printf("ERROR: Malloc failed!\n");
        exit(0);
    }
    
    temp = *theFront;
    *theFront = (*theFront)->next;
    if(*rear == temp)
    {
        *rear = (*rear)->next;
    }
    free(temp);
}

/*----
Purpose: Sorts all the data when given an array of integers
Parameters: int list[]( array to sort ), int n (the number to sort)
Return: VOID
----*/
void bubbleSort(int list[], int num)
{
    int i = 0;
    int j = 0;
    int k = 0;
 
    for (i = 0; i < ( num - 1 ); i++)
    {
        for (j = 0 ; j < num - i - 1; j++)
        {
            if (list[j] > list[j+1])
            {
                /* The swapping is done here! */
 
                k = list[j];
                list[j] = list[j+1];
                list[j+1] = k;
            }
        }
    }
  
    printf("Sorted list in ascending order:\n");
 
    for ( i = 0 ; i < num ; i++ )
    {
        printf("ARRIVAL TIME of thread: %d\n", list[i]);
    }

}

/*----
Purpose: Prints out all the data in the Priority Queue for the thread contents - CPU info
Parameters: struct Burst * theFront (the burst list )
Return: VOID
----*/
void printThreadContents(struct Burst * theFront) 
{
    struct Burst * temp = NULL;
	
    if (theFront != NULL)
    {
        temp = theFront;
        printf("front >> ");
    }

    while(temp != NULL) 
    {
        printf("%d >> ",temp->cpuTime);
        temp = temp->next;
    }
    printf("last\n");
}

/*----
Purpose: Prints out all the thread data in the Priority Queue
Parameters: struct Burst * theFront (the burst list )
Return: VOID
----*/
void printThread(struct Thread * threadToEnqueue) 
{
    struct Thread * temp = NULL;
	
    if (threadToEnqueue != NULL)
    {
        temp = threadToEnqueue;
        printf("front >> ");
    }

    while(temp != NULL) 
    {
        printf("%d >> ",temp->arrivalTime);
        temp = temp->next;
    }
    printf("last\n");
}

/*----
Purpose: Checks if the list is empty or not, returns true if empty. Otherwise returns false if not empty.
Parameters: front queue(the list)
Return: return true(empty), return false(not empty)
----*/
bool isEmpty(front queue)
{
    int nodes = 0;
    front tempList = NULL;
    
    if (queue != NULL)
    {
        tempList = queue;
    }
	else
    {
        printf("The list is null!\n");
        return true;
    }
    
    while(tempList != NULL)
    {
        nodes++;
        tempList = tempList->next;
    }
    
    if(nodes == 0){
        return true;
    }
    return false;
}