****************************************************
Erik Zorn-Wallentin  0864583
CIS*4500             Assignment #3 - Ackermann Function
Thursday, Feb. 18 / 2016
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

*IMPORTANT* This implementation uses iterative approach, this is done on purpose.
Please see my other programs if you want to see the recursive approach.

Ada Steps:
To compile this program make sure you are in the correct directory in the terminal for where your file is.

Follow these steps:
1. Compile: 
	gcc -c iterativeackermanfunction.adb
2. BIND AND LINK: 
	gnatmake iterativeackermanfunction.adb

3. RUN: 
	./iterativeackermanfunction

'Ackermann function iterative in Ada: Enter two numbers (Below 4 for a quick result)'
'Please enter number 1: ' --> enter first number (make sure its a number and below 4 for quick results and only once)
'Please enter number 2: ' --> enter second number (make sure its a number and below 4 for quick results and only once)
After it will calculate the two numbers (may take longer than 15 seconds if the numbers are too big using ackermann function).
Once it is done calculating it will print out the result and end the program.

	* good input for ackermann(m, n): 3 12 *

********************************************
TESTING -- INPUT FOR ACKERMANN(m, n): 3 12 --- RESULT: 32765
********************************************

ITERATIVE RESULTS --- not recursion.

-- Using my computer at home when timing the functions (i7 3.6GHz processor):

Ada Program:
	iterative in Ada: 8 seconds (uses system time)

Fortran Program:
	iterative in Fortran: 7.4 seconds

Julia Program:
	iterative in Julia: 24 seconds

Python Program:
	iterative in Python: 401.6 seconds!! *Hope you have a fast computer to test it on yours when marking! *

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
