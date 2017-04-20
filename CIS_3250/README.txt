****************************************************
Janki Desai - 0843299
Brandon Gordon - 0850874
Erik Zorn-Wallentin	0864583
Roy Morales - 0845495

CIS*3250			    Group 2: Assignment - Calculator
Friday, Nov. 21 / 2014  Teacher: Dr. David Calvert
****************************************************

******************
Group Members
******************
Janki Desai 0843299 		 - Worked hard, tried to make up for lack of help from teammates, attended almost every meeting
Roy Morales 0845495 		 - Worked hard, tried to make up for lack of help from teammates, attended almost every meeting
Erik Zorn-Wallentin  0864583 - Worked hard, tried to make up for lack of help from teammates, attended almost every meeting

Brandon Gordon				 - Worked a few hours on GUI, attended only 2-3 meetings out of entire semester.

Ethan Nichol 0832811		 - Did not write any code, did not attend any meetings, did not help us in any way, asked to help once but disappeared after.
							 - Has never seen the calculator, as he never came to work on project.

Brinean Crews 0826471	     - Did not write any code, attended only 3-5 meetings out of entire semester, did not help with calculator
							 - Has never ran the calculator, and does not know how it works.
							 
Jacky Chen 0843300			 - Worked a few hours on last day on matplotlib with 2 other people, attended only 3-5 meetings out of entire semester
							 - Only helped on last day with other members, did not help throughout the semester			 
							 - Has never ran the calculator, as he never came to work on project, does not know how calculator works
							 

***************************************************************
Very Important Instructions - Please do this first before anything!
***************************************************************

Inside group2 folder there is a file called "plotly-1.4.5", move this folder to your Desktop.
Open terminal and follow these commands:
cd Desktop
cd plotly-1.4.5
 	-You should now be in the plotly folder
When you are in the plotly folder type in terminal:
python setup.py install --user
	-It will run a commands for a minute or two so please wait for it to finish.
Once it is finished drag the folder back to group2, and all the proper files to run the calculator should now be installed.
When using any graph commands, please wait a few seconds for the graph to be displayed.


**********
Overview
**********

There are three main components to this project. There is a main program which gives a menu to decide which program you want to use.
The remaining components of the project are: Text interface, Scientific calculator GUI (Graphical User Interface)

The main program (calculator.py):
	Should be run first, and it will display a menu option to decide on the other components to use for the calculator.

The Text interface component (terminal.py):
	Will display a menu, take in a file to read expression and evaluate the result to print to the screen or allow the user to manually input an expression
	and print the result
	
Scientific Calculator GUI (app.py):
	Will display a new application, it is a scientific calculator that would mimic a normal calculator task.
	It has a text box to display all current data (input and results from user) and widget buttons for the user
	to input new information into the calculator. 
		Ex the button "1" would input 1 into the display box as the current data.
	It also has advance scientific calculator functions such as sin, cos, tan, log, etc
	It can also read in a file and write to a file (the current data on the display box)
	
	Scientific calculator graph button:
	
	This button has graphing capabilities. It will graph when you press the "graph" button on the calculator and that
	will open plotly wbesite which will display the calculated graph of the input from the user.
	Use "Var:x" button to get a variable x into the display box, but once you use the x button only use graph button to calculate,
	if you try to press '=' while using 'x' it will crash the program and is a known limitation.
	
*******************
Technical Features
*******************

Dictionary: There are two dictionaries for the scientific calculator, one dictionary will convert all the key words to readable format for scientific calculator,
			the other dictionary will convert all the key words to readable format for the graphing function.
			Dictionary uses replaceWords function which takes in string to replace and the dictionary. More of a description is given in "app.py" file.
			
Graphing:	We are using plotly library for our graphing in function called graphResult().  When calling graphResult it will evaluate the given string and
			send it to the plotly website to be displayed in a readable graph format. More of a description is given in "app.py" file.
			
GUI:		Graphical Interface is displayed when using "app.py" file, this is our normal scientific calculator that evaluates any input given to a calculated result,
			or can output a readable graph. More of a description is given in "app.py" file.
			
File:		Our input file is called "input.txt" and needs to be called that if you want data to be read from our calculator, our output file is called "output.txt".
			When reading in from a file if it uses any variables like 'x' it can only use the graphing functions and cannot use '=' button anymore for a normal evaluation.
			Also when using the opposite, like not using any variables called 'x' should not use the graphing functions. This is a known limitation of the project.
			When reading in from a file it uses readFile() function and when the user wants to write to a file it uses writeFile() function. 
			More of a description is given in "app.py" and "terminal.py" file.
			
Input:		For the scientific calculator: 
				When the user inputs any data it will always use the numPressed(input) function to add the input to the total input in the display box at top of program.
				calculateResult(input) will take all the input from the display box at the top and try to evaluate the entire expression when you press "=" button.
					
			For the text interface:
				All of the input is handled through prompts which directly pass the input to calculateResult(input) and follows the same routine as indicated above.
				
			More of a description is given in "app.py" and "terminal.py" file.
			
Other:		All the information of functions, general GUI info, algorithms, etc are commented in each python file. 	
			Please see "app.py" and "terminal.py" to see detailed info on any other information needed.	
	


************
Compilation
************

To compile this program make sure you are in the correct directory in the terminal to where your file is.
The directory will be named group2, and it will contain three python files: 
	calculator.py
	terminal.py 
	app.py 
You may need to chmod u+x filename on all three files before running. 
	Ex. chmod u+x calculator.py

**************************************
Running the program(s) / Instructions
**************************************

After compiling the program properly, you should run the program by typing: 
	"./calculator.py" in the terminal.
	
Make sure to follow the above instruction to ensure you will run everything correctly which will give menu options
on running the other programs. 

When running the "./calculator.py" also called the "main file" a menu will show:
1) Text Interface
2) Scientific Calculator GUI
3) Quit

Example:
If the user will press option 1) Text Interface the program, then "./terminal.py" will be called and a new menu will pop up:
 
1) Press 'f' for file
2) Press 'm' for manually entering the mathematical expression

The 'f' option allows the user to read one line from a file and calculates the result to print on the screen
The 'm' option allows the user to manually enter a mathematical expression that will calculate the result and print to the screen

Some examples of using the 'm' option in the menu:

1+3*5 ---> Hit enter to get result
1+sin(1) --> Hit enter to get result
pi + 5 ---> Hit enter to get result

1sin(1) ---> Correct way would be: 1*sin(1)
2tan(1+3) ---> Correct way would be: 2*tan(1+3)
2log(1) ---> Correct way would be: 2*log(1)
e7 ---> Correct way would be e * 7

Example:
If the user will press option 2) Scientific Calculator GUI, then "./app.py" will be called and a new application will pop up:

The GUI will be displayed for the scientific calculator, and it will perform calculator functions.
Any input or results will be displayed at the top of the screen, and all buttons will perform as what they are labelled to do:

Some Examples:

"1" would display 1 on the text box at the top of the program, while buttons "1" -> "+" -> "2" -> "=" would display 3 at the top.
Please remember to close any brackets when using any advanced functions like sin, cos, tan as when you use their buttons they will have
an opening bracket and needs to be closed.

Some buttons may be confusing, almost every advanced function such as sin,cos,tan,log will use a specific format following:
sin(x) ---> where x is the user input and when the button is pressed it opens a bracket and expects it to be closed.

DtoR button short form is actually called: Degrees to Radians and it also accepts the same format as sin,cos,tan, etc.
DtoR button converts some value to radians.

RtoD button short from is actually called: Radian to Degrees and it also accepts the same format as sin,cos,tan etc.
DtoR button converts some value to degrees.

"!" button is factorial and accepts the same format as sin,cos,tan etc.

"Var: x" button is just a variable x which displays x on the display box.

***********
Test Plan
***********
Each python file when ran will prompt if you would like to run a test plan on the current file or not.
The prompt will display (Y/N):
	Press N if user chooses to not run any test cases
		If the user decides to not run test cases, the program will run normally 
	Press Y if user chooses to run test cases
		If the user decides to run test cases, the results will be printed out before running the main program.


When using the scientific calculator (app.py) please look at the terminal when you run the program to choose
an option on the prompt, the application doesn't wait for a Y/N and this is a known limitation. 
Please choose an option before using the scientific calculator.

Each python file that uses a test plan will have a documentation of the test plan inside the python file.
Example:

The scientific calculator (app.py) will have its test plan documentation inside the file. 
You can look at the test plan and a few of the test cases will be commented out that will crash the program if you choose to uncomment the test case.

Also each test plan will have a commented section that will describe how to test the file normally (GUI)

**************************
Bibliography / References
**************************
https://plot.ly/ -- plotly main website
https://plot.ly/python/getting-started/ -- help install plotly library
http://stackoverflow.com/questions/11091548/centering-and-size-a-windows-frame-in-tkinter-class-python -- help with understanding TkInter module
http://zetcode.com/gui/tkinter/layout/ -- help understanding the GUI layout
https://docs.python.org/2/library/math.html -- help with the math library in python for advanced functions
https://www.daniweb.com/software-development/python/code/216636/multiple-word-replace-in-text-python# -- help understanding dictionary
Unicode references:
http://www.fileformat.info/info/unicode/char/221A/index.htm - Square Root
http://www.fileformat.info/info/unicode/char/03c0/index.htm - PI

******************
Known Limitations
******************

When running the scientific calculator it will prompt the user if they want to run a test plan, if the user
exits the scientific calculator pop up and after presses "Y" to run the test plan the program will crash.

All the calculations for sin,cos,tan are in radians.

The scientific calculator and the graphing functions need to be exact on the correct input on the sin, cos, tan, sqrt, e, log, etc.
An example of this would be: 
1+sin(1) ---> Correct way to input sin function ( using buttons "1","+","sin","1",")" )
1sin(1) ---> Incorrect way to use sin function it needs to have an operand (+,-,/,*) before using the sin button.
The other advanced functions follow the same protocol such as cos, tan, log, etc.

All the advanced functions when the user presses them they will start with an open bracket and the user needs to 
close the bracket after their input for the calculation after pressing "=" to calculate properly.
An example of this would be:

Press sin button, -> sin(1  --> press "=" ---> Incorrect, would give an error
Press sin button, -> sin(1)  --> press "=" ---> Correct way
The other advanced functions follow the same protocol such as cos, tan, log, etc

Not enough work was done on the calculator and the scientific calculator, so the graphing calculator needed to be separate.
They both follow different calls and calculation protocols differently and this is why they are in separate python files,
with more time they would have been put together in one python file that the user could use in the normal GUI.

The Text Interface Menu when using any advanced functions such as sin, cos, tan, log, etc, needs to use the math library on input.
An example of this would be:
When the user manually inputs a mathematical expression for: 1sin(1)
The correct way of doing the above expression would be 1*sin(1) or the program will crash,
if the user writes 1sin(1) that is the incorrect method and will not work correctly.

The Scientific Calculator GUI has a text box/ label box at the top of the program, it allows any input from the keyboard.
This is a known limitation and the user should not write anything from the keyboard in that box or the program will just give 0 as the result after pressing the '=' button.

IMPORTANT - If the input file has any variable (x or y) in it, it will crash when reading in the file from any python program. 
Please only use scientific functions and numbers in input.txt.

IMPORTANT - The Scientific Calculator has graphing capabilities, if you are using 'x' as input and try to calculate it with '=' button it,
will crash the program. Please when you are not graphing do not use 'var:x' button as that will only be able to calculate using graph button.

After pressing the graph button and when you exit graph, press enter in the terminal to fully quit everything.

The only input file is called: input.txt and if you want to add your own data it needs to be called input.txt and can replace our current input.txt file.

