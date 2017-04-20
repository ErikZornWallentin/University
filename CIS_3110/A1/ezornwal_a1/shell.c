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
#include <stdlib.h>		/* exit */
#include <unistd.h>		/* _exit, fork */
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>	/* pid_t */
#include <sys/wait.h>	/* waitpid */
#include <errno.h>


extern char **getln();

int searchInternalCommands(char **args);
int redirectInputAndOutput(int option, char **args, char **inputFilename, char **outputFilename);
int startCommand(char **args, int block, int inputResult, int outputResult, char * inputFilename, char * outputFilename);
int checkAmpersand(char **args);

int main() 
{
	char **args;
	
	int inputResult = 0;
	int outputResult = 0;
	
	char * inputFilename = "";
	char * outputFilename = "";
	
	int block;
	
	/* Loop forever! */
	while(1) 
	{
		
		/* Prompt for the user to see */
		printf(">> ");
		args = getln();
		
		/* If no input it will continue on the loop, fixes the user just pressing enter bug */
		if(args[0] == NULL)
		{
			continue;
		}
		
		/* Check for all internal shell commands such as: exit, args, name */
		if(searchInternalCommands(args))
		{
			continue;
		}
		
		/* Check for Ampersand */
		block = (checkAmpersand(args) == 0);
		
		
		/* Check for redirected input */
		inputResult = redirectInputAndOutput(1, args, &inputFilename, &outputFilename);
		if (inputResult == -1)
		{
			fprintf(stderr, "ERROR: Give a proper file argument!\n");
		}
		else if (inputResult == 1)
		{
			printf("Redirecting input from: %s\n", inputFilename);
		}
		
		/* Check for redirected output */
		outputResult = redirectInputAndOutput(2, args, &inputFilename, &outputFilename);
		if (outputResult == -1)
		{
			fprintf(stderr, "ERROR: Give a proper file argument!\n");
		}
		else if (outputResult == 1)
		{
			printf("Redirecting output from: %s\n", outputFilename);
		}
		
		/* Start the command */
        startCommand(args, block, inputResult, outputResult, inputFilename, outputFilename);
	}
	return 0;
}

/*----
Purpose: A function that checks any internal commands from user: exit, args, name
Parameters: char **args(the command given from the user)    
Return: int (success or failure)
----*/
int searchInternalCommands(char **args) 
{
	int n = 0;
	int i = 0;
	
	if(strcmp(args[0], "exit") == 0) 
	{
		fprintf(stderr, "Now exiting the shell!\n");
		exit(0);
	}
  
	else if(strcmp(args[0], "args") == 0) 
	{
	  
		if (args[1] == NULL)
		{
			fprintf(stderr, "ERROR: No arguments passed to args command!\n");
			return 0;
		}
	
		for(i = 1; args[i] != NULL; i++) 
		{
			n++;
		}
		
		printf("argc = %d, args =", n);
		
		if (args[1] != NULL)
		{
			printf(" %s", args[1]);
		}
	
		for(i = 2; args[i] != NULL; i++) 
		{
			printf(", %s", args[i]);
		}
	
		printf("\n");
	
	}
	
	else if(strcmp(args[0], "add") == 0) 
	{
		int result = 0;
		
		if (args[1] == NULL)
		{
			fprintf(stderr, "ERROR: No arguments passed to add command!\n");
			return 0;
		}
		
		if (args[1] != NULL)
		{
			printf("%s", args[1]);
			result += (int)strtol(args[1], NULL, 0);
		}
		
		for(i = 2; args[i] != NULL; i++) 
		{
			result += (int)strtol(args[i], NULL, 0);
			printf(" + %s", args[i]);
		}
		
		printf(" = %d\n", result);
	}
	
	else if(strcmp(args[0], "name") == 0) 
	{
		if (args[1] == NULL)
		{
			fprintf(stderr, "ERROR: No arguments passed to name command!\n");
			return 0;
		}
		
		printf("Your full name is:");
		for(i = 1; args[i] != NULL; i++) 
		{
			/* Get first and last name only ! */
			if (i < 3)
			{
				printf(" %s", args[i]);
			}
		}
		printf("\n");
	}
	
	return 0;
}

/*----
Purpose: A function that checks for redirection for files
Parameters: int option( 1 for input and 2 for output redirection), char **args(the command given from the user),
            char * inputFilename(gets the input file name), char * outputFilename (gets the output file name)         
Return: int (success or failure)
----*/
int redirectInputAndOutput(int option, char **args, char **inputFilename, char **outputFilename)
{
	int i = 0;
	int n = 0;

	for(i = 0; args[i] != NULL; i++) 
	{
		/* check for input redirection */
		if (option == 1)
		{
			if(args[i][0] == '<') 
			{
				free(args[i]);

				/* Get the file name */
				if(args[i+1] != NULL) 
				{
					*inputFilename = args[i+1];
				}
				/* Return failure if there is no argument after < */
				else 
				{
					return -1;
				}

				// Adjust the rest of the arguments in the array
				for(n = i; args[n-1] != NULL; n++) 
				{
					args[n] = args[n+2];
				}

				return 1;
			}
		}
		/* check for output redirection */
		else if (option == 2)
		{
			if(args[i][0] == '>') 
			{
				free(args[i]);

				/* Get the file name */
				if(args[i+1] != NULL) 
				{
					*outputFilename = args[i+1];
				} 
				else 
				{
					return -1;
				}

				// Adjust the rest of the arguments in the array
				for(n = i; args[n-1] != NULL; n++) {
					args[n] = args[n+2];
				}

				return 1;
			}
		}
	}
	
	return 0;
}

/*----
Purpose: A function that checks for the ampersand as the final argument
Parameters: char **args(the command given from the user)
Return: int (success or failure)
----*/
int checkAmpersand(char **args)
{
	int n = 0;

	for(n = 1; args[n] != NULL; n++);

	if(args[n-1][0] == '&') 
	{
		free(args[n-1]);
		args[n-1] = NULL;
		return 1;
	}
  
	return 0;
}

/*----
Purpose: A function that does the command given from the user
Parameters: char **args(the command given from the user), int block (check ampersands), 
            int inputResult(checks for input file '<'), int outputResult(checks for output file '>'),
			char * inputFilename(gets the input file name), char * outputFilename (gets the output file name)
Return: int (success or failure)
----*/
int startCommand(char **args, int block, int inputResult, int outputResult, char * inputFilename, char * outputFilename)
{
	pid_t pid;
	int result = 0;
	int status;
	
	pid = fork();

	/* Errors in fork, EAGAIN, ENOMEM, it will return -1 from fork call */
	if (pid == -1)
	{
		perror("Unable to fork: ");
		return 0;
	}
	/* Success, we are in the child process */
	else if (pid == 0) 
	{
		// Set up redirection in the child process
		if(inputResult == 1)
		{
			freopen(inputFilename, "r", stdin);
		}

		if(outputResult == 1)
		{
			freopen(outputFilename, "w+", stdout);
		}

		// Execute the command
		result = execvp(args[0], args);

		exit(1);
	}

	/* waitpid: waits for a child process to finish */
	if(block) 
	{
		printf("Waiting for child the child (%d)\n", pid);
		result = waitpid(pid, &status, 0);
		printf("Child (%d) has finished!\n", pid);
		
		/* Below part gets rid of a warning... */
		if (result == 0)
		{

		}
	}
	
	return 1;
}