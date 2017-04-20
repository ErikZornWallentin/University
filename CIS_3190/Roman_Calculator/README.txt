****************************************************
Erik Zorn-Wallentin	 0864583
CIS*3190(DE)         A3 - COBOL
Monday, March. 16 / 2015
****************************************************

**********************
Compilation
**********************
To run the program, make sure you are in the correct directory.
To compile the program type in the command-prompt:
cobc -free -x -o a3 a3.cbl

Tt will generate an executable called: a3


***********************
Running the program(s)
***********************
To run the program, make sure you are in the correct directory and type:
./a3

This will start the roman numeral calculator that will automatically use "input.txt" file.
It reads each line one by one and gives back a result.
It will convert roman numerals into normal numerical format.
EXAMPLE: "input.txt" -> XIV

When running the program it will say:

********** ROMAN CALCULATOR **********
Your Roman Numerals: CXIV
The converted result is: 0114

The input file already gives about 17 different test cases to start off with!
You will see lots of conversions when running the program!

**************************
Bibliography / References 
**************************

http://www.csis.ul.ie/cobol/examples/#SimplePrograms -- help with COBOL programs
http://stackoverflow.com/questions/16442609/how-to-access-single-character-from-a-string-in-cobol
The first thing to understand is that array indices are zero based in C and 1 based in COBOL.
http://stackoverflow.com/questions/24777344/compute-length-string-of-variable-with-cobol -- get index of string
http://stackoverflow.com/questions/16442609/how-to-access-single-character-from-a-string-in-cobol
http://homeworktips.about.com/od/mathhomework/a/romannumerals.htm -- understanding roman numerals

*****************
Known Limitations
*****************

It does not prompt the user for the file name, it automatically uses "input.txt" as the default file name.

When compiling it will give warnings: dereferencing type-punned pointer will break strict-aliasing rules
and the prof told us not to worry about these warnings so they were left in there.
