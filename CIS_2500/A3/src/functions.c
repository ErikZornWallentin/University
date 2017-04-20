/*************************A3.c****************************
Student Name: Erik Zorn - Wallentin  Student Number: 0864583
Date: Fri, March.14 / 2014              Course Name: CIS2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

#include "functions.h"



/*----
Purpose: The purpose of this function is to get the input assets/room.txt file and start generating the game,
         it has error checking, and will always print out the file contents before generating
Parameters: char * filename(the 2nd input of command line) and int n (amount of arguments on command line)
Return: file * (file variable)
----*/
FILE *readFile(char * filename, int n)
{
    FILE *f = NULL;
    char assets[30] ="assets/"; 
    char txt[5] = ".txt";
    
    char string[12][151];
    char buffer[151];
    int i = 1;

    if(n == 2)
    {   
	/* Error check a few stuff that could go wrong */ 
        if (strcmp(filename,"assets/room.txt") == 0)
    	{
            printf("The file that was supplied is %s\n", filename);
            f = fopen(filename, "r");
            if (f == NULL)
            {
                printf("I could not find the file, exiting now");
                exit(0);
            }
    	}

        else if(strcmp(filename,"room.txt") == 0)
        {
            
            strcat(assets, filename);
            printf("The file that was supplied is %s\n", filename);
            f = fopen(assets, "r"); 
            if (f == NULL)
            {
                printf("I could not find the file, exiting now.\n");
                exit(0);
            }   
        }

        else if(strcmp(filename,"room") == 0)
        {          
            strcat(assets, filename);
            strcat(assets, txt);
            printf("The file that was supplied is %s\n", filename);          
            f = fopen(assets, "r"); 
            if (f == NULL)
            {
                printf("I could not find the file, exiting now");
                exit(0);
            }
 
        }

        else if(strcmp(filename,"assets/room") == 0)
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
            printf("Not a proper file, try the room file with .txt ending\n");
            exit(0);
       
    	}

        while(fgets(buffer,151,f))						/* Print file */
    	{
            strcpy(string[i],buffer);
            printf("File line %d: %s",i,string[i]);
            i++;
    	} 
        
        getchar(); 								/* Hold the user */
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
Purpose: The purpose of this function is to get 'tokens' from a file and parse the text into the struct
         for every bit of info needed for the room.
Parameters: char * token(every bit of info on file), struct Room * room (pass in a room number)
Return: nothing
----*/

void parseText(char * token, struct Room * room)
{
    int holder = 0;                   /* Holds the first number variable for anything with a comma Ex. h2,2 */
    int holder2 = 0;                  /* Holds the second number variable for anything with a comma Ex. h2,2 */
    int holder3 = atoi(&token[0]);

    if (token[0] == 'd')
    {
        if(token[1] == 'e')
        {   
            room->eastDoor = atoi(&token[2]);     
        }
        
        else if(token[1] == 'w')
        {   
            room->westDoor = atoi(&token[2]);     
        }
        
        else if(token[1] == 's')
        {   
            room->southDoor = atoi(&token[2]);    
        } 
  
        else if(token[1] == 'n')
        {   
            room->northDoor = atoi(&token[2]);    
        }        
    }

    else if (token[0] == 'g')
    {
        
        holder = atoi(&token[1]);
        if (holder >= 10)
        {
            holder2 = atoi(&token[4]);
        }
        else
        {
            holder2 = atoi(&token[3]);
        }     
        if(holder <= 25 && holder > 0 && holder2 <= 25 && holder2 > 0)
        {   
            
            room->goldX = holder;
            room->goldY = holder2;
        }
        
        else
        {   
            printf("Error with file! Dimensions too large or error with input!\n"); 
        }     
    }
	
    else if (token[0] == 'h')
    {
        holder = atoi(&token[1]);
        if (holder >= 10)
        {
            holder2 = atoi(&token[4]);
        }
        else
        {
            holder2 = atoi(&token[3]);
        }
        if(holder <= 25 && holder > 0 && holder2 <= 25 && holder2 > 0)
        {   
            room->heroX = holder;
            room->heroY = holder2;
        }
        
        else
        {   
            printf("Error with file! Dimensions too large or error with input!\n"); 
        }     
    }
	
    else if (token[0] == 'p')
    {
        holder = atoi(&token[1]);
        if (holder >= 10)
        {
            holder2 = atoi(&token[4]);
        }
        else
        {
            holder2 = atoi(&token[3]);
        }
        if(holder <= 25 && holder > 0 && holder2 <= 25 && holder2 > 0)
        {   
            room->potionX = holder;
            room->potionY = holder2;
        }
        
        else
        {   
            printf("Error with file! Dimensions too large or error with input!\n"); 
        }     
    }
	
    else if (token[0] == 'm')
    {
        holder = atoi(&token[1]);
        if (holder >= 10)
        {
            holder2 = atoi(&token[4]);
        }
        else
        {
            holder2 = atoi(&token[3]);
        }
        if(holder <= 25 && holder > 0 && holder2 <= 25 && holder2 > 0)
        {   
            room->monsterX = holder;
            room->monsterY = holder2;
        }
        
        else
        {   
            printf("Error with file! Dimensions too large or error with input!\n"); 
        }     
    }
	
    else if (token[0] == 's')
    {
        holder = atoi(&token[1]);
        if (holder >= 10)
        {
            holder2 = atoi(&token[4]);
        }
        else
        {
            holder2 = atoi(&token[3]);
        }
        if(holder <= 25 && holder > 0 && holder2 <= 25 && holder2 > 0)
        {   
            room->stairX = holder;
            room->stairY = holder2;
        }
        
        else
        {   
            printf("Error with file! Dimensions too large or error with input!\n"); 
        }     
    }
    
    else if (token[0] == 'w')
    {
        holder = atoi(&token[1]);
        if (holder >= 10)
        {
            holder2 = atoi(&token[4]);
        }
        else
        {
            holder2 = atoi(&token[3]);
        }
        if(holder <= 25 && holder > 0 && holder2 <= 25 && holder2 > 0)
        {   
            room->weaponX = holder;
            room->weaponY = holder2;
        }
        
        else
        {   
            printf("Error with file! Dimensions too large or error with input!\n"); 
        }     
    }
	
    else if (holder3 > 0 && holder3 <= 25)
    {
        room->yMaxWall = holder3;
    }

    else if (holder3 > 25)
    {
        printf("Room too large! Needs to be 25 or smaller. Resizing room to 10!\n");
        room->yMaxWall = 10;
    }
    
}

/*----
Purpose: The purpose of this function is to print every piece of room info 
Parameters: int j(room number slot), struct Room * room (pass in a room number)
Return: nothing
----*/

void printRoom(struct Room * room, int j)
{   
    int x = 0;
    int y = 0;
    if(j == 1)
    {

        /* Draw left to down side */
        for(x =room->xWall; x < (room->xMaxWall)+(room->xWall); x++)
        {  
            if (room->westDoor != 0 && x == room->westDoor+3)
            {
                mvaddch(x,room->yWall, '+');
            }
			
            else
            {
                mvaddch(x,room->yWall, '|');
                if(room->westDoor > (room->xMaxWall)+(room->xWall))
                {
                    mvaddch(room->xWall+1,room->yWall, '+');    
                }
                
            }
			
            for(y = room->yWall; y < (room->yMaxWall)+1; y++)
            {
               mvaddch(x,y+1, '.'); 
            }
        }

        /* Draw right to down side */
        for(x =room->xWall; x < (room->xMaxWall)+(room->xWall); x++)
        {
            if (room->eastDoor != 0 && x == room->eastDoor+3)
            {
                mvaddch(x,(room->yWall)+(room->yMaxWall)-1, '+');
            }
  
            else
            {			
                mvaddch(x,(room->yWall)+(room->yMaxWall)-1, '|');
            }
        }

        /* Draw top to right side */
        for(y =room->yWall; y < (room->yMaxWall)+(room->yWall)-2; y++)
        {  
            if(room->northDoor != 0 && y == room->northDoor+2)
            {
                mvaddch(room->xWall,(y)+1, '+');
            }

            else
            {			
                mvaddch(room->xWall,(y)+1, '-');
            }
        }
 
        /* Draw bottom to right side */
        for(y =room->yWall; y < (room->yMaxWall)+(room->yWall)-2; y++)
        {  
            if(room->southDoor != 0 && y == room->southDoor+2)
            {
                mvaddch((room->xWall)+(room->xMaxWall)-1,(y)+1, '+');
            }

            else
            {			
                mvaddch((room->xWall)+(room->xMaxWall)-1,(y)+1, '-');
            }
        }
                                                                 
        if ( room->heroX > 0 && room->heroY > 0 &&  (room->heroX)+3 < (room->xMaxWall)+2 &&  (room->heroY)+3 < (room->yMaxWall)+2 )
        {
            mvaddch((room->heroX)+(room->xWall),(room->heroY)+(room->yWall),'@');
            
        }
        
        if ( room->heroX == 0 || room->heroY == 0 ||  (room->heroX)+3 > (room->xMaxWall)+1 ||  (room->heroY)+3 > (room->yMaxWall)+1 )
        {
            mvaddch(1+(room->xWall),1+(room->yWall),'@');
            
        }
      
        if ( room->goldX > 0 && room->goldY > 0 &&  (room->goldX)+3 < (room->xMaxWall)+2 &&  (room->goldY)+3 < (room->yMaxWall)+2 )
        {
            mvaddch((room->goldX)+(room->xWall),(room->goldY)+(room->yWall),'*');
            
        }
        
        if ( (room->goldX)+3 > (room->xMaxWall)+1 ||  (room->goldY)+3 > (room->yMaxWall)+1 )
        {
            mvaddch(2+(room->xWall),2+(room->yWall),'*');
            
        }

        if ( room->monsterX > 0 && room->monsterY > 0 &&  (room->monsterX)+3 < (room->xMaxWall)+2 &&  (room->monsterY)+3 < (room->yMaxWall)+2 )
        {
            mvaddch((room->monsterX)+(room->xWall),(room->monsterY)+(room->yWall),'M');
            
        }
        
        if ( (room->monsterX)+3 > (room->xMaxWall)+1 ||  (room->monsterY)+3 > (room->yMaxWall)+1 )
        {
            mvaddch(2+(room->xWall),3+(room->yWall),'M');
            
        }

        if ( room->potionX > 0 && room->potionY > 0 &&  (room->potionX)+3 < (room->xMaxWall)+2 &&  (room->potionY)+3 < (room->yMaxWall)+2 )
        {
            mvaddch((room->potionX)+(room->xWall),(room->potionY)+(room->yWall),'!');
            
        }
        
        if ( (room->potionX)+3 > (room->xMaxWall)+1 ||  (room->potionY)+3 > (room->yMaxWall)+1 )
        {
            mvaddch(3+(room->xWall),2+(room->yWall),'!');
            
        }

        if ( room->weaponX > 0 && room->weaponY > 0 &&  (room->weaponX)+3 < (room->xMaxWall)+2 &&  (room->weaponY)+3 < (room->yMaxWall)+2 )
        {
            mvaddch((room->weaponX)+(room->xWall),(room->weaponY)+(room->yWall),'(');
            
        }
        
        if ( (room->weaponX)+3 > (room->xMaxWall)+1 ||  (room->weaponY)+3 > (room->yMaxWall)+1 )
        {
            mvaddch(3+(room->xWall),3+(room->yWall),'(');
            
        }

        if ( room->stairX > 0 && room->stairY > 0 &&  (room->stairX)+3 < (room->xMaxWall)+2 &&  (room->stairY)+3 < (room->yMaxWall)+2 )
        {
            mvaddch((room->stairX)+(room->xWall),(room->stairY)+(room->yWall),'%');
            
        }
        
        if ( (room->stairX)+3 > (room->xMaxWall)+1 ||  (room->stairY)+3 > (room->yMaxWall)+1 )
        {
            mvaddch(2+(room->xWall),1+(room->yWall),'%');
            
        }
        
        
    }
    
    if(j == 2 || j == 3 || j == 4 || j == 5 || j == 6)
    {

        /* Draw left to down side */
        for(x =room->xWall; x < (room->xMaxWall)+(room->xWall); x++)
        {  
            if (room->westDoor != 0 && x == room->westDoor+(room->xWall))
            {
                mvaddch(x,room->yWall, '+');
            }
			
            else
            {
                mvaddch(x,room->yWall, '|');
                if(room->westDoor > (room->xMaxWall)+(room->xWall))
                {
                    mvaddch(room->xWall+1,room->yWall, '+');    
                }
                
            }
			
            for(y = room->yWall; y < (room->yMaxWall)+(room->yWall)-2; y++)
            {
               mvaddch(x,y+1, '.'); 
            }
        }

        /* Draw right to down side */
        for(x =room->xWall; x < (room->xMaxWall)+(room->xWall); x++)
        {
            if (room->eastDoor != 0 && x == room->eastDoor+(room->xWall))
            {
                mvaddch(x,(room->yWall)+(room->yMaxWall)-1, '+');
            }
  
            else
            {			
                mvaddch(x,(room->yWall)+(room->yMaxWall)-1, '|');
            }
        }

        /* Draw top to right side */
        
        for(y =room->yWall; y < (room->yMaxWall)+(room->yWall)-2; y++)
        {                              
            if(room->northDoor != 0 && y == room->northDoor+(room->yWall)-1)
            {
                mvaddch(room->xWall,(y)+1, '+');
            }

            else
            {			
                mvaddch(room->xWall,(y)+1, '-');
            }
        }
 
        /* Draw bottom to right side */
        for(y =room->yWall; y < (room->yMaxWall)+(room->yWall)-2; y++)
        {  
            if(room->southDoor != 0 && y == room->southDoor+(room->yWall)-1)
            {
                mvaddch((room->xWall)+(room->xMaxWall)-1,(y)+1, '+');
            }

            else
            {			
                mvaddch((room->xWall)+(room->xMaxWall)-1,(y)+1, '-');
            }
        }
      
        if ( room->goldX > 0 && room->goldY > 0 &&  (room->goldX)+3 < (room->xMaxWall)+2 &&  (room->goldY)+3 < (room->yMaxWall)+2 )
        {
            mvaddch((room->goldX)+(room->xWall),(room->goldY)+(room->yWall),'*');
            
        }
        
        if ( (room->goldX)+3 > (room->xMaxWall)+1 ||  (room->goldY)+3 > (room->yMaxWall)+1 )
        {
            mvaddch(2+(room->xWall),2+(room->yWall),'*');
            
        }

        if ( room->monsterX > 0 && room->monsterY > 0 &&  (room->monsterX)+3 < (room->xMaxWall)+2 &&  (room->monsterY)+3 < (room->yMaxWall)+2 )
        {
            mvaddch((room->monsterX)+(room->xWall),(room->monsterY)+(room->yWall),'M');
            
        }
        
        if ( (room->monsterX)+3 > (room->xMaxWall)+1 ||  (room->monsterY)+3 > (room->yMaxWall)+1 )
        {
            mvaddch(2+(room->xWall),3+(room->yWall),'M');
            
        }

        if ( room->potionX > 0 && room->potionY > 0 &&  (room->potionX)+3 < (room->xMaxWall)+2 &&  (room->potionY)+3 < (room->yMaxWall)+2 )
        {
            mvaddch((room->potionX)+(room->xWall),(room->potionY)+(room->yWall),'!');
            
        }
        
        if ( (room->potionX)+3 > (room->xMaxWall)+1 ||  (room->potionY)+3 > (room->yMaxWall)+1 )
        {
            mvaddch(3+(room->xWall),2+(room->yWall),'!');
            
        }

        if ( room->weaponX > 0 && room->weaponY > 0 &&  (room->weaponX)+3 < (room->xMaxWall)+2 &&  (room->weaponY)+3 < (room->yMaxWall)+2 )
        {
            mvaddch((room->weaponX)+(room->xWall),(room->weaponY)+(room->yWall),'(');
            
        }
        
        if ( (room->weaponX)+3 > (room->xMaxWall)+1 ||  (room->weaponY)+3 > (room->yMaxWall)+1 )
        {
            mvaddch(3+(room->xWall),3+(room->yWall),'(');
            
        }

        if ( room->stairX > 0 && room->stairY > 0 &&  (room->stairX)+3 < (room->xMaxWall)+2 &&  (room->stairY)+3 < (room->yMaxWall)+2 )
        {
            mvaddch((room->stairX)+(room->xWall),(room->stairY)+(room->yWall),'%');
            
        }
        
        if ( (room->stairX)+3 > (room->xMaxWall)+1 ||  (room->stairY)+3 > (room->yMaxWall)+1 )
        {
            mvaddch(2+(room->xWall),1+(room->yWall),'%');
            
        } 

    }

    

}