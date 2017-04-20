/*************************carbon.c****************************
Student Name: Erik Zorn - Wallentin  Student Number: 0864583
Date: Fri, Sept.26 / 2014              Course Name: CIS2520
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

void carbonFunc();

/*----
Purpose: The purpose of this function is to calculate unique strings in the word carbon.
Parameters: None
Return: void (nothing)
----*/
void carbonFunc()
{
    char word[6] = "CARBON"; //using the letters 'c','a','r','b','o','n' from a1 question #1

    //For loop variables for each character in the word for "CARBON"
    int c = 0;
    int a = 0;
    int r = 0;
    int b = 0;
    int o = 0;
    int n = 0;
    
    //Counter variable for unique strings
    int uniqueCounter = 0;

    for (c = 0; c < 6; c++) //Start of the first character loop using "c" check
    {
		
	    for (a = 0; a < 6; a++) //Start of the second character loop using "a" check
        {
            if (a == c)
            {
                continue;
            }

            for (r = 0; r < 6; r++) //Start of the third character loop using "r" check
            {
                if (r == c || r == a)
                {
                    continue;
                }
                for (b = 0; b < 6; b++) //Start of the fourth character loop using "b" check
                {
                    if (b == c || b == a || b == r)
                    {
                        continue;
                    }

                    for(o = 0; o < 6; o++) //Start of the fifth character loop using "o" check
                    {
                        if (o == c || o == a || o == r || o == b)
                        {
                            continue;
                        }
						
                        for (n = 0; n < 6; n++) //Start of the sixth character loop using "n" check
                        {	
                            if (n == c || n == a || n == r || n == b || n == o)
                            {
                                continue;
                            }
                            
                            //Counter for the the unique string totalling 720 at the end
                            uniqueCounter++;
                            
                            //Prints out the 6 character string with the number of the line
                            printf("#%d: %c%c%c%c%c%c\n", uniqueCounter, word[c], word[a], word[r], word[b], word[o], word[n]);
                        }						
                    }
                }
            }
        }
    }
}