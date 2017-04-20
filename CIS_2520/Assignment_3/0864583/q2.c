/*************************q2.c****************************
Student Name: Erik Zorn - Wallentin  Student Number: 0864583
Date: Sun, Nov.2 / 2014              Course Name: CIS2520
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
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//function prototypes
void downHeap(int a[], int root, int botOfArray);
void heapSorter(int arr[], int theArrayLength);

int main (int argc, char *argv[])
{  
	FILE * file = NULL;
	char * token;
	char buffer2[80];
	int array[20][10];
	int array2[20][10];
	int array3[20];
	char string2[30][40];
	int a = 0;
	int b = 0;
	int c = 0;
	int m = 0;
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	int counter = 0;
	
	
	file = fopen("f.dat","r");
	if (file != NULL)
	{
	    /*file = fopen("f1.dat","r");*/
	    while (fgets(buffer2,80,file))
	    {
	        strcpy(string2[m], buffer2);
	        m++;
	    }
	}
	else
	{
		printf("Problem with file!\n");
		exit(0);
	}
	
	/* Token each piece of data and the result goes into the proper array */
	for ( m = 0; m < 20; m++)
	{
		b = 0;
		c = 0;
		sum1 = 0;
	    sum2 = 0;
	    sum3 = 0;
		counter = 0;
	    
		token = strtok(string2[m], " ");
			
		
		while ( token != NULL)
		{
			if (b < 10)
			{
				array[a][b] = atoi(&token[0]);
				
				/* Sum the first 3 and leave the rest */
				if (counter == 0)
				{
					sum1 = atoi(&token[0]);
				}
				else if (counter == 1)
				{
					sum2 = atoi(&token[0]);
				}
				else if (counter == 2)
				{
					sum3 = atoi(&token[0]);
					array2[a][c] = sum1 + sum2 + sum3;
					array3[a] = sum1 + sum2 + sum3;
					c++;
				}
				if (counter >= 3) 
				{
					array2[a][c] = atoi(&token[0]);
					c++;
				}
			}
			/*printf("%s [%d][%d]: %d",token,a,b,array[a][b]);*/
			b++;
			counter++;
			token = strtok(NULL, " ");				
		}
		a++;
	}
	
	/* Commented parts below show all the steps going through on checks */
	
	/*
	printf("\n");
	for (a = 0; a < 20; a++) 
	{
        for (b = 0; b < 10; b++) 
		{
            printf("%d ", array[a][b]);
        }
        printf("\n");
    }
	
	printf("\n");
	for (a = 0; a < 20; a++) 
	{
        for (b = 0; b < 8; b++) 
		{
            printf("%d ", array2[a][b]);
        }
        printf("\n");
    } 
	
	printf("\n");
	for (a = 0; a < 20; a++) 
	{

        printf("%d ", array3[a]);
    } 
	*/
	heapSorter(array3, 20);
	
	/*
	printf("\n");
	for (a = 0; a < 20; a++) 
	{

        printf("%d ", array3[a]);
    }*/
	
	printf("Sorted Array: \n");
	for (a = 0; a < 20; a++) 
	{
		for (b = 0; b < 20; b++) 
		{
			if (array3[a] == array2[b][0])
			{
				for (c = 0; c < 10; c++) 
				{
					printf("%d ", array[b][c]);
				}
				printf("\n");
			}
		}
    }
	
	return 0;
}


/*----
Purpose: The purpose of this function is to do the sorting process ( down heap algorithm) on the array of numbers
         to get the lowest values first and the highest values last
Parameters: int arr[](passed in integer array from the main), int root (root of array), int botOfArray ( bottom of the array)
Return: Nothing VOID
----*/
void downHeap(int arr[], int root, int botOfArray)
{
    int bigChild = 0;
	int temp = 0;
	int child = 0;
	
    while (root * 2 < botOfArray)
    {
        child = root * 2 + 1;
        if (child == botOfArray)
        {
            bigChild = child;
        }
        else
        {
            if (arr[child] > arr[child + 1])
			{
                bigChild = child;
			}
            else
			{
                bigChild = child + 1;
			}
        }

        if (arr[root] < arr[bigChild])
        {
            temp = arr[root];
            arr[root] = arr[bigChild];
            arr[bigChild] = temp;
        }
        else
		{
			return;
		}
        root = bigChild;
    }
}

/*----
Purpose: The purpose of this function is to extract the root and start at the mid element for the sorting
Parameters: int arr[](passed in integer array from the main), int theArrayLength (length of the array)
Return: Nothing VOID
----*/
void heapSorter(int arr[], int theArrayLength)
{
    int n = 0;
	 
	/* Start at the mid element */
    for (n = ((theArrayLength / 2)-1); n >= 0; --n)
    {
        downHeap(arr, n, theArrayLength-1);
    }

	/* extract the root and start creating the sorted list */
    for (n = theArrayLength-1; n >= 0; --n)
    {
        int temp;
        temp = arr[n];
        arr[n] = arr[0];
        arr[0] = temp;
        downHeap(arr, 0, n-1);
    }
}