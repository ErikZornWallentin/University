****************************************************
Erik Zorn-Wallentin  0864583
CIS*3190(DE)         Assignment #4 - Ackermann Function
Friday, March. 27 / 2015
****************************************************
  
** IMPORTANT **
** Switched Cobol for Python (recursive) **

**********************
Compilation
**********************

C steps:
To compile this program make sure you are in the correct directory in the terminal for where your file is.

Follow these steps:
1. Compile:
	gcc recursiveInC.c -o recursiveInC
	gcc iterativeInC.c -o iterativeInC
2. RUN:
	./recursiveInC
	./iterativeInC

Ada Steps:
To compile this program make sure you are in the correct directory in the terminal for where your file is.

Follow these steps:
1. Compile: 
	gcc -c recursiveinada.adb
	gcc -c iterativeinada.adb
2. BIND AND LINK: 
	gnatmake recursiveinada.adb
	gnatmake iterativeinada.adb

3. RUN: 
	./recursiveinada
	./iterativeinada

Fortran Steps:
To compile this program make sure you are in the correct directory in the terminal for where your file is.

Follow these steps:
1. Compile: 
	gfortran recursiveInFrotran.f90 -o recursiveFortran
	gfortran iterativeInFrotran.f90 -o iterativeFortran
2. RUN: 
	./recursiveFortran
	./iterativeFortran

Python:
To run the program, make sure you are in the correct directory.

Follow these steps:
1. Compile and RUN:
	python recursiveInPython.py

***********************
Running the program(s)
***********************
--See above steps on how to run each program

All programs when run will ask for the same thing, such as:

'Ackermann function recursive in Fortran: Enter two numbers (Below 4 for a quick result)'
'Please enter number 1: ' --> enter first number (make sure its a number and below 10 for quick results and only once)
'Please enter number 2: ' --> enter second number (make sure its a number and below 10 for quick results and only once)
After it will calculate the two numbers (may take longer than 15 seconds if the numbers are too big using ackermann function).
Once it is done calculating it will print out the result and end the program.

	* good input for ackermann(m, n): 3 12 *

********************************************
TESTING -- INPUT FOR ACKERMANN(m, n): 3 12
********************************************

-- Using the Linux (Sun Ray's - Thornbrough Building) computers at school I got these results when timing the functions:

C Programs:
	recursive in C: 6 seconds
	iterative in C: 12.7 seconds

Ada Programs:
	recursive in Ada: 10 seconds (uses system time)
	iterative in Ada: 21 seconds (uses system time)

Fortran Programs:
	recursive in Fortran: 14.69 seconds
	iterative in Fortran: 26.23 seconds

Python Program:
	recursive in Python: Segmentation fault (python can't calculate it properly) new input ackermann:(3,11) -- 154.3 seconds

**************************
Bibliography / References
**************************

http://rosettacode.org/wiki/Ackermann_function -- help understanding ackermann function
http://en.wikipedia.org/wiki/Ackermann_function -- help understanding ackermann function
http://en.literateprograms.org/Ackermann_function_%28C%29 -- help understanding ackermann function
http://www.codeproject.com/Articles/21194/Iterative-vs-Recursive-Approaches -- help understanding ackermann function
http://fortranwiki.org/fortran/show/recursion -- help understanding ackermann function
http://rosettacode.org/wiki/Time_a_function -- timing functions
http://rosettacode.org/wiki/Stack -- help understanding stacks
http://sandbox.mc.edu/~bennet/ada/examples/ -- ada help with stacks
http://groups.engin.umd.umich.edu/CIS/course.des/cis400/ -- help with legacy languages

http://www.quora.com/For-scientific-computing-what-are-the-advantages-and-disadvantages-of-using-C-as-compared-to-using-FORTRAN-90 -- fortran knowledge
http://www.adaic.org/advantages/features-benefits/ -- ada knowledge
http://www.quora.com/What-are-the-advantages-and-disadvantages-of-Python-over-Java-and-PHP-for-web-development -- python knowledge
http://www.enggpedia.com/computer-engineering-encyclopedia/301-programming-languages/1886-c-language-dis-advantages -- c knowledge

*****************
Known Limitations
*****************

-- Python and Ada can only handle so much and may need to lower input for it to work properly!
