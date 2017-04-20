****************************************************
Erik Zorn-Wallentin  0864583
CIS*4500             Assignment #3 - Ackermann Function
Monday, Feb. 22 / 2016
****************************************************

**********************
Compilation
**********************

Make sure you have the Ada compiler installed on your computer. 

Download: https://sourceforge.net/projects/gnuada/

Or my preffered option is dowload Cygwin and also download the Devel package!
https://www.cygwin.com/


***********************
Running the program(s)
***********************

*IMPORTANT* This implementation uses recursive approach, this is done on purpose.
Please see my other programs if you want to see the recursive approach.

Ada Steps:
To compile this program make sure you are in the correct directory in the terminal for where your file is.

Follow these steps:
1. Compile: 
	gcc -c recursiveackermannfunction.adb
2. BIND AND LINK: 
	gnatmake recursiveackermannfunction.adb

3. RUN: 
	./recursiveackermannfunction

'Ackermann function recursive in Ada: Enter two numbers (Below 4 for a quick result)'
'Please enter number 1: ' --> enter first number (make sure its a number and below 4 for quick results and only once)
'Please enter number 2: ' --> enter second number (make sure its a number and below 4 for quick results and only once)
After it will calculate the two numbers (may take longer than 15 seconds if the numbers are too big using ackermann function).
Once it is done calculating it will print out the result and end the program.

	* good input for ackermann(m, n): 3 12 *

********************************************
TESTING -- INPUT FOR ACKERMANN(m, n): 3 12 --- RESULT: 32765
********************************************

RECURSIVE RESULTS --- not iterative.

-- Using my computer at home when timing the functions (i7 3.6GHz processor):

Ada Program:
	recursive in Ada: 5 seconds (uses system time)

Fortran Program:
	recursive in Fortran: 00 seconds -- OVERFLOW on my computer *Interesting*
	recursive in Fortran with (3,11): 1.123 seconds as my next closest test!

Julia Program:
	recursive in Julia: 4.078 seconds

Python Program:
	recursive in Python: 00 seconds -- OVERFLOW on my computer *Interesting*
	recursive in Python with (3,6): 0.065 seconds as my next one that doesn't overflow!
	Notice how it can only do up to (3,6) which is very important!

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
http://www.enggpedia.com/computer-engineering-encyclopedia/301-programming-languages/1886-c-language-dis-advantages -- c knowledge
http://stackoverflow.com/questions/17479782/julia-request-user-input-from-script - julia user input knowledge
http://julialang.org/ - julia knowledge
https://en.wikibooks.org/wiki/Introducing_Julia/Arrays_and_tuples - julia array knowledge
http://rosettacode.org/wiki/Array_Initialization - ada array

*****************
Known Limitations
*****************
