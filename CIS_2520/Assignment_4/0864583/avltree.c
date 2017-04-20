/************************* shell.c ****************************
Student Name: Erik Zorn - Wallentin  Student Number: 0864583
Date: Wed, Jan.28 / 2014             Course Name: CIS*3110
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

#define MAXSIZE 100

/* Comment for programming at my house: set PATH=C:\MinGW\bin;%PATH% */

/*function prototypes*/

void menu();
int getNumberWithErrorCheck(int * theNumber, int size);

struct AVLtree * insertKey(struct AVLtree * tempNode, char * value);
int checkHeight(struct AVLtree * tempNode);
int balanceFactor(struct AVLtree * tempNode);

struct AVLtree * singleRrotate(struct AVLtree * tempNode);
struct AVLtree * singleLrotate(struct AVLtree * tempNode);
struct AVLtree * singleRightRotate(struct AVLtree * tempNode);
struct AVLtree * singleLeftRotate(struct AVLtree * tempNode);
struct AVLtree * doubleLRrotation(struct AVLtree * tempNode);
struct AVLtree * doubleRLrotation(struct AVLtree * tempNode);

int isEmpty(const char * input);

struct AVLtree * findKey(struct AVLtree * keyToFind, char * input);
void printAllAboveKey(struct AVLtree * tempNode, int value);

struct AVLtree * deleteKey(struct AVLtree * tempNode, char * value);

int findMaxSize (struct AVLtree * tempNode);
int findMaxHeight(struct AVLtree * tempNode);

/* The AVL Tree Struct */
struct AVLtree
{
    char key[30];
    int count;
    struct AVLtree * right;
    struct AVLtree * left;
    int height;
    int maxSize;
} AVLtree;

int main (int argc, char *argv[])
{  
	FILE * file = NULL;
	int userInput = 0;         /* The main menu user input variable */
	int checker = 1;              /* Checks if user wants to quit or not variable in main menu */
	int errorCode;                /* Error checker variable to check for bad input */
	int userInputHolder = 0; 
	
	char buf[80];
	char * fileName = NULL;
	char * finder = NULL;
	char * keyToInsert = NULL;
	char * removeKey = NULL;
	
	char * token;
	
	struct AVLtree * root = NULL; 	  /* find the root of the AVL tree */
	struct AVLtree * tempRoot = NULL; /* find the root of the AVL tree */
	
	int findFrequency = 0;
	
	int printMaxHeight = 0;
	int printMaxSize = 0;
	 
	
	/* Print out the banner */
	printf("\n");
	printf("**********************************\n");
	printf("*** Name: Erik Zorn-Wallentin  ***\n");
	printf("*** ID: 0864583 Class: CIS2050 ***\n");
	printf("**********************************\n");
	printf("\n");
	
	do
    {
	    /* Call the main menu function to display the main menu */
        menu();
		printf("avl/> ");
		scanf("%d", &userInput);
		
		/* This is a place holder that fixes a bug with error checking */
        userInputHolder = userInput;
		
        /* Error checking part, it gives guidance on where you made the error */
        errorCode = getNumberWithErrorCheck(&userInput,4);
        if (errorCode == 0)
        {
        	userInput = userInputHolder;
		
			switch (userInput)
        	{
				case 1:
					printf("filename: ");
					fgets(buf, sizeof(buf), stdin);
					
					size_t ln1 = strlen(buf) - 1;
					if (buf[ln1] == '\n')
					buf[ln1] = '\0';
				
					fileName = buf;
					
					file = fopen(fileName,"r");
										
					if (file != NULL)
					{
						char line [ 50000 ];

						printf("Reading from file: \n");
						while ( fgets(line, 1024, file) != NULL )
						{	
							
							token = strtok(line, "\t \n");
							while ( token != NULL)
							{
								if (isEmpty(token) == 0)
   								{
									//printf("ZORN: %s (zorn)\n",token);
									root = insertKey(root,token);
									token = strtok(NULL, "\t \n");
								}									
							}
						}
						fclose ( file );
					}
					else
					{
						printf("Error with file, returning to menu.\n");
						
					}
					break;
				case 2:
					printf("find key: ");
					fgets(buf, sizeof(buf), stdin);
					
					size_t ln2 = strlen(buf) - 1;
					if (buf[ln2] == '\n')
					buf[ln2] = '\0';
				
					finder = buf;
					tempRoot = root;
					
					tempRoot = findKey(tempRoot, finder);
					
					if (tempRoot != NULL)
					{
						printf("key: %s, frequency: %d\n", tempRoot->key, tempRoot->count);
					}
					else
					{
						printf("No_such_key\n");
					}
			    	break;
				case 3:
					printf("insert key: ");
					fgets(buf, sizeof(buf), stdin);
					
					size_t ln3 = strlen(buf) - 1;
					if (buf[ln3] == '\n')
					buf[ln3] = '\0';
				
					keyToInsert = buf;
					root = insertKey(root, keyToInsert);
					
					tempRoot = root;
					tempRoot = findKey(tempRoot, keyToInsert);
					
					if (tempRoot != NULL)
					{
						printf("key: %s, frequency: %d\n", tempRoot->key, tempRoot->count);
					}
						
			    	break;
		    	case 4:
					printf("remove key: ");
					fgets(buf, sizeof(buf), stdin);
					
					size_t ln4 = strlen(buf) - 1;
					if (buf[ln4] == '\n')
					buf[ln4] = '\0';

					removeKey = buf;
					tempRoot = root;
					
					if (root != NULL)
					{
						tempRoot = findKey(tempRoot, removeKey);
						if (tempRoot != NULL)
						{
							printf("key: %s, frequency: %d\n", tempRoot->key, tempRoot->count);
						}
						
						root = deleteKey(root, removeKey);
						if (root != NULL)
						{
							printf("No_such_key\n");
						}
					}
					else
					{
						printf("No_such_key\n");
					}
		    		break;
		    	case 5:
		    		tempRoot = root;
		    		
		    		if (tempRoot != NULL)
					{
						printMaxHeight = findMaxHeight(tempRoot) - 1;
						printMaxSize = findMaxSize(tempRoot);
						printf("height %d, size: %d", printMaxHeight, printMaxSize);
					}
		    		break;
				case 6:
					printf("frequency: ");
					scanf("%d",&findFrequency);
					
					if (root != NULL)
					{
						/* Traverse tree inorder */
						printAllAboveKey(root, findFrequency);
					}
					else
					{
						printf("No_such_key\n");
					}
					break;
				case 7:
				
            	    checker = 0; 
				default:
			
					if (userInput != 7) /* Buffer problems, fixes a bug */
					{
						printf("Incorrect input, try again! Numbers between 1-7!\n");
					}
					break;
			}
		}
	}while(checker == 1);
	
	printf("Now quitting the program!\n");	
	return 0;
}

/*----
Purpose: Prints out the menu in a loop till the user presses exit
Parameters: none
Return: void (nothing)
----*/
void menu()
{ 	
    printf("\nPlease choose one of the following using numbers between (1-7):\n");
    printf("1) Initialization\n");
    printf("2) Find\n");
    printf("3) Insert\n");
	printf("4) Remove\n");
	printf("5) Check Height and Size\n");
	printf("6) Find All (above a given frequency)\n");
	printf("7) Exit\n"); 
}

/*----
Purpose: Error checking function, source code given out by Judi in CIS1500 for students to use 
Parameters: takes in the input and the size of the input
Return: int (return error code)
----*/
int getNumberWithErrorCheck(int * theNumber, int size)
{
    int i;
    char next;
    char inputString[MAXSIZE];
    if (size > MAXSIZE)        	    
    {
        size = MAXSIZE;
    }
    fgets(inputString,MAXSIZE,stdin);
    i=0;
    next = inputString[i];     
    while ( i < size && next != '\0'&& isdigit(next)&& next !='\n')
    {     	
        i = i+1;
        next = inputString[i];  
    }  
       
    if (i+1 < strlen(inputString))
    {
        printf("Invalid input, please try numbers!\n");
       	/*there was an error*/
        * theNumber = -99;
       	return -1;   
    }
    else
    {
        *theNumber = (int)atol(inputString);   	
    }   

    return 0;
}

/*----
Purpose: A function that inserts key to AVL tree and performs rotations if needed to balance tree
Parameters: struct AVLtree * node (passing in the current node to be rotated), char * value (the key to be inserted)
Return: struct AVLtree * tempNode (returns the new root)
----*/
struct AVLtree * insertKey(struct AVLtree * tempNode, char * value)
{
	/* Insert actual data here */
	if(tempNode == NULL)
	{
		tempNode = (struct AVLtree*)malloc(sizeof(struct AVLtree));
		strcpy(tempNode->key, value);
		tempNode->count = 1;
        tempNode->left = NULL;
        tempNode->right = NULL;
        tempNode->maxSize = 1;
	}
	/* Go into right tree */               
    else if(strcmp( value, tempNode->key) > 0)
	{
		tempNode->right = insertKey(tempNode->right, value);
        if(balanceFactor(tempNode) == -2) /* Check balance factor */
        {
			//if(x>T->right->key)
			if(strcmp( value, tempNode->right->key) > 0) 
            {
				tempNode = singleRightRotate(tempNode);
            }
            else
            {
				tempNode = doubleRLrotation(tempNode);
            }
        }
    }
    /* Go into left tree */ 
    else if(strcmp( value, tempNode->key) < 0)  
    {
		tempNode->left = insertKey(tempNode->left, value);
        if(balanceFactor(tempNode) == 2) /* Check balance factor */
        {
			if(strcmp( value, tempNode->left->key) < 0) 
            {
				tempNode = singleLeftRotate(tempNode);
            }
            else
            {
				tempNode = doubleLRrotation(tempNode);
            }
        }
    }
    /* Key is already in the tree, so duplicate was found */ 
	else
	{
		/* Add one to the frequency count */ 
		tempNode->count = tempNode->count + 1;
    }
    
    tempNode->height = checkHeight(tempNode);
    return(tempNode);
}

/*----
Purpose: A function that checks the height of the key in the AVL tree
Parameters: struct AVLtree * node (passing in the current node to be rotated), char * value (the key to be inserted)
Return: struct AVLtree * tempNode (returns the new root)
----*/
int checkHeight(struct AVLtree * tempNode)
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if(tempNode == NULL)
	{
		return (0);
	}
    if(tempNode->left == NULL)
	{
		leftHeight = 0;
	}
	else
	{
		leftHeight = 1 + tempNode->left->height;
	}
	if(tempNode->right == NULL)
	{
		rightHeight = 0;
	}
    else
	{
		rightHeight = 1 + tempNode->right->height;
	}
    if(leftHeight > rightHeight)
	{
		return (leftHeight);
	}
	
	return (rightHeight);
}

/*----
Purpose: A function that does a single rotate to the right
Parameters: struct AVLtree * node (passing in the current node to be rotated)
Return: struct AVLtree * tempNode (returns the new root)
----*/
struct AVLtree * singleRrotate(struct AVLtree * tempNode)
{
	/* Data structures theory - Single rotations: */
	/* R: ((T1 y T2) x T3) -> (T1 y (T2 x T3)) */
    struct AVLtree * temp2;
	
    temp2 = tempNode->left;
    tempNode->left= temp2->right;
    temp2->right = tempNode;
    
    tempNode->height = checkHeight(tempNode);
    temp2->height = checkHeight(temp2);
	
    return (temp2);
}

/*----
Purpose: A function that does a single rotate to the left
Parameters: struct AVLtree * node (passing in the current node to be rotated)
Return: struct AVLtree * tempNode (returns the new root)
----*/
struct AVLtree * singleLrotate(struct AVLtree * tempNode)
{
	/* Data structures theory */
	/* L: (T1 x (T2 y T3)) -> ((T1 x T2) y T3) */
	
    struct AVLtree * temp2;
    
	temp2 = tempNode->right;
    tempNode->right = temp2->left;
    temp2->left = tempNode;
    
    tempNode->height = checkHeight(tempNode);
    temp2->height = checkHeight(temp2);
	
    return (temp2);
}

struct AVLtree * singleRightRotate(struct AVLtree * tempNode)
{
    tempNode = singleLrotate(tempNode);
    
    return (tempNode);
}

struct AVLtree * singleLeftRotate(struct AVLtree * tempNode)
{
    tempNode = singleRrotate(tempNode);
    
    return (tempNode);
}

/*----
Purpose: A function that does a double rotate (only rotate when node has left child and the left child
		 also has a right child
Parameters: struct AVLtree * node (passing in the current node to be rotated)
Return: struct AVLtree * tempNode (returns the new root)
----*/
struct AVLtree * doubleLRrotation(struct AVLtree * tempNode)
{
	/* Data structures theory - Double rotations: */
	/* LR: ((T0 y (T1 z T2)) x T3) -> ((T0 x T1)) z (T2 y T3) */
	
    tempNode->left = singleLrotate(tempNode->left);
    tempNode = singleRrotate(tempNode);
    
    return (tempNode);
}

/*----
Purpose: A function that does a double rotate (only rotate when node has right child and the right child
		 also has a left child
Parameters: struct AVLtree * node (passing in the current node to be rotated)
Return: struct AVLtree * tempNode (returns the new root)
----*/
struct AVLtree * doubleRLrotation(struct AVLtree * tempNode)
{
	/* Data structures theory - Double rotations: */
	/* RL: (T0 x ((T1 z T2) y T3)) -> ((T0 x T1)) z (T2 y T3) */
	
    tempNode->right = singleRrotate(tempNode->right);
    tempNode = singleLrotate(tempNode);
    
    return(tempNode);
}

/*----
Purpose: A function that checks the balance factor of the data, if its greater than 1 or less than 1 it needs to be rebalanced
Parameters: struct AVLtree * tempNode (passing in the current node to check balance factor)
Return: int ( passes back the balance factor result )
----*/
int balanceFactor(struct AVLtree * tempNode)
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if(tempNode == NULL)
	{
		return (0);
	}
    if(tempNode->left == NULL)
	{
		leftHeight = 0;
	}
    else
	{
		leftHeight = 1 + tempNode->left->height;
	}
    if(tempNode->right == NULL)
	{
		rightHeight = 0;
	}
    else
	{
		rightHeight = 1 + tempNode->right->height;
	}
    return(leftHeight - rightHeight);
}

/*----
Purpose: A function that checks if the string is empty or has spaces
Parameters: const char * s (string to check if it is empty or has spaces)
Return: int ( return 0 or 1 indicating pass or fail)
----*/
int isEmpty(const char * input) 
{
    while (*input != '\0') 
    {
        if (!isspace(*input))
        {
            return 0;
        }
        input++;
    }
    
    return 1;
}

/*----
Purpose: A function that finds the key to be printed out
Parameters: AVLtree * keyToFind (passes in the AVLtree), char * input (key to be found)
Return: struct AVLtree * result ( passses back the AVLtree node with the key)
----*/
struct AVLtree * findKey(struct AVLtree * keyToFind, char * input)
{	
    if( keyToFind == NULL )
    {
        return NULL;
    }
    if(strcmp( input, keyToFind->key) < 0) 
    {    
        return findKey(keyToFind->left, input );
    }
    else if(strcmp( input, keyToFind->key) > 0) 
    {
        return findKey(keyToFind->right, input );
    }
    else
    {
        return keyToFind;
    }
}

/*----
Purpose: A function that prints all keys above the input value
Parameters: AVLtree * tempNode (passes in the AVLtree), int value (print all keys above this value)
Return: NOTHING
----*/
void printAllAboveKey(struct AVLtree * tempNode, int value)
{   
    if(tempNode != NULL)
    {
        printAllAboveKey(tempNode->left, value);
        if( tempNode->count > value) 
		{
			printf("key: %s, frequency: %d\n", tempNode->key, tempNode->count);
        }
        printAllAboveKey(tempNode->right, value);
    }
}

/*----
Purpose: A function that deletes a key from AVL tree and performs rotations if needed to balance tree
Parameters: struct AVLtree * node (passing in the current node to be rotated), char * value (the key to be deleted)
Return: struct AVLtree * tempNode (returns the new root)
----*/
struct AVLtree * deleteKey(struct AVLtree * tempNode, char * value)
{       
    struct AVLtree * temp2;
	
    if(tempNode == NULL)
    {
        return NULL;
    }
    
    else if(strcmp( value, tempNode->key) > 0)  
    {
        tempNode->right = deleteKey(tempNode->right, value);
        if(balanceFactor(tempNode) == 2)
        {
            if(balanceFactor(tempNode->left) >= 0)
            {
                tempNode = singleLeftRotate(tempNode);
            }
            else
            {
                tempNode = doubleLRrotation(tempNode);
            }
        }
    }
    
    else if(strcmp( value, tempNode->key) < 0)
    {
        tempNode->left = deleteKey(tempNode->left, value);
        if(balanceFactor(tempNode) == -2)//Rebalance during windup
        {	
            if(balanceFactor(tempNode->right) <= 0)
            {
                tempNode = singleRightRotate(tempNode);
            }
            else
            {
                tempNode = doubleRLrotation(tempNode);
            }
        }   
    }
    
    /* Found data to be deleted */
    else
    {
        if (tempNode->count > 1)
        {
            tempNode->count = tempNode->count - 1;
        }
        else
        {	
            if(tempNode->right != NULL)
            {  
        		temp2 = tempNode->right;
                while(temp2->left != NULL)
                {
                    temp2 = temp2->left;
                }
            
                strcpy(tempNode->key, temp2->key);
                tempNode->right = deleteKey(tempNode->right, temp2->key);
            	
                /* Rebalance again */
                if(balanceFactor(tempNode) == 2)
                {
                    if(balanceFactor(tempNode->left) >= 0)
                    {
                        tempNode = singleLeftRotate(tempNode);
                    }
                    else
                    {
                        tempNode = doubleLRrotation(tempNode);
                    }
                }
            }
            else
            {
                return (tempNode->left);
            }
        }
    }
	
    tempNode->height = checkHeight(tempNode);
    return (tempNode);
}

/*----
Purpose: A function that finds the size of the AVL tree, and counts every key
Parameters: AVLtree * tempNode (passes in the AVLtree)
Return: int (sum of keys in the AVL tree)
----*/
int findMaxSize (struct AVLtree * tempNode) 
{
    if (tempNode == 0) return 0;
    return tempNode->maxSize + findMaxSize(tempNode->left) + findMaxSize(tempNode->right);
}

/*----
Purpose: A function that finds the height of the AVL tree
Parameters: AVLtree * tempNode (passes in the AVLtree)
Return: int (height of AVL tree)
----*/
int findMaxHeight(struct AVLtree * tempNode) 
{
    if (tempNode == NULL)
    {
        return 0;
    }
    else
    {
        /* calculate the depth of all the subtree's */
        int leftDepth;
        int rightDepth;
        
        leftDepth = findMaxHeight(tempNode->left);
        rightDepth = findMaxHeight(tempNode->right);
 
        /* use the larger one */
        if (leftDepth > rightDepth)
        { 
            return (leftDepth + 1);
        }
        else 
        {
            return (rightDepth + 1);
        }
    }
} 
	