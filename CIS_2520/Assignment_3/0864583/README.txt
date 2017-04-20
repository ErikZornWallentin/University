****************************************************
Erik Zorn-Wallentin	 0864583
CIS2520			     Assignment #3
Sunday, Nov. 2 / 2014
****************************************************


**********************
Compilation
**********************

To compile this program make sure you are in the correct directory in the terminal for where your file is.
Next type make in the command prompt.

***********************
Running the program(s)
***********************

To run the program type "./q1 or ./q2 for the specific program", you need to first compile it properly as directed above. 

Your output "q1" takes a command line argument which needs quotes inside of it to calculate an equation. ex. "200-(5+3)/5", without
quotes it won't work properly. Also equations using full brackets around everything causes problems, try to use less brackets.
A menu should pop out when running the program. Only option that works is the 5) update and 6) calculate option.
The option 5) update asks for a variable name and value and replaces it in the binary tree
The option 6) calculates the final answer and gives the result

Your output "q2" first takes in a file called "f.dat" indicated in assignment, that contains an array of 20x10. It will print out the original array in a sorted order
using down heap.


**************************
Bibliography / References
**************************
http://www.codebeach.com/2008/09/sorting-algorithms-in-c.html -- understanding downheap sorting
http://cognitivedissonance.ca/misc/parsing_demo/parsing.html -- understanding binary tree

*****************
Known Limitations
*****************
q1 - Need quotes around equation to get the program to run properly. Also has troubles with brackets in certain scenarios, try to use less brackets.
Most the options don't work properly, was not able to complete q1 and calculate option may cause problems using it several times. 

q2 - There is a good amount of error checking done on the file as far as entering the filename at the start, it doesn't check for incorrect input (not integers). Also if there are multiple sums in the array that are the same value/equal the program will not work properly. 
If everything is given as intended as 20x10 array of numbers the program will work as intended.
Program needs a file called "f.dat" as indicated in the assignment for it to work properly.



