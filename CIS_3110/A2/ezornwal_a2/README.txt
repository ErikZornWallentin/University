****************************************************
Erik Zorn-Wallentin	 0864583
CIS*3110			 Assignment #2
Fri, Feb. 27 / 2015
****************************************************

**********************
Compilation
**********************

To compile this program make sure you are in the correct directory in the terminal for where your file is.
Next type make in the command prompt. The executable is called *** simcpu ***

You can also type make clean to clean everything out first if something went wrong.

**IMPORTANT**
Report.txt holds my CPU scheduling algorithm data

***********************
Running the program(s)
***********************

To run the program type "./simcpu < stdin" or "simcpu < stdin"
Ex1. simcpu < t2.txt    -- will take in a file called t2.txt from stdin using default mode FCFS
Ex2. simcpu -d < t2.txt -- same as above but in detail mode for FCFS
Ex3. simcpu -d -v < t2.txt -- same as above but in detail mode for FCFS and verbose mode
Ex3. simcpu -d -v -r 50 < t2.txt -- run in detail mode, verbose mode, and round robin mode with quantum 50

*Program will exit if not given a stdin and will exit if input is not given after -r for a number!*

From the command line it accepts:
"-d" for the first slot as detail mode,
"-v" in the second slot as verbose mode,
"-r INT" in the third slot as round robin mode with quantum
*NOTE "-r INT" can also be used in first, second slots!
*NOTE -- Needs to work in that order*

First it will parse your file after given input and print out some messages about the modes
and after it will give out your FCFS or RR scheduling info.


**************************
Bibliography / References
**************************
http://stackoverflow.com/questions/2564503/how-do-i-check-if-my-program-has-data-piped-into-it -- check stdin
http://www.cprogramto.com/c-program-for-first-come-first-serve-scheduling/ -- help understanding FCFS
http://www.programmingsimplified.com/c/source-code/c-program-bubble-sort -- help with sorting the priority queue
http://www.java2s.com/Tutorial/C/0260__Data-Structure/Aqueuebasedonthelinkedlist.htm -- help with understanding priority queue

*****************
Known Limitations
*****************

**IMPORTANT** Program will throw an error if text file has any characters or comments inside of it!!!
**IMPORTANT** Program will throw an error if text file has more processors than indicated from top of program!!!
**IMPORTANT** Cannot have more than 400 lines in the text file given!

Program will exit if not given a stdin and will exit if input is not given after -r for a number!
Here are some examples of error/correct command line arguments:
ERROR: simcpu will throw an error
CORRECT: simcpu < t2.txt

ERROR: simcpu -r < t2.txt
CORRECT: simcpu -r 50 < t2.txt

Program needs -d -v -r in that order, mixing those around will make program not work correctly!

***Important*** Round robin not implemented fully!

I did try to implement the priority queue and have a lot of the functionality in, just was not able
to 100% link it all together.





