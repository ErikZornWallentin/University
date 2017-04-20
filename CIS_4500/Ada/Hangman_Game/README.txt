****************************************************
Erik Zorn-Wallentin  0864583
CIS*3190(DE)         Assignment #2 - Ada
Thur, Feb. 19 / 2015
****************************************************

**********************
Compilation
**********************

To compile this program make sure you are in the correct directory in the terminal for where your file is.
Follow these steps:
1. Compile: gcc -c hangman.adb
2. BIND AND LINK: gnatmake hangman.adb
3. RUN: hangman

***********************
Running the program(s)
***********************

To run the program type "./hangman or hangman" for the specific program, you need to first compile it properly as directed above. 
A prompt will pop up saying the program has started and you can exit at any time by typing '.' or 'N'.

When the program has started it will start the Hangman game, it will give a secret word that is hidden with '-' (ex. BYE >>> ---)
You have 10 chances to guess the word, please only input 1 character at a time for the program to work correctly and don't use the a word you already guessed!
If you get a correct guess the letter will show up as not hidden, but if you get an incorrect guess you will see the hangman being drawn on the screen till you lose!

Good luck!

**************************
Bibliography / References
**************************
http://www.pegasoft.ca/resources/boblap/12.html -- unbounded strings
http://www.adahome.com/FAQ/programming.html#visible_ops -- Ada FAQ
http://www.infres.enst.fr/~pautet/Ada95/a95list.htm -- Ada 95 Tutorial
http://www.ada95.ch/doc/tut1/index.html - Ada lecture notes
http://code.wikia.com/wiki/Random_number -- random number generator
http://en.wikibooks.org/wiki/Ada_Programming/Control#if-else -- help with if/else/and/or


*****************
Known Limitations
*****************

- If you guessed a letter, and guess it again it will cause the program to not work properly.
ex (word is ---   ---> you guessed 'b'   -->   b--   --> you guessed 'b' again -->  bb--)
This gives an unexpected behaviour and doesn't perform properly.

- Spaces as a guess count as a guessed letter!

- If you guess several letters at once it will cause the program to have an undesired effect!
Please guess using only 1 character!

- Pickax changed to Pickaxe in dictionary





