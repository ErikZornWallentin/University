****************************************************
Erik Zorn-Wallentin	 0864583
CIS2520			     Assignment #2
Monday, Oct. 13 / 2014
****************************************************


**********************
Compilation
**********************

To compile this program make sure you are in the correct directory in the terminal for where your file is.
Next type make in the command prompt.

***********************
Running the program(s)
***********************

To run the program type "./q1 or ./q2 for the specific program", you need to first compile it properly as directed above. Your output "q1" should be a menu system
that firsts takes input of a file(disk.txt as a command line argument) of cars(does some preprocessing), after it gives you options to choose from. 1) adds a new car to the available for rent linked list. 2) adds a returned car to the available for rent linked list. 3) adds a returned car to the repair list. 4) transfer a car from repair list to the
available for rent list. 5) rents the first available car from the available for rent linked list. 6) prints all the car. 7) quits program and saves to the file.

Input to file "disk.txt" must follow this pattern and example is shown already in the program root directory:
1st variable: number 1-3 to show which linked list to put it in 1(available for rent), 2(rented), 3(in repair) linked lists.
2nd variable: license plate number (ex. BNMS 607)
3rd variable: mileage number (ex. 102)
4th variable: car state (ex. Returned Car or New Car)
5th variable: return date(ex. YYMMDD and do it in with numbers)
Every variable is separated by a "," and no spaces should be used in the file. The file has very little error checking only checks if the file exists or not!

Your output "q2" first takes in a file that asks for a postfix expression. It calculates the postfix expression from the command line and prints the postfix expression
and the evaluated result.



**************************
Bibliography / References
**************************
http://www.c-program-example.com/2011/10/c-program-for-evaluation-of-postfix.html — understanding postfix
CIS 1500 Error checking function from Judi for students to use last year
http://www.cprogramming.com/snippets/source-code/singly-linked-list-insert-remove-add-count — understanding linked list
http://c.happycodings.com/sorting-searching/code10.html — understand sorting
http://stackoverflow.com/questions/20636265/linked-list-moving-a-node-from-one-list-to-another — understanding moving nodes
https://www.cs.bu.edu/teaching/c/linked-list/delete/ -- understanding deletion

*****************
Known Limitations
*****************

VERY IMPORTANT PLEASE READ - File only takes in 40 lines, with 80 characters maximum
in this lines anything more will cause segmentation fault.
Please input less than 40 lines for the file for it to work properly when reading in,
or it will crash.
Error checking was done for a lot of stuff, but was not done for writing in the file or
when its asking for input inside the menu function.



