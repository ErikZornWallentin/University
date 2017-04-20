****************************************************
Erik Zorn-Wallentin	 0864583
CIS*3110			 Assignment #3
Fri, March. 27 / 2015
****************************************************

* Report that was asked for in description is at bottom of this file! *

**********************
Compilation
**********************

To compile this program make sure you are in the correct directory in the terminal for where your file is.
Next type make in the command prompt.
If you are in the DiningPhilosopher (Part 1 of A3) directory you will get an executable called: dine
If you are in the MemoryManagement (Part 2 of A3) directory you will get an executable called: holes

***********************
Running the program(s)
***********************

Part 1 - Assignment 3
To run the program type "./dine 3 2", which would input 3 as the number of philosophers and 2 as the number of times they eat.
When that command is given it will start showing the Philosopher's eating and thinking.

Part 2 - Assignment 3
To run the program type "./holes p1.txt", which would use p1.txt as the input file.
A menu will pop up that says:
1) First Fit  -- Will perform the FIRST fit memory management on the p1.txt file
2) Best Fit   -- Will perform the BEST fit memory management on the p1.txt file
3) Next Fit   -- Will perform the NEXT fit memory management on the p1.txt file
4) Worst Fit  -- Will perform the WORST fit memory management on the p1.txt file
5) Exit Program  -- Will exit the program

If you choose a menu option it will perform its calculation and give the result and come back to the menu after.
You can continue on doing each menu option as many times as you like.
The menu does perform error-checking if the input is incorrect.

**************************
Bibliography / References
**************************

Part 1 - Dining Philosopher References!
https://www.cs.mtu.edu/~shene/NSF-3/e-Book/MUTEX/TM-example-philos-1.html -- help understanding dining philosopher problem
http://docs.oracle.com/cd/E19205-01/820-0619/gepji/index.html -- help understanding dining philosopher problem
http://rosettacode.org/wiki/Dining_philosophers -- help understanding dining philosopher problem
http://stackoverflow.com/questions/23529773/dining-philosopher-program-c -- help understanding dining philosopher problem
http://en.wikipedia.org/wiki/Dining_philosophers_problem -- help understanding dining philosopher problem

Part 2 -Memory Management References!
http://www.quora.com/In-memory-management-while-using-the-Best-Fit-First-Fit-and-Worst-Fit-Memory-Allocation-Methods-for-Fixed-Partitioning-is-only-one-process-allowed-inside-a-memory-hole
http://www.quora.com/What-are-the-first-fit-next-fit-and-best-fit-algorithms-for-memory-management -- help understanding memory management
https://www.youtube.com/watch?v=TnBQkzBsOe8 -- help understanding memory management
http://thumbsup2life.blogspot.ca/2011/02/best-fit-first-fit-and-worst-fit-memory.html -- help understanding memory management
http://courses.cs.vt.edu/~csonline/OS/Lessons/MemoryAllocation/index.html -- help understanding memory management


**************************
REPORT -- *IMPORTANT*
**************************

Part 1 -
- Follows theories from Dining Philosophers in the slides in class.
- It compiles with the -pthread flag
- I use fork() for the processes and I have a semaphore variable keeping track of everything ( wait, post)
- To simulate it properly, I use the sleep command before hungry / eating states to properly process everything.
- Error checking is done on input and everything

Part 2 -
- This program uses memory management theories like first/next/best/worst fit.
- Only 128 memory is being simulated, it uses an int array from 0-127 representing the 128 memory!
- I used a link list where the file is stored in a normal queue, this queue is then handed over to any "fit" the user chooses,
  they can choose one and it will be converted into the memory queue / memory array for the simulation.
- I also have a normal queue ( file), a duplicate of (normal queue) so I can forever use it, and the memory queue (simulation)
- Algorithm's used for first/next/best/worst fit follow the theory given from the memory-management.pptx and the slides given
  from class.
- The file used for simulation is the file in the assignment description.
- Print statements are used throughout if ever needed to see anything during the simulation, just open code and the uncomment any print statement

*****************
Known Limitations
*****************
