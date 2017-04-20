****************************************************
Erik Zorn-Wallentin	 0864583
CIS*3110			 Assignment #1
Wed, Jan. 28 / 2015
****************************************************

**********************
Compilation
**********************

To compile this program make sure you are in the correct directory in the terminal for where your file is.
Next type make in the command prompt. The executable is called *** shell ***

You can also type make clean to clean everything out first if something went wrong.

IMPORTANT *** If you are on mac change the makefile program from -lfl to -ll, if you are not on mac don't change anything ***

***********************
Running the program(s)
***********************

To run the program type "./shell or shell" for the specific program, you need to first compile it properly as directed above. 
A prompt will pop up ">>" and will loop forever for user input. 

It accepts a few commands such as:
	- exit (which exits the program)
	- args (Ex. args 100 200 300 will output argc = 3, args = 100, 200, 300) It counts the arguments and displays them all
	- add (Ex. add 100 200 0xa will output >> 100 + 200 + 0xa = 310) 
	It adds up the arguments that are in decimal or hexadecimal form

	*** The question 3. for a command "???" that is named and designed by myself is below ***
	- name (Ex. name Erik Zorn will output >> Your full name is: Erik Zorn)

It also has normal shell commands such as redirection:

	- Files for for input are given and called: input.txt
	- Files for output are given and called: output.txt

	Ex. sort < input.txt (will sort the data inside input.txt and display it as input redirection )
	Ex. ls -l > output.txt (will output the data from l -l and display it as output redirection )
	Ex. ls (will display everything in current directory)


**************************
Bibliography / References
**************************

Used the lex.c zip given from TA on the moodle.socs.uoguelph.ca in class.
http://en.wikipedia.org/wiki/Fork_%28system_call%29 -- understanding fork

Also took references from the 3 tutorials given in the class on moodle.socs.uoguelph.ca from TA:
https://www.cs.drexel.edu/~jjohnson/2012-13/fall/cs543/assignments/shlab/index.html
http://www.cs.cornell.edu/Courses/cs414/2004su/homework/shell/shell.html
http://people.cs.pitt.edu/~khalifa/cs1550/sum06/Assignments/Assign1/assignment1.htm

*****************
Known Limitations
*****************

When compiling make for first time, lex gives out some warnings, this library was given from TA and I don't know how to fix
the warnings inside the lex file, as it was a library we were told to use from TA. But my code itself has no warnings!

Was not able to implement piping, there is no command for "|" in assignment.

Was not able to get double quotes arguments to work in the args example.


