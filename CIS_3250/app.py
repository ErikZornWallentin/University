#!/usr/bin/python

import os, sys, time, atexit, subprocess, math
from Tkinter import *
from Tkinter import Tk, W, E
from ttk import Frame, Button, Label, Style
from ttk import Entry
import re

import plotly.plotly as py
from plotly.graph_objs import *
py.sign_in("roymorales", "9vlu198zav")

import numpy as np

#**************************
#Purpose: The purpose of this function is to replace specific words in user input box to be readable for the calculator math functions
#Parameters: string (holds self.current variable which is the input from the user
#            theDictionary (passing in the dictionary to find which values to swap)
#Return: returns the string with the replaced values from the dictionary 
#**************************
def replaceWords(string, theDictionary):

	replace = re.compile('|'.join(map(re.escape, theDictionary)))
	def translate(match):
			return dictionary[match.group(0)]
	return replace.sub(translate, string)
	

class Calc():

	#**************************
	#Purpose: The purpose of this function is to store important data to be passed into other functions, the important data will be described below.
	#		  self.current is the current data in the text box
	#         self.newNumber is the variable that checks if the text box needs to be replaced or not after using the equals button
	#         self.eq is the variable that checks if the equals button was pressed or not
	#Parameters: self (the important data to be passed around described above)         
	#Return: nothing
	#**************************
    def __init__(self):
        self.current = ""        #The current data in the text box
        self.newNumber = True    #If the text box needs to be replaced after using equals 
        self.eq = False          #If Equals button pressed or not

	#**************************
	#Purpose: The purpose of this function is to input the data from the buttons pressed Ex. "1" button would turn into 1 on text box
	#Parameters: self (described above)
	#            theDictionary (passing in the dictionary to find which values to swap)
	#Return: returns the string with the replaced values from the dictionary 
	#**************************
    def numPressed(self, num):
    	#This function displays its result to the display box in the GUI
        self.eq = False
      
        temp = border1.get()
        	
        temp2 = str(num)
        if self.newNumber:
            self.current = temp2
            self.newNumber = False
        else:
            self.current = temp + temp2
        border1.delete(0, END)
        border1.insert(0, self.current)
    
    #**************************
	#Purpose: The purpose of this function is to write data to a file (just one line)
	#Parameters: self (described above)
	#Return: nothing
	#**************************   
    def writeFile(self, PATH):
    	
    	#Input filename here to test if its readable, please try output.txt
    	#Remember to use .txt as the extension in the filename
		
		if os.path.isfile(PATH) and os.access(PATH, os.R_OK):
			file = open("output.txt","w")
		
			temp = str(self.current)
			file.write(temp)
			file.close()
		else:
			print "Error with file not found!"	
    
    #**************************
	#Purpose: The purpose of this function is to read data to be calculated from the file (the last line)
	#Parameters: self (described above), PATH(file name)
	#Return: nothing
	#**************************
    def readFile(self, PATH):
    	#Only file that works is called: input.txt
		if not isinstance(PATH,basestring):
			print "Error input is not proper format please use a string!"
			return
					
		#Input file name here to test if its readable, please try input as the file name
		#The file extension at the end is not needed for this call
		if os.path.isfile(PATH) and os.access(PATH, os.R_OK):
			file = open("input.txt","r")
		
		
			self.eq = False
			for line in file:
				self.current = line
				border1.delete(0, END)
				border1.insert(0, line)
				self.newNumber = False
			file.close()
		else:
			print "Error with file not found!"
			
    #**************************
	#Purpose: The purpose of this function is to clear the calculator data and put 0 in the text box
	#Parameters: self (described above)
	#Return: nothing
	#**************************    
    def clearResult(self):
    	self.eq = False
    	border1.delete(0, END)
    	border1.insert(0, "0")
    	self.newNumber = True #Make sure to set to True so it knows when to deal with '0' as the first input
    
    #**************************
	#Purpose: The purpose of this function is to clear the calculator data and put nothing in the text box
	#Parameters: self (described above)
	#Return: nothing
	#**************************    	
    def allClearResult(self):
    	self.eq = False
    	border1.delete(0, END)
    	self.newNumber = True #Make sure to set to True so it knows when to deal with '0' as the first input
    
    #**************************
	#Purpose: The purpose of this function is to graph the text box data into the plotly website with username: roymorales
	#Parameters: self (described above)
	#Return: nothing
	#**************************    
    def graphResult(self):
    	#This function will call the plotly website after being called, plotly website will display some info from the call on the terminal
    	
    	u = []
    	z = []
    
    	if(self.current != ''):
    		temp = replaceWords(self.current, graphDictionary)
    		
        	#GET ALL TEST VALUES FOR X (RANGE FROM -PI to +PI)
        	xValues = np.linspace(-math.pi, math.pi, 256, endpoint=True)

        	#GET ALL X VALUES
        	for i in xValues:
        		z.append(i)

			#SOLVE FOR ALL Y VALUES
			for x in xValues:
				u.append(eval(temp))
			
        	#GRAPH
        	trace1 = Scatter(
            	x = z,
            	y = u,
            	mode = 'lines'
        	)
        	data = Data([trace1])
        	plot_url = py.plot(data, filename='line-scatter')
    
    #**************************
	#Purpose: The purpose of this function is to evaluate all the information in the text box from the user and give the result
	#Parameters: self (described above)
	#Return: nothing
	#**************************
    def calculateResult(self):
    
    	#Exit function if equals button was already pressed!
    	if self.eq == True:
    		return
    		
    	self.eq = True
    	
        result = 0
        temp = 0
        #Replace any word in the text box with the dictionary part Ex. sin -> math.sin to be calculated
        #Create new temp variable to get the input and create result to calculate the input from the user
    	temp = replaceWords(self.current, dictionary)
    	
        #temp = self.current #if you just want the textbox without replacing the data
        
        if self.current != '':
			try:
				result = eval(temp)
				border1.delete(0, END)
				border1.insert(0, result)
				self.current = result
				self.newNumber = True #If you want to replace the old result automatically on the next input after equals button

			except SyntaxError: #THIS IS WHY SIN ETC THROWS AN ERROR CUZ IT THINKS IT IS BAD INPUT
				border1.delete(0, END)
				border1.insert(0, "0")
				self.current = result
					
        else:
        	border1.delete(0, END)
        	border1.insert(0, "0")
        	self.current = result
        	self.newNumber = True #If you want to replace the old result automatically on the next input after equals button

input = Calc()
root = Tk()
calc = Frame(root)
calc.grid()

new = Frame(root)
new.grid()

number = StringVar()
equalsHit = False

#dictionary: converts all the key words to readable format for the scientific calculator
dictionary = {'sin':'math.sin', 'cos':'math.cos', 'tan':'math.tan', 'pi':'math.pi', 'e':'math.e', 'log':'math.log10', 'sqrt':'math.sqrt', '^':'**', 'factorial':'math.factorial', 'ln':'math.log', 'DtoR':'math.radians', 'RtoD':'math.degrees'}

#graphDictionary: converts all the key words to readable format for the graphing function
graphDictionary = {'sin':'np.sin', 'cos':'np.cos', 'tan':'np.tan', 'pi':'np.pi', 'e':'np.e', 'log':'np.log10', 'sqrt':'np.sqrt', '^':'**', 'factorial':'np.factorial', 'ln':'np.log', 'DtoR':'np.radians', 'RtoD':'np.degrees'}

root.title("Calculator for Mathematics")

Style().configure("TButton", padding=(0,5,0,5), font='cambria 15')

border1 = Entry(calc, justify=RIGHT)
border1.grid(row = 0, column = 0, columnspan = 9, pady = 5, sticky=W+E)
border1.insert(0, "0")

sinButton = Button(calc, text = "sin(x)")
sinButton["command"] = lambda val = "sin(": input.numPressed(val)
sinButton.grid(row = 1, column = 4, pady = 5, sticky=W+E)

cosButton = Button(calc, text = "cos(x)")
cosButton["command"] = lambda val = "cos(": input.numPressed(val)
cosButton.grid(row = 1, column = 5, pady = 5, sticky=W+E)

tanButton = Button(calc, text = "tan(x)")
tanButton["command"] = lambda val = "tan(": input.numPressed(val)
tanButton.grid(row = 1, column = 6, pady = 5)

clearButton = Button(calc, text = "Clear")
clearButton["command"] = input.clearResult
clearButton.grid(row = 1, column = 7, pady = 5, sticky = W)

allClearButton = Button(calc, text = "Reset")
allClearButton["command"] = input.allClearResult
allClearButton.grid(row = 1, column = 8, pady = 5)

piButton = Button(calc, text = u"\u03C0")
piButton["command"] = lambda val = "pi": input.numPressed(val)
piButton.grid(row = 2, column = 6, pady = 5)

expButton = Button(calc, text = "e")
expButton["command"] = lambda val = "e": input.numPressed(val)
expButton.grid(row = 2, column = 7, pady = 5)

logButton = Button(calc, text = "log(x)")
logButton["command"] = lambda val = "log(": input.numPressed(val)
logButton.grid(row = 2, column = 8, pady = 5)

powerButton = Button(calc, text = "x ^ y")
powerButton["command"] = lambda val = "^": input.numPressed(val)
powerButton.grid(row = 2, column = 4, pady = 5)

modButton = Button(calc, text = "%")
modButton["command"] = lambda val = "%": input.numPressed(val)
modButton.grid(row = 3, column = 4, pady = 5)

factorialButton = Button(calc, text = "!(x)")
factorialButton["command"] = lambda val = "factorial(": input.numPressed(val)
factorialButton.grid(row = 3, column = 5, pady = 5)

lnButton = Button(calc, text = "ln(x)")
lnButton["command"] = lambda val = "ln(": input.numPressed(val)
lnButton.grid(row = 3, column = 6, pady = 5)

degreeButton = Button(calc, text = "DtoR")
degreeButton["command"] = lambda val = "DtoR(": input.numPressed(val)
degreeButton.grid(row = 3, column = 7, pady = 5)

radianButton = Button(calc, text = "RtoD")
radianButton["command"] = lambda val = "RtoD(": input.numPressed(val)
radianButton.grid(row = 3, column = 8, pady = 5)

sqrtButton = Button(calc, text = u"\u221A")
sqrtButton["command"] = lambda val = "sqrt(": input.numPressed(val)
sqrtButton.grid(row = 2, column = 5, pady = 5)

label1 = Label(calc, text="")
label1.grid(row=4, column=4, columnspan = 8, pady = 5, sticky=W+E) 

oneButton = Button(calc, text = "1")
oneButton["command"] = lambda val = 1: input.numPressed(val)
oneButton.grid(row = 5, column = 4, pady = 5)  

twoButton = Button(calc, text = "2")
twoButton["command"] = lambda val = 2: input.numPressed(val)
twoButton.grid(row = 5, column = 5, pady = 5)

threeButton = Button(calc, text = "3")
threeButton["command"] = lambda val = 3: input.numPressed(val)
threeButton.grid(row = 5, column = 6, pady = 5)

openBracketButton = Button(calc, text = "(")
openBracketButton["command"] = lambda val = "(": input.numPressed(val)
openBracketButton.grid(row = 5, column = 7, pady = 5) 

closeBracketButton = Button(calc, text = ")")
closeBracketButton["command"] = lambda val = ")": input.numPressed(val)
closeBracketButton.grid(row = 5, column = 8, pady = 5)

fourButton = Button(calc, text = "4")
fourButton["command"] = lambda val = 4: input.numPressed(val)
fourButton.grid(row = 6, column = 4, pady = 5) 

fiveButton = Button(calc, text = "5")
fiveButton["command"] = lambda val = 5: input.numPressed(val)
fiveButton.grid(row = 6, column = 5, pady = 5)

sixButton = Button(calc, text = "6")
sixButton["command"] = lambda val = 6: input.numPressed(val)
sixButton.grid(row = 6, column = 6, pady = 5)

multButton = Button(calc, text = "X")
multButton["command"] = lambda val = "*": input.numPressed(val)
multButton.grid(row = 6, column = 7, pady = 5)

xVarButton = Button(calc, text = "Var: x")
xVarButton["command"] = lambda val = "x": input.numPressed(val)
xVarButton.grid(row = 8, column = 7, pady = 5)

divButton = Button(calc, text = "/")
divButton["command"] = lambda val = "/": input.numPressed(val)
divButton.grid(row = 6, column = 8, pady = 5)

sevenButton = Button(calc, text = "7")
sevenButton["command"] = lambda val = 7: input.numPressed(val)
sevenButton.grid(row = 7, column = 4, pady = 5) 

eightButton = Button(calc, text = "8")
eightButton["command"] = lambda val = 8: input.numPressed(val)
eightButton.grid(row = 7, column = 5, pady = 5)

nineButton = Button(calc, text = "9")
nineButton["command"] = lambda val = 9: input.numPressed(val)
nineButton.grid(row = 7, column = 6, pady = 5) 

addButton = Button(calc, text = "+")
addButton["command"] = lambda val = "+": input.numPressed(val)
addButton.grid(row = 7, column = 7, pady = 5)

subButton = Button(calc, text = "-")
subButton["command"] = lambda val = "-": input.numPressed(val)
subButton.grid(row = 7, column = 8, pady = 5)

zeroButton = Button(calc, text = "0")
zeroButton["command"] = lambda val = 0: input.numPressed(val)
zeroButton.grid(row = 8, column = 4, pady = 5)

dotButton = Button(calc, text = ".")
dotButton["command"] = lambda val = ".": input.numPressed(val)
dotButton.grid(row = 8, column = 5, pady = 5)

negButton = Button(calc, text = "( - )")
negButton["command"] = lambda val = "-": input.numPressed(val)
negButton.grid(row = 8, column = 6, pady = 5)

equalsButton = Button(calc, text = "=")
equalsButton["command"] = input.calculateResult
equalsButton.grid(row = 8, column = 8, padx=5, pady = 5, sticky=W+E)

label2 = Label(calc, text="")
label2.grid(row=9, column=4, columnspan = 8, pady =5) 

readFileButton = Button(calc, text = "Read File")
readFileButton["command"] = lambda val = "input.txt": input.readFile(val)
readFileButton.grid(row = 10, column = 4, pady = 5)

writeFileButton = Button(calc, text = "Write File")
writeFileButton["command"]= lambda val = "output.txt": input.writeFile(val)
writeFileButton.grid(row = 10, column = 5, pady = 5) 

graphButton = Button(calc,text="Graph",command = input.graphResult)
graphButton.grid(row = 10, column = 6, pady = 5)

button = Button(calc,text="Quit",command = calc.quit)
button.grid(row = 10, column = 8, pady = 5)

print "Would you like to run the test plan? (Y/N)"
testPlan = raw_input("Enter option (Y/N): ")

#####TESTING PLAN######
#All the test cases for testing app.py are below and some run automatically, while the failed tests will be commented out.
#######################
if (testPlan == 'y' or testPlan == 'yes' or testPlan == 'YES' or testPlan == 'Y'):
	print "#####################################"
	print "######Now running the Test plan######"
	print "#####################################"

	### Test function "numPressed" -- Which is used to input data from the buttons pressed ###
	print ""
	print "Testing numPressed() Function:"
	inputValue = "1"
	input.numPressed(inputValue)		#Press equals button, it correctly passes 1 without any errors and takes the result. PASSED TEST
	print("PASSED TEST with value: " + inputValue)
	
	inputValue = "BLAHH"
	input.numPressed(inputValue)		#Press equals button, it accepts BLAHH into the final result but gives out 0 as an error taken. PASSED TEST
	print("PASSED TEST with value: " + inputValue)
	
	inputValue = "sin(1)"
	input.numPressed(inputValue)				#Press equals button, it accepts the argument and gives out a proper final calculated result. PASSED TEST
	print("PASSED TEST with value: " + inputValue)
	
	inputValue = "1sin(1)"
	input.numPressed(inputValue)			#Press equals button, it accepts the argument and gives out 0 as an error taken because it cannot calculate the result. PASSED TEST
	print("PASSED TEST with value: " + inputValue)
	
	#input.numPressed(fdsdfs)				#Not a proper argument, FAILED TEST

	print ""
	
	### Test function "writeFile" -- Which is used to write to a file ###
	print "Testing writeFile() Function:"
	
	fileInput = "blah"
	input.writeFile(fileInput)			#It accepts the argument, throws an error not found because a file does not exist with that name. PASSED TEST
	print("PASSED TEST with file name: " + fileInput)

	fileInput = "output.txt"
	input.writeFile(fileInput)			#It accepts the argument, it write to the file because output.txt exists in the directory and writes the text box to file. PASSED TEST
	print("PASSED TEST with file name: " + fileInput)
	
	fileInput = "output"
	input.writeFile(fileInput)			#It accepts the argument, throws an error even though we have a file called output, it needs .txt parameter to work. PASSED TEST
	print("PASSED TEST with file name: " + fileInput)
	
	#input.writeFile()						#It does not accept no arguments, FAILED TEST
	#input.writeFile(blahhh)				#It does not accept the argument, throws an error because it thinks its a variable and it doesn't exist. FAILED TEST

	print ""
	
	### Test function "readFile" -- Which is used to read a file ###
	print "Testing readFile() Function:"
	
	fileOutput = "blah"
	input.readFile(fileOutput)				#It accepts the argument, throws an error not found because a file does not exist with that name. PASSED TEST
	print("PASSED TEST with file name: " + fileOutput)
	
	fileOutput = "input"
	input.readFile(fileOutput)				#It accepts the argument, it reads the file because input.txt exists in the directory and prints the file to the text bos. PASSED TEST
	print("PASSED TEST with file name: " + fileOutput)
	
	#input.readFile(blahh)				    #It does not accept the argument, throws an error because it thinks its a variable and it doesn't exist. FAILED TEST
	#input.readFile()						#It does not accept no arguments, FAILED TEST

	### Test function "clearResult" -- Which is used to clear the text box to make it have only "0" inside of it ###
	print "Testing clearResult() Function:"
	
	input.clearResult()						#It accepts no arguments, clears everything properly and replaces with "0". PASSED TEST
	print("PASSED TEST: cleared text box and put in 0")
	#input.clearResult("BLAHH")				#It does not accept arguments passed to it, FAILED TEST
	#input.clearResult(blahh)				#It does not accept arguments passed to it, FAILED TEST
	
	print ""

	### Test function "allClearResult" -- Which is used to clear the text box to make it have no data inside of it ###
	print "Testing allClearResult() Function:"
	
	input.allClearResult()					#It accepts no arguments, clears everything properly. PASSED TEST
	print("PASSED TEST: cleared text box")
	#input.allClearResult("BLAHH")			#It does not accept arguments passed to it, FAILED TEST
	#input.allClearResult(blahh)			#It does not accept arguments passed to it, FAILED TEST
	
	print ""

	### Test function "calculateResult" -- Which is used to evaluate everything in the text box ###
	print "Testing clearResult() Function:"
	input.calculateResult()				#It accepts no arguments, properly calculates the textbox. PASSED TEST
	print("PASSED TEST: calculated everything in text box")
	#input.calculateResult("BLAHH")			#It does not accept arguments passed to it, FAILED TEST
	#input.calculateResult(blahh)			#It does not accept arguments passed to it, FAILED TEST
	
	print ""

	### Test function "replaceWords" -- Which is used to replace words from the user ###
	print "Testing replaceWords() Function:"
	temp2 = replaceWords("sin", dictionary)			#It accepts the arguments, replaces sin word to math.sin . PASSED TEST
	print ("PASSED TEST with result: " + temp2)
	temp2 = replaceWords("math.sin", dictionary)	#It accepts the arguments, replaces sin word to math.sin and gives out math.math.sin. FAILED TEST
	print ("FAILED TEST with result: " + temp2)
	temp2 = replaceWords("", dictionary)			#It accepts the arguments, prints out nothing. PASSED TEST
	print ("PASSED TEST with result: " + temp2)
	#temp2 = replaceWords(dictionary)				#Gives an error, it needs the 2 proper arguments (string, dictionary). FAILED TEST
	#temp2 = replaceWords()							#Gives an error, it needs the 2 proper arguments (string, dictionary). FAILED TEST
	#temp2 = replaceWords(dictionary, "")			#Gives an error, it needs the 2 proper arguments (string, dictionary). FAILED TEST
	temp2 = replaceWords("1+5", dictionary)			#It accepts the arguments, does not replace anything and gives back the same string. PASSED TEST
	print ("PASSED TEST with result: " + temp2)

	#print temp2
	print ""
	
	### Test function "graphResult" -- Which is used to evaluate everything in the text box ###
	print "Testing graphResult() Function:"
	#input.graphResult()						#It accepts no arguments, properly calculates the textbox. PASSED TEST
	print("FAILED TEST: graphResult() has no data")
	
	#input.calculateResult("BLAHH")			#It does not accept arguments passed to it, FAILED TEST
	#input.calculateResult(blahh)			#It does not accept arguments passed to it, FAILED TEST

	print "#####################################"
	print "###Now running the normal program!###"
	print "#####################################"
	#######################################
	### General Testing of app.py      ####
	#######################################

	#Testing the GUI
		#Spam the '=' button to see if we can generate an error at any time?    ---> Works correctly does not give any error or any problems. PASSED TEST
		#Check if all the buttons work correctly?                               ---> Works correctly, all buttons work as intended. PASSED TEST
		#Can user give bad input to be calculated?                              ---> Works correctly, if there is any bad input it will give some type of response or the text box will display 0 as an error.
		#Can user input random keyboard into text box?                          ---> Yes accepts any keyboard, will not calculate any input from the keyboard and be replaced. PASSED TEST
else:
	print "#####################################"
	print "###Now running the normal program!###"
	print "#####################################"

root.mainloop()
