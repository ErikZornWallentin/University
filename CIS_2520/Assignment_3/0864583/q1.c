/*************************q1.c****************************
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

#define MAXSIZE 100

typedef struct node {
	char type;
	float number;
	struct node * left;
	struct node * right;
	struct node * next;
}node;

/* Global head pointer and variables */
struct node * head = NULL;
char * x1 = "x1";
char * x2 = "x2";
char * x3 = "x3";
char * x4 = "x4";
char * x5 = "x5";
char * array[10][10];
int counter = 0;

/*Function Prototypes*/
void menu();
void display();
int getNumberWithErrorCheck(int * theNumber, int size);
char * checkBrackets(char * input); 
node * createTree(char * input);
int check(char * input, node * ptr, char a, char b); 
float subTree(node * ptr); 


int main (int argc, char *argv[]) 
{
	
	int userInput = 0;         /* The main menu user input variable */
	int userInputHolder = 0;      
    int checker = 1;              /* Checks if user wants to quit or not variable in main menu */
	int errorCode;                /* Error checker variable to check for bad input */
	
	char * token;
	char buf[80];
	char * userInput3 = NULL;
	
	node * result = NULL;
	
	char * argument = argv[1];
	char * tempArgument = "";
	
	int a = 0;
	int b = 0;
	
	
	if (argc == 2)
	{	
		printf("The argument supplied is %s\n", argument);
	}
	else if (argc >= 3)
	{
		printf("ERROR: Too many arguments found, try only 1 expression with no spaces!\n"); /* Exit the program */
		exit(0);
	}
	else
	{
		printf("ERROR: No arguments were found, please give an infix expression!\n"); /* Exit the program */
		exit(0);
	}
	
		
	do
    {
	    /* Call the main menu function to display the main menu */
        menu();
		
		scanf("%d", &userInput);
		
		/* This is a placeholder that fixes a bug with error checking */
        userInputHolder = userInput;
		
        /* Error checking part, it gives guidance on where you made the error */
        errorCode = getNumberWithErrorCheck(&userInput,4);
        if (errorCode == 0)
        {
        	userInput = userInputHolder;
		
			switch (userInput)
        	{
				case 1:
					
					printf("Binary Tree: \n");
					for (a = 0; a < 10; a++) 
					{
						for (b = 0; b < 10; b++) 
						{
							if	(array[a][b] != NULL)
							{
								printf("%s ", array[a][b]);
							}
						}
						printf("\n");
   					}
					
					break;
				case 2:
			    
			    	break;
				case 3:
			    
			    	break;
		    	case 4:
		    	
		    		break;
		    	case 5:
		    		printf("Please input variable name and new input: ");
					fgets(buf, sizeof(buf), stdin);
					
					size_t ln1 = strlen(buf) - 1;
					if (buf[ln1] == '\n')
					buf[ln1] = '\0';
				
					userInput3 = buf;
					token = strtok(userInput3, ",");
	   				
	   				if (strcmp (token,"x1") == 0)
					{
						token = strtok(NULL, ",");
						
						x1 = token;
						printf("Variable x1 was changed to: %s\n", x1);
					}
					
					else if (strcmp (token,"x2") == 0)
					{
						token = strtok(NULL, ",");
						
						x2 = token;
						printf("Variable x2 was changed to: %s\n", x2);
					}
					else if (strcmp (token,"x3") == 0)
					{
						token = strtok(NULL, ",");
						
						x3 = token;
						printf("Variable x3 was changed to: %s\n", x3);
					}
					else if (strcmp (token,"x4") == 0)
					{
						token = strtok(NULL, ",");
						
						x4 = token;
						printf("Variable x4 was changed to: %s\n", x4);
					}
					else if (strcmp (token,"x5") == 0)
					{
						token = strtok(NULL, ",");
						
						x5 = token;
						printf("Variable x5 was changed to: %s\n", x5);
					}
					else
					{
						printf("Incorrect variable!\n");
					}
	
		    		break;
				case 6:
					tempArgument = argument;
					/*printf("%s\n", argument);*/
					printf("%s\n", tempArgument);
					result = createTree(tempArgument);
					
					printf("The final result: %.2f\n", subTree(result));
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
    printf("1) Display\n");
    printf("2) Preorder\n");
    printf("3) Inorder\n");
	printf("4) Postorder\n");
	printf("5) Update\n");
	printf("6) Calculate\n");
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

char * checkBrackets(char * input) 
{
	int len = strlen(input);
	int slot = len-1;
	
	while (slot >= 0) 
	{
		if (input[slot] == ')') 
		{
			input[slot] = '\0';
			while (input[slot] != '(') 
			{
				if (slot == 0) 
				{ 
					printf("Error with bracket not closed\n");
					exit (1); 
				}
				slot = slot - 1;
			}
			/* now remove the parantheses from the string and re-lex */
			return &input[slot + 1];
		}
		if (input[slot] == '(') 
		{ 
			printf("Error with bracket not closed\n");
			exit (1); 
		}
		slot = slot - 1;
	}
	return NULL;
}		
	
	
node * createTree(char * input) 
{
	node * temp = malloc(sizeof(node));
	char * ptr = NULL;
	
	
	/*printf("parsing input: %s\n",input);*/
	
	/* replace the x1-x5 variables with the input from the user */ 
	if (strcmp (input,"x1") == 0)
	{
		if (strcmp (x1,"x1") != 0)
		{			
			input = x1;
			/*printf("Variable input was changed to: %s\n", input);*/
		}
	}
	else if (strcmp (input,"x2") == 0)
	{
		if (strcmp (x2,"x2") != 0)
		{			
			input = x2;
			/*printf("Variable input was changed to: %s\n", input);*/
		}
	}
	else if (strcmp (input,"x3") == 0)
	{
		if (strcmp (x3,"x3") != 0)
		{			
			input = x3;
			/*printf("Variable input was changed to: %s\n", input);*/
		}
	}
	else if (strcmp (input,"x4") == 0)
	{
		if (strcmp (x4,"x4") != 0)
		{			
			input = x4;
			/*printf("Variable input was changed to: %s\n", input);*/
		}
	}
	else if (strcmp (input,"x5") == 0)
	{
		if (strcmp (x5,"x5") != 0)
		{			
			input = x5;
			/*printf("Variable input was changed to: %s\n", input);*/
		}
	}
	
	
	fflush(stdout);
	
	if (check(input, temp, '+', '-') == 1 || check(input, temp, '*', '/') == 1)
	{
		return temp;
	}
	
	else if ( (ptr = checkBrackets(input)) ) 
	{
		return createTree(ptr);
	}
	
	/* strtof for tokening to floats instead of using strtok */
	temp->number = strtof(input, NULL);
	temp->type = 'o';
	
	return temp;
}


float subTree(node * ptr) 
{
	float right = 0.0;
	float left = 0.0; 
	float operationResult = 0.0;
	char buff[10];
	
	if (ptr->type == 'o') 
	{
		return ptr->number;
	}
	
	left = subTree(ptr->left);
	right = subTree(ptr->right);
	
	if (counter == 0)
	{
		//sprintf(array[9][0], "%f", left);
	
		sprintf(buff, "%f", left);
		array[9][0] =  &buff[0];
		array[8][1] = (char *) &ptr->type;
		array[9][2] = (char *) &right;
	}
	else if (counter == 1)
	{
		array[9][4] = (char *) &left;
		array[8][3] = (char *) &ptr->type;
		array[9][6] = (char *) &right;
	}
	else if (counter == 2)
	{
		array[8][3] = (char *) &ptr->type;
	}
	else if (counter == 3)
	{
		array[6][3] = (char *) &ptr->type;
		array[7][4] = (char *) &right;
	}
	
	counter = counter + 1;
	
	fflush(stdout);
	
	if (ptr->type == '+')
	{
		operationResult = left + right;
		return operationResult;
	}
	
	else if (ptr->type == '-') 
	{
		operationResult = left - right;
		return operationResult;
	}
	
	else if (ptr->type == '*') 
	{
		operationResult = left * right;
		return operationResult;
	}
	
	else if (ptr->type == '/') 
	{
		operationResult = left / right;
		return operationResult;
	}
	
	else
	{
		printf("Error with operands! Now exitting\n");
		exit(1);
	}
	
	return 0; 
}

	
int check(char * input, node * ptr, char a, char b) 
{
	int len = strlen(input); 
	int c = len-1;
	
	while (c >= 0) 
	{	// skip paranthesized expressions 
		if (input[c] == ')') 
		{
			while (input[c--] != '(') 
			{
				if (c < 0) 
				{ 
					printf("Error with bracket not closed\n");
					exit (1); 
				}
			}
		}
		
		if (input[c] == '(') 
		{ 
			printf("Error with bracket not closed\n");
			exit (1); 
		}
		
		if ((input[c] == a) || (input[c] == b)) 
		{
			ptr->type = input[c];
			input[c] = '\0';
			ptr->left = createTree(input);
			ptr->right = createTree(&input[c+1]);
			return 1;
		}			
		c--;
	}
	return 0;
}