/*************************A3.c****************************
Student Name: Erik Zorn - Wallentin  Student Number: 0864583
Date: Fri, March.14 / 2014              Course Name: CIS2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "functions.h"

/* Define the movement keys */
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'



int main(int argc, char* argv[])
{

    int ch;
    int yPos = 12;
    int xPos = 12; 

    char string2[12][151];
    char buffer2[1000];
    char checkX[2] = "X";
    char check[2] = " "; 
    int m = 0;
    int i = 0;
    int j = 1;
    char * token;
    chtype hero = '@';
    int gold = 0;
    int potion = 0;
    int weapon = 0;
    int holder = 0;
    int holderRoom = 0;
    int highestNum = 4;
    int generate = 0;

	
    /* Each room represents the input text file line ex. room.txt line 1 = room1*/
    struct Room * room1;       
    struct Room * room2;
    struct Room * room3;
    struct Room * room4;
    struct Room * room5;
    struct Room * room6;
    
 
    FILE * file = NULL; 
    file = readFile(argv[1],argc);
    
    srand (time(NULL));

    /* Create memory for each room to hold the data from file */
    room1 = (struct Room*)malloc(sizeof(struct Room)*152);
    room2 = (struct Room*)malloc(sizeof(struct Room)*152);
    room3 = (struct Room*)malloc(sizeof(struct Room)*152);
    room4 = (struct Room*)malloc(sizeof(struct Room)*152);
    room5 = (struct Room*)malloc(sizeof(struct Room)*152);
    room6 = (struct Room*)malloc(sizeof(struct Room)*152);

    if (file != NULL)
    {
	/* Open file and put each line into a string array */
        file = fopen("assets/room.txt", "r");
        while(fgets(buffer2,1000,file))					
    	{
            strcpy(string2[m],buffer2);            
            m++;
            i++;
    	}
        printf("\n"); 
        
        /* Token each piece of data and the result goes into the proper structure */
        for (m = 0; m < i; m++)
        {
            token = strtok(string2[m], checkX);
            holderRoom = atoi(&token[0]);
            if( m == 0)
            {
                if (holderRoom <= 25)
                {
                    room1->xMaxWall = atoi(&token[0]);
                }
                else
                {
                    printf("Room too large! Needs to be 25 or smaller. Resizing room to 10!\n");
                    room1->xMaxWall = 10;
                }
            }
       
            else if( m == 1)
            {
                if (holderRoom <= 25)
                {
                    room2->xMaxWall = atoi(&token[0]);
                }
                else
                {
                    printf("Room too large! Needs to be 25 or smaller. Resizing room to 10!\n");
                    room2->xMaxWall = 10;
                }
            }
			
	    else if( m == 2)
            {
                if (holderRoom <= 25)
                {
                    room3->xMaxWall = atoi(&token[0]);
                }
                else
                {
                    printf("Room too large! Needs to be 25 or smaller. Resizing room to 10!\n");
                    room3->xMaxWall = 10;
                }
            }
			
	    else if( m == 3)
            {
                if (holderRoom <= 25)
                {
                    room4->xMaxWall = atoi(&token[0]);
                }
                else
                {
                    printf("Room too large! Needs to be 25 or smaller. Resizing room to 10!\n");
                    room4->xMaxWall = 10;
                }
            }
			
	    else if( m == 4)
            {
                if (holderRoom <= 25)
                {
                    room5->xMaxWall = atoi(&token[0]);
                }
                else
                {
                    printf("Room too large! Needs to be 25 or smaller. Resizing room to 10!\n");
                    room5->xMaxWall = 10;
                }
            }
			
	    else if( m == 5)
            {
                if (holderRoom <= 25)
                {
                    room6->xMaxWall = atoi(&token[0]);
                }
                else
                {
                    printf("Room too large! Needs to be 25 or smaller. Resizing room to 10!\n");
                    room6->xMaxWall = 10;
                }
            }

            while( token != NULL ) 
            {

                /* Give each of the rooms some info  to fix bugs*/
                if(m == 0)
		{
                    parseText(token, room1);
                    room1->roomNumber = 1;
                    room1->xWall = 3;
                    room1->yWall = 3;
                    room1->monsterHp = 5;
                    room1->heroHp = 10;
                    
		}

                else if(m == 1)
		{
                    parseText(token, room2);
                    room2->roomNumber = 2;
                    room2->xWall = 3;
                    room2->yWall = 30;
                    room2->monsterHp = 5;
		}
 
                else if(m == 2)
		{
                    parseText(token, room3);
                    room3->roomNumber = 3;
                    room3->xWall = 3;
                    room3->yWall = 57;
                    room3->monsterHp = 5;
		}

                else if(m == 3)
		{
                    parseText(token, room4);
                    room4->roomNumber = 4;
                    room4->xWall = 30;
                    room4->yWall = 3;
                    room4->monsterHp = 5; 
		}

                else if(m == 4)
		{
                    parseText(token, room5);
                    room5->roomNumber = 5;
                    room5->xWall = 30;
                    room5->yWall = 30;
                    room5->monsterHp = 5;
		}

                else if(m == 5)
		{
                    parseText(token, room6);
                    room6->roomNumber = 6;
                    room6->xWall = 30;
                    room6->yWall = 57;
                    room6->monsterHp = 5;
		}				
                /*printf("%s\n", token);*/
                token = strtok(NULL, check);
            }
        }   
    }
  
    /* Start curses mode */

    initscr();					   
    start_color();   					/* Start colour mode*/                             
    cbreak();
    keypad(stdscr, TRUE);				/* Get the keys we want */		   
    noecho();						/* This does not leave a trail of characters*/							
  
    /* Print each individual room */
    printRoom(room1, j);
    j++;
    printRoom(room2, j);	
    j++;
    printRoom(room3, j);
    j++;
    printRoom(room4, j);
    j++;
    printRoom(room5, j);	
    j++;
    printRoom(room6, j);
   	
    refresh();	
    
    if( holder == 0)
    {
        move(room1->heroX+3,room1->heroY+3);
        getyx(stdscr, yPos, xPos);
        holder = 1;
    }
    
    while((ch = getch()) != 'q')
    {
        switch(ch)
        {
            case UP: 
                if (mvinch(yPos-1,xPos) == '|' || mvinch(yPos-1,xPos) == '-')
                {	
                    move(yPos,xPos);
                }
		
                else if (mvinch(yPos-1,xPos) == 'M')
                {	
                    move(yPos,xPos);
                    generate =(rand()%highestNum);
                    if (generate == 1)
                    {
                        mvprintw(2,0,"You missed the monster.");
                    }
                    if (generate == 2)
                    {
                        mvprintw(2,0,"You hit the monster.       ");
                        room1->monsterHp = room1->monsterHp -1;
                    }
                    if (generate == 3)
                    {
                        
                        mvprintw(2,0,"Monster hit you!.        ");
                        room1->heroHp = room1->heroHp-1;
                        mvprintw(1,0,"HP: %d!",room1->heroHp); 
                    }
                }
 		
                else if (mvinch(yPos-1,xPos) == '+')
                {
                    if(xPos == room1->northDoor+room1->yWall)
                    {
                        
                    	mvaddch(yPos+1,xPos,'.');
                        mvaddch(yPos,(room1->yWall)+(room1->northDoor),'.');
                        move(room2->xWall+1,room2->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }
                     
                     else if(xPos == room2->northDoor+room2->yWall)
                     {
                    	mvaddch(yPos+1,xPos,'.');
                        mvaddch(yPos,(room2->yWall)+(room2->northDoor),'.');
                        move(room3->xWall+1,room3->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     } 

                     else if(xPos == room3->northDoor+room3->yWall)
                     {
                    	mvaddch(yPos+1,xPos,'.');
                        mvaddch(yPos,(room3->yWall)+(room3->northDoor),'.');
                        move(room4->xWall+1,room4->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }

                     else if(xPos == room4->northDoor+room4->yWall)
                     {
                    	mvaddch(yPos+1,xPos,'.');
                        mvaddch(yPos,(room4->yWall)+(room4->northDoor),'.');
                        move(room5->xWall+1,room5->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }

                     else if(xPos == room5->northDoor+room5->yWall)
                     {
                    	mvaddch(yPos+1,xPos,'.');
                        mvaddch(yPos,(room5->yWall)+(room5->northDoor),'.');
                        move(room6->xWall+1,room6->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }  
                }

                else if (mvinch(yPos-1,xPos) == '%')
                {	        
                    
                    mvprintw(0,25,"You beat the floor, congrats!!!\n");
                    mvprintw(1,0,"INVENTORY: You picked up %d gold(s), %d potion(s), %d weapon(s)!",gold,potion,weapon);
                    mvprintw(2,25,"Now exiting the game!!!\n");
                    mvaddch(yPos+1,xPos,'.');
                    yPos--;
                    getyx(stdscr, yPos, xPos);
                        
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    getch();
                    endwin();
                    /* Close file and free memory!! */
                    fclose(file);
                    free(room1);
                    free(room2);
                    free(room3);
                    free(room4);
                    free(room5);
                    free(room6);
                    return(0); 
                     
                }

                else if (mvinch(yPos-1,xPos) == '*')
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    yPos--;
                    move(yPos,xPos); 
                    gold = gold + 1;
                    
                }
       
                else if (mvinch(yPos-1,xPos) == '!')
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    yPos--;
                    move(yPos,xPos); 
                    potion = potion + 1;
                    
                }

                else if (mvinch(yPos-1,xPos) == '(')
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    yPos--;
                    move(yPos,xPos); 
                    weapon = weapon + 1;
                    
                }

                else
                {
                    
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    yPos--;
                    move(yPos,xPos); 
                }
                break;

            case DOWN:    
                if (mvinch(yPos+1,xPos) == '|' || mvinch(yPos+1,xPos) == '-')
                {	
                    move(yPos,xPos);
                }

                else if (mvinch(yPos+1,xPos) == 'M')
                {	
                    move(yPos,xPos);
                    generate =(rand()%highestNum);
                    if (generate == 1)
                    {
                        mvprintw(2,0,"You missed the monster.");
                    }
                    if (generate == 2)
                    {
                        mvprintw(2,0,"You hit the monster.       ");
                        room1->monsterHp = room1->monsterHp -1;
                    }
                    if (generate == 3)
                    {
                        
                        mvprintw(2,0,"Monster hit you!.        ");
                        room1->heroHp = room1->heroHp-1;
                        mvprintw(1,0,"HP: %d!",room1->heroHp); 
                    }
                }

                else if (mvinch(yPos+1,xPos) == '+')
                {
                    if(xPos == room1->southDoor+room1->yWall)
                    {
                        
                    	mvaddch(yPos-1,xPos,'.');
                        mvaddch(yPos,(room1->yWall)+(room1->southDoor),'.');
                        move(room2->xWall+1,room2->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }
                     
                     else if(xPos == room2->southDoor+room2->yWall)
                     {
                    	mvaddch(yPos-1,xPos,'.');
                        mvaddch(yPos,(room2->yWall)+(room2->southDoor),'.');
                        move(room3->xWall+1,room3->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     } 

                     else if(xPos == room3->southDoor+room3->yWall)
                     {
                    	mvaddch(yPos-1,xPos,'.');
                        mvaddch(yPos,(room3->yWall)+(room3->southDoor),'.');
                        move(room4->xWall+1,room4->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }

                     else if(xPos == room4->southDoor+room4->yWall)
                     {
                    	mvaddch(yPos-1,xPos,'.');
                        mvaddch(yPos,(room4->yWall)+(room4->southDoor),'.');
                        move(room5->xWall+1,room5->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }

                     else if(xPos == room5->southDoor+room5->yWall)
                     {
                    	mvaddch(yPos-1,xPos,'.');
                        mvaddch(yPos,(room5->yWall)+(room5->southDoor),'.');
                        move(room6->xWall+1,room6->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }  
                }
                 
                else if (mvinch(yPos+1,xPos) == '%')
                {	        
                    
                    mvprintw(0,25,"You beat the floor, congrats!!!\n");
                    mvprintw(1,0,"INVENTORY: You picked up %d gold(s), %d potion(s), %d weapon(s)!",gold,potion,weapon);
                    mvprintw(2,25,"Now exiting the game!!!\n");
                    mvaddch(yPos-1,xPos,'.');
                    yPos++;
                    getyx(stdscr, yPos, xPos);
                        
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    getch();
                    endwin();
                    /* Close file and free memory!! */
                    fclose(file);
                    free(room1);
                    free(room2);
                    free(room3);
                    free(room4);
                    free(room5);
                    free(room6);
                    return(0); 
                     
                }
                
                else if (mvinch(yPos+1,xPos) == '*')
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    yPos++;
                    move(yPos,xPos); 
                    gold = gold + 1;
                    
                }
       
                else if (mvinch(yPos+1,xPos) == '!')
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    yPos++;
                    move(yPos,xPos); 
                    potion = potion + 1;
                    
                }

                else if (mvinch(yPos+1,xPos) == '(')
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    yPos++;
                    move(yPos,xPos); 
                    weapon = weapon + 1;
                    
                }
                else
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    yPos++;
                    move(yPos,xPos);               
                }
                break;

            case LEFT:     
                if (mvinch(yPos,xPos-1) == '|' || mvinch(yPos,xPos-1) == '-')
                {	
                    move(yPos,xPos); 
                }

                else if (mvinch(yPos,xPos-1) == 'M')
                {	
                    move(yPos,xPos);
                    generate =(rand()%highestNum);
                    if (generate == 1)
                    {
                        mvprintw(2,0,"You missed the monster.");
                    }
                    if (generate == 2)
                    {
                        mvprintw(2,0,"You hit the monster.       ");
                        room1->monsterHp = room1->monsterHp -1;
                    }
                    if (generate == 3)
                    {
                        
                        mvprintw(2,0,"Monster hit you!.        ");
                        room1->heroHp = room1->heroHp-1;
                        mvprintw(1,0,"HP: %d!",room1->heroHp); 
                    }
                }

                else if (mvinch(yPos,xPos-1) == '+')
                {
                    if(yPos == room1->westDoor+room1->xWall)
                    {
                        
                    	mvaddch(yPos,xPos+1,'.');
                        mvaddch(yPos,(room1->yWall)+1,'.');
                        move(room2->xWall+1,room2->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }
                     
                     else if(yPos == room2->westDoor+room2->xWall)
                     {
                    	mvaddch(yPos,xPos+1,'.');
                        mvaddch(yPos,(room2->yWall)+1,'.');
                        move(room3->xWall+1,room3->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     } 

                     else if(yPos == room3->westDoor+room3->xWall)
                     {
                    	mvaddch(yPos,xPos+1,'.');
                        mvaddch(yPos,(room3->yWall)+1,'.');
                        move(room4->xWall+1,room4->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }

                     else if(yPos == room4->westDoor+room4->xWall)
                     {
                    	mvaddch(yPos,xPos+1,'.');
                        mvaddch(yPos,(room4->yWall)+1,'.');
                        move(room5->xWall+1,room5->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }

                     else if(yPos == room5->westDoor+room5->xWall)
                     {
                    	mvaddch(yPos,xPos+1,'.');
                        mvaddch(yPos,(room5->yWall)+1,'.');
                        move(room6->xWall+1,room6->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }  
                }
                
                else if (mvinch(yPos,xPos-1) == '%')
                {	        
                    
                    mvprintw(0,25,"You beat the floor, congrats!!!\n");
                    mvprintw(1,0,"INVENTORY: You picked up %d gold(s), %d potion(s), %d weapon(s)!",gold,potion,weapon);
                    mvprintw(2,25,"Now exiting the game!!!\n");
                    mvaddch(yPos,xPos+1,'.');
                    xPos--;
                    getyx(stdscr, yPos, xPos);
                        
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    getch();
                    endwin();
                    /* Close file and free memory!! */
                    fclose(file);
                    free(room1);
                    free(room2);
                    free(room3);
                    free(room4);
                    free(room5);
                    free(room6);
                    return(0); 
                     
                }
                
                else if (mvinch(yPos,xPos-1) == '*')
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    xPos--;
                    move(yPos,xPos); 
                    gold = gold + 1;
                    
                }
       
                else if (mvinch(yPos,xPos-1) == '!')
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    xPos--;
                    move(yPos,xPos); 
                    potion = potion + 1;
                    
                }

                else if (mvinch(yPos,xPos-1) == '(')
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    xPos--;
                    move(yPos,xPos); 
                    weapon = weapon + 1;
                    
                }
                else
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    xPos--;
                    move(yPos,xPos);       
                }
                break;

            case RIGHT:     
                if (mvinch(yPos,xPos+1) == '|' || mvinch(yPos,xPos+1) == '-')
                {	
                    move(yPos,xPos);
                }

                else if (mvinch(yPos,xPos+1) == 'M')
                {	
                    move(yPos,xPos);
                    generate =(rand()%highestNum);
                    if (generate == 1)
                    {
                        mvprintw(2,0,"You missed the monster.");
                    }
                    if (generate == 2)
                    {
                        mvprintw(2,0,"You hit the monster.       ");
                        room1->monsterHp = room1->monsterHp -1;
                    }
                    if (generate == 3)
                    {
                        
                        mvprintw(2,0,"Monster hit you!.        ");
                        room1->heroHp = room1->heroHp-1;
                        mvprintw(1,0,"HP: %d!",room1->heroHp); 
                    }
                }
                else if (mvinch(yPos,xPos+1) == '+')
                {
                    
                    if(yPos == room1->eastDoor+room1->xWall)
                    {
                        
                    	mvaddch(yPos,xPos-1,'.');
                        mvaddch(yPos,(room1->yWall)+(room1->yMaxWall)-2,'.');
                        move(room2->xWall+1,room2->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }
                     
                     else if(yPos == room2->eastDoor+room2->xWall)
                     {
                    	mvaddch(yPos,xPos-1,'.');
                        mvaddch(yPos,(room2->yWall)+(room2->yMaxWall)-2,'.');
                        move(room3->xWall+1,room3->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     } 

                     else if(yPos == room3->eastDoor+room3->xWall)
                     {
                    	mvaddch(yPos,xPos-1,'.');
                        mvaddch(yPos,(room3->yWall)+(room3->yMaxWall)-2,'.');
                        move(room4->xWall+1,room4->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }

                     else if(yPos == room4->eastDoor+room4->xWall)
                     {
                    	mvaddch(yPos,xPos-1,'.');
                        mvaddch(yPos,(room4->yWall)+(room4->yMaxWall)-2,'.');
                        move(room5->xWall+1,room5->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }

                     else if(yPos == room5->eastDoor+room5->xWall)
                     {
                    	mvaddch(yPos,xPos-1,'.');
                        mvaddch(yPos,(room5->yWall)+(room5->yMaxWall)-2,'.');
                        move(room6->xWall+1,room6->yWall+1);
                        getyx(stdscr, yPos, xPos);
                        
                        addch(hero);
                        mvaddch(yPos,xPos,'.');
                     }                   
                }
               
                else if (mvinch(yPos,xPos+1) == '%')
                {	        
                    
                    mvprintw(0,25,"You beat the floor, congrats!!!\n");
                    mvprintw(1,0,"INVENTORY: You picked up %d gold(s), %d potion(s), %d weapon(s)!",gold,potion,weapon);
                    mvprintw(2,25,"Now exiting the game!!!\n");
                    mvaddch(yPos,xPos-1,'.');
                    xPos++;
                    getyx(stdscr, yPos, xPos);
                        
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    getch();
                    endwin();
                    /* Close file and free memory!! */
                    fclose(file);
                    free(room1);
                    free(room2);
                    free(room3);
                    free(room4);
                    free(room5);
                    free(room6);
                    return(0); 
                     
                }                

                else if (mvinch(yPos,xPos+1) == '*')
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    xPos++;
                    move(yPos,xPos); 
                    gold = gold + 1;
                    
                }
       
                else if (mvinch(yPos,xPos+1) == '!')
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    xPos++;
                    move(yPos,xPos); 
                    potion = potion + 1;
                    
                }

                else if (mvinch(yPos,xPos+1) == '(')
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    xPos++;
                    move(yPos,xPos); 
                    weapon = weapon + 1;
                    
                }
                else
                {
                    addch(hero);
                    mvaddch(yPos,xPos,'.');
                    xPos++;
                    move(yPos,xPos); 
                    
                }
                break;

            default:
                mvprintw(0,0,"Error: Please try using w,a,s,d keys!");
                move(yPos,xPos);
                refresh(); 
        }
    }
 
    refresh(); 	
    mvprintw(1,0,"Exiting Now, have a good day!\n");
    mvprintw(2,0,"INVENTORY: You picked up %d gold(s), %d potion(s), %d weapon(s)!",gold,potion,weapon);
    getch();
    endwin();
    

    /* Close file and free memory!! */
    fclose(file);
    free(room1);
    free(room2);
    free(room3);
    free(room4);
    free(room5);
    free(room6);
    return(0);
}
