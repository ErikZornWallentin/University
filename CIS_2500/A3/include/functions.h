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

/* Here are the function declarations for the assignment */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <ncurses.h>

/* This is a struct that contains every type of info that
is needed for each room, and there are 6 rooms total for 
the first floor */
struct Room
{
    int xWall;
    int yWall;
    int xMaxWall;
    int yMaxWall;

    int roomNumber;
    int eastDoor;
    int westDoor;
    int northDoor;
    int southDoor;

    int heroX;
    int heroY;
    char heroSymbol;
    int heroHp;
	
    int goldX;
    int goldY;
    char goldSymbol;
	
    int monsterX;
    int monsterY;
    char monsterSymbol;
    int monsterHp;
	
    int potionX;
    int potionY;
    char potionSymbol;
	
    int stairX;
    int stairY;
    int stairSymbol;
	
    int weaponX;
    int weaponY;
    int weaponSymbol;
	
};


/*----
Purpose: The purpose of this function is to get the input assets/room.txt file and start generating the game,
         it has error checking, and will always print out the file contents before generating
Parameters: char * filename(the 2nd input of command line) and int n (amount of arguments on command line)
Return: file * (file variable)
----*/

FILE *readFile(char * filename, int n);

/*----
Purpose: The purpose of this function is to get 'tokens' from a file and parse the text into the struct
         for every bit of info needed for the room.
Parameters: char * token(every bit of info on file), struct Room * room (pass in a room number)
Return: nothing
----*/

void parseText(char * token, struct Room * room);

/*----
Purpose: The purpose of this function is to print every piece of room info 
Parameters: int j(room number slot), struct Room * room (pass in a room number)
Return: nothing
----*/

void printRoom(struct Room * room, int j);
