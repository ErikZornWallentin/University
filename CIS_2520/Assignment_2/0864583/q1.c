/*************************q1.c****************************
Student Name: Erik Zorn - Wallentin  Student Number: 0864583
Date: Mon, Oct.13 / 2014             Course Name: CIS2520
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

/* Comment for programming at my house: set PATH=C:\MinGW\bin;%PATH% */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define MAXSIZE 100 

/* Function Prototypes */
void menu();
int getNumberWithErrorCheck(int * theNumber, int size);
void add(int state, char * plateNum, int num, char * carState, int returnDate);
void display();
struct available_for_rent *sorting(struct available_for_rent *head);
struct available_for_rent *merger(struct available_for_rent *head_one, struct available_for_rent *head_two);
struct in_repair *findDelete(struct in_repair *currP, char * value);
void delete();
double calculateIncome();
FILE *readFile(char * filename, int n);
void writeFile();

struct available_for_rent
{
	int slot;
    int mileage;
	char * plate_number;
	char * car_state;
	int expectedReturnDate;
    struct available_for_rent *next;
}*head=NULL;

struct rented
{
    int slot;
	int mileage;
	char * plate_number;
	char * car_state;
    int expectedReturnDate;
    struct rented *next;
}*head2=NULL;

struct in_repair
{
    int slot;
    int mileage;
	char * plate_number;
	char * car_state;
	int expectedReturnDate;
    struct in_repair *next;
}*head3=NULL;
 
int main (int argc, char *argv[])
{   

	char buf[80];
	int holder;
	int userInput = 0;         /* The main menu user input variable */
	int userInputHolder = 0;
	char * userInput2 = NULL;
	double totalIncome = 0;         
    int checker = 1;              /* Checks if user wants to quit or not variable in main menu */
	int errorCode;                /* Error checker variable to check for bad input */
	
	char buffer2[80];
	char string2[40][80];
	int m = 0;
	int i = 0;
	int counter = 0;
	FILE * file = NULL;
	char * token;
	
	int holder1 = 0;
	char * holder2;
	int holder3;
	char * holder4;
	int holder5;
	
	
	file = readFile(argv[1],argc); /* Error checking for the filename */
	if (file != NULL)
	{
	    file = fopen("disk.txt","r");
	    while (fgets(buffer2,80,file))
	    {
	        strcpy(string2[m], buffer2);
	        m++;
	        i++;
	    }
	}
	
	/* Token each piece of data and the result goes into the proper list */
	for ( m = 0; m < i; m++)
	{
	    token = strtok(string2[m], ",");
	    holder1 = atoi(&token[0]);

	    while ( token != NULL)
	    {
	        if (counter == 1)
	        {
	            holder2 = &token[0];
	        }
	        else if (counter == 2)
	        {
	            holder3 = atoi(&token[0]);
	        }
	        else if (counter == 3)
	        {
	            holder4 = &token[0];
	        }
	        else if (counter == 4)
	        {
	            holder5 = atoi(&token[0]);
	        }
	        counter++;
	        token = strtok(NULL, ",");       
	    }
	    add(holder1, holder2,holder3, holder4, holder5);
	    counter = 0;
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
				printf("Please input plate number: \n");
				fgets(buf, sizeof(buf), stdin);
				/* Get rid of the null terminator */
				size_t ln1 = strlen(buf) - 1;
				if (buf[ln1] == '\n')
				buf[ln1] = '\0';
				
				userInput2 = buf;
				
				printf("Please input mileage: \n");
				scanf("%d", &holder);

				add(1, userInput2,holder, "New Car", 0);
				
				break;
			case 2:
			    printf("Please input plate number: \n");
				fgets(buf, sizeof(buf), stdin);
				/* Get rid of the null terminator */
				size_t ln2 = strlen(buf) - 1;
				if (buf[ln2] == '\n')
				buf[ln2] = '\0';
				
				userInput2 = buf;
				
				printf("Please input mileage: \n");
				scanf("%d", &holder);

				add(1, userInput2,holder, "Returned Car", 0);
			    break;
			case 3:
			    printf("Please input plate number: \n");
				fgets(buf, sizeof(buf), stdin);
				/* Get rid of the null terminator */
				size_t ln3 = strlen(buf) - 1;
				if (buf[ln3] == '\n')
				buf[ln3] = '\0';
				
				userInput2 = buf;
				
				printf("Please input mileage: \n");
				scanf("%d", &holder);

				add(3, userInput2,holder, "Returned Car", 0);
			    break;
		    case 4:
		    	printf("Please input plate number: \n");
				fgets(buf, sizeof(buf), stdin);
				/* Get rid of the null terminator */
				size_t ln4 = strlen(buf) - 1;
				if (buf[ln4] == '\n')
				buf[ln4] = '\0';
		    	
		    	head3 = findDelete(head3, buf);
		    	break;
		    case 5:
		    	delete();
		    	break;
			case 6:
				/* sort the list before printing it*/
				head = sorting(head);
				/* print the lists */
				display();
				break;
			case 7:
				totalIncome = calculateIncome();
				printf("\nCharge for a flat rate of $40.00 for up to 100km and 15 cents per km after 100 kilometers\n");
                printf("Total income from rented cars: $%.2lf\n", totalIncome);
				/* Write to the file */
				writeFile();
                getchar();
			    /* Quit the program */
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
    printf("1) Add a new car to the available-for-rent list\n");
    printf("2) Add a returned car to the available-for-rent list\n");
    printf("3) Add a returned car to the repair list\n");
	printf("4) Transfer a car from repair list to the available-for-rent list\n");
	printf("5) Rent first available car\n");
	printf("6) Print all the lists\n");
	printf("7) Quit\n"); 
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
Purpose: Add information (node) to the linked list
Parameters: int state(1 for the available_for_rent list, 2 for the rented and 3 for in_repair), 
            char * plateNum (plate number given), int num (mileage number given), char * carState (returned or new car), 
            int returnDate(the expected return date for the car)
Return: void (nothing)
----*/
void add(int state, char * plateNum, int num, char * carState, int returnDate )
{
  	if (state == 1)
  	{
  	    struct available_for_rent *new_node;

	    new_node=(struct available_for_rent *)malloc(sizeof(struct available_for_rent));

 	    if(new_node == NULL)
        {
            return;
        }
		
        new_node->slot = state;
        new_node->plate_number = malloc(strlen(plateNum)+1);
        strcpy(new_node->plate_number,plateNum);
	    new_node->mileage = num;
	    new_node->car_state = malloc(strlen(carState)+1);
        strcpy(new_node->car_state, carState);
		new_node->expectedReturnDate = returnDate;
 	    new_node->next = NULL;
    
        if(head == NULL)
        {
            head = new_node;
        }
        else
        {
            new_node->next =head;
            head = new_node;
        }
		printf("\nCreated some new data in the available for rent list.\n");
    }
    else if (state == 2)
  	{
  	    struct rented *new_node;

	    new_node=(struct rented *)malloc(sizeof(struct rented));

 	    if(new_node == NULL)
        {
            return;
        }
     
	    new_node->slot = state;
        new_node->plate_number = malloc(strlen(plateNum)+1);
        strcpy(new_node->plate_number,plateNum);
	    new_node->mileage = num;
	    new_node->car_state = malloc(strlen(carState)+1);
        strcpy(new_node->car_state, carState);
        new_node->expectedReturnDate = returnDate;
 	    new_node->next = NULL;
    
        if(head2 == NULL)
        {
            head2 = new_node;
        }
        else
        {
            new_node->next = head2;
            head2 = new_node;
        }
		printf("\nCreated some new data in the rented list.\n");
    }
    else
    {
        struct in_repair *new_node;

        new_node=(struct in_repair *)malloc(sizeof(struct in_repair));

 	    if(new_node == NULL)
        {
            return;
        }
     
	    new_node->slot = state;
        new_node->plate_number = malloc(strlen(plateNum)+1);
        strcpy(new_node->plate_number,plateNum);
	    new_node->mileage = num;
	    new_node->car_state = malloc(strlen(carState)+1);
        strcpy(new_node->car_state, carState);
		new_node->expectedReturnDate = returnDate;
 	    new_node->next = NULL;
    
        if(head3 == NULL)
        {
            head3 = new_node;
        }
        else
        {
            new_node->next = head3;
            head3 = new_node;
        }
		printf("\nCreated some new data in the repair list.\n");
    }
	
}

/*----
Purpose: Deletes a node from available_for_rent link list and calls the add function to add a node to rented list 
Parameters: nothing
Return: void (nothing)
----*/
void delete()
{
    struct available_for_rent *temp;

	if(head == NULL)
    {
    	printf("\nNo cars to rent!\n");
        return;
    }
    int userInput3 = 0;
    printf("\nPlease input the expected return date (YYMMDD): ");
    scanf("%d", &userInput3);
    
    temp = head;
    add(2,temp->plate_number, temp->mileage, temp->car_state, userInput3);
    head = head->next;
    free(temp);
}

/*----
Purpose: Deletes a node from available_for_rent link list and calls the add function to add a node to rented list 
Parameters: struct in_repair * currPtr( the head of in in_repair linked list), char * value (license plate to check for)
Return: struct in_repair * findDelete
----*/
struct in_repair *findDelete(struct in_repair *currPtr, char * value)
{
  
    if (currPtr == NULL)
    {
        return NULL;
    }

    if(strcmp(currPtr->plate_number, value) == 0) 
    {
        struct in_repair *tempNextPtr;
    
        /*Add the current node to the available for rent list*/
		printf("\nTransfering car(license plate): %s to the rented list.\n", currPtr->plate_number);
        
		add(1, currPtr->plate_number, currPtr->mileage, currPtr->car_state, 0);

        tempNextPtr = currPtr->next;

        free(currPtr);
        return tempNextPtr;
    }
  
    /*Use recursion to get to the node easier*/
    currPtr->next = findDelete(currPtr->next, value);

    return currPtr;
}

/*----
Purpose: Prints out all the linked lists contents
Parameters: void (nothing)
Return: void (nothing)
----*/
void display()
{
    struct available_for_rent *temp;
    temp = head;
    
    struct rented *temp2;
    temp2 = head2;
    
    struct in_repair *temp3;
    temp3 = head3;
    
    printf("\n**********************************\n");
	printf("Printing available for rent list: \n");
	printf("**********************************\n");
    while(temp != NULL)
    {
        printf("%s: %s Mileage: %d\n", temp->car_state, temp->plate_number, temp->mileage);
        temp = temp->next;
    }
    
    printf("\n**********************************\n");
	printf("Printing the rented list: \n");
	printf("**********************************\n");
    while(temp2 != NULL)
    {
        printf("%s: %s Mileage: %d Return Date: %d\n", temp2->car_state, temp2->plate_number, temp2->mileage, temp2->expectedReturnDate);
        temp2 = temp2->next;
    }
    
    printf("\n**********************************\n");
	printf("Printing in-repair list: \n");
	printf("**********************************\n");
    while(temp3 != NULL)
    {
        printf("%s: %s Mileage: %d\n", temp3->car_state, temp3->plate_number, temp3->mileage);
        temp3 = temp3->next;
    }
    
    /* Hold for user input */
	getchar();
}

/*----
Purpose: This purpose of this function is to perform a merge sort on the available for rent linked list
Parameters: struct available_for_rent *head (head of the linked list)
Return: struct available_for_rent (returns the head back)
----*/
struct available_for_rent *sorting(struct available_for_rent *head)
{
    struct available_for_rent *head1;
    struct available_for_rent *head2;

    if((head == NULL) || (head->next == NULL)) 
    {
        return head;
    }

    head1 = head;
    head2 = head->next;
    
    while((head2 != NULL) && (head2->next != NULL)) 
    {
        head = head->next;
        head2 = head->next->next;
    }
    
    head2 = head->next;
    head->next = NULL;

    return merger(sorting(head1), sorting(head2));
}

/*----
Purpose: This purpose of this function is to merge the lists from the 2 heads
Parameters: struct available_for_rent *head1 (1st head of the linked list), struct available_for_rent *head2 (2nd head of the linked list)
Return: struct available_for_rent (returns the head back)
----*/
struct available_for_rent *merger(struct available_for_rent *head1, struct available_for_rent *head2) 
{
    struct available_for_rent *head3;

    if(head1 == NULL)
    {
        return head2;
    }

    if(head2 == NULL)
    { 
        return head1;
    }

    if(head1->mileage < head2->mileage) 
    {
        head3 = head1;
        head3->next = merger(head1->next, head2);
    } 
    else 
    {
        head3 = head2;
        head3->next = merger(head1, head2->next);
    }

    return head3;
}

/*----
Purpose: calculate the total income earned from the miles driven on the cars, converts miles to kilometers
Parameters: None
Return: return result( total income generated )
----*/
double calculateIncome()
{
	struct rented *temp4;
    temp4 = head2;
    int income = 0;
    double km = 0;
	double result = 0.0;
	
    while(temp4 != NULL)
    {       	
      	/* Convert to Kilometers, make sure mileage is 0 or above!*/
      	if (temp4->mileage >= 0)
        {
            km = (double)temp4->mileage/0.62137;
            if (km <= 100)
            {
                income = 40.0;
            }
            else if (km > 100)
            {
            	km = km - 100;
                income = km * 0.15; /* 15 cents for each km after 100 */
                income = income + 40.0; /* add the base 40$ */
            }
            result = result + income;
        }
        temp4 = temp4->next;
    }
    return result;
}

/*----
Purpose: The purpose of this function is to get the input disk.txt file and start generating the lists,
         it has error checking, and will always print out the file contents before generating
Parameters: char * filename(the 2nd input of command line) and int n (amount of arguments on command line)
Return: file * (file variable)
----*/
FILE *readFile(char * filename, int n)
{
    FILE *f = NULL;
    char txt[5] = ".txt";
    
    char string[40][80];
    char buffer[80];
    int i = 1;

    if(n == 2)
    {   
    /* Error check a few stuff that could go wrong */ 
        if (strcmp(filename,"disk.txt") == 0)
        {
            printf("The file that was supplied is %s\n", filename);
            f = fopen(filename, "r");
            if (f == NULL)
            {
                printf("I could not find the file, exiting now");
                exit(0);
            }
        }

        else if(strcmp(filename,"disk") == 0)
        {          
            strcat(filename, txt);
            printf("The file that was supplied is %s\n", filename);          
            f = fopen(filename, "r"); 
            if (f == NULL)
            {
                printf("I could not find the file, exiting now");
                exit(0);
            }
 
        }
        else
        {
            printf("Not a proper file, try disk.txt\n");
            exit(0);
       
        }

        while(fgets(buffer,151,f))                        /* Print file */
        {
            strcpy(string[i],buffer);
            /*printf("File line %d: %s",i,string[i]);*/
            i++;
        } 
        
    }

    else if(n > 2)
    {
        printf("Too many arguments given, please give the input text file.\n");
        exit(0);
    }

    else
    {
        printf("One argument was expected, please give the input text file.\n");
        exit(0);
    }
  
    return f;
}

/*----
Purpose: The purpose of this function is to write all the linked lists data to the file disk.txt to save for a later time
Parameters: nothing
Return: void (nothing)
----*/
void writeFile()
{
	struct available_for_rent *temp;
    temp = head;
    
    struct rented *temp2;
    temp2 = head2;
    
    struct in_repair *temp3;
    temp3 = head3;
	
    FILE *fptr  = NULL;
    fptr = fopen("disk.txt","w");
    
	if(fptr == NULL)
	{
        printf("Error: File does not exist!");
        exit(0);
    }
	
	while(temp != NULL)
    {
        fprintf(fptr,"%d,%s,%d,%s,%d\n", temp->slot, temp->plate_number, temp->mileage, temp->car_state, temp->expectedReturnDate);
        temp = temp->next;
    }

	while(temp2 != NULL)
    {
        fprintf(fptr,"%d,%s,%d,%s,%d\n", temp2->slot, temp2->plate_number, temp2->mileage, temp2->car_state, temp2->expectedReturnDate);
        temp2 = temp2->next;
    }
	
	while(temp3 != NULL)
    {
        fprintf(fptr,"%d,%s,%d,%s,%d\n", temp3->slot, temp3->plate_number, temp3->mileage, temp3->car_state, temp3->expectedReturnDate);
        temp3 = temp3->next;
    }
	
    fclose(fptr);
}