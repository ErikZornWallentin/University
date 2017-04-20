#!/usr/bin/python

import os, sys, time, atexit, subprocess, math
import re

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

#**************************
#Purpose: The purpose of this function is to read data to be calculated from the file (the last line) and evaluate the file data
#Parameters: nothing
#Return: nothing
#**************************      
def readFile(PATH):

	#Input file name here to test if its readable, please try input as the file name
	#The file extension at the end is not needed for this call
	
	#Only file that works is called: input.txt
	if os.path.isfile(PATH) and os.access(PATH, os.R_OK):
		file = open("input.txt","r")
		temp = 0
		result = 0
	
		for line in file:
			temp = line
		
		file.close()
	else:
		print "Error file not found!"
		return
	
	if temp != '':
		try:
			temp = replaceWords(temp, dictionary)
			result = eval(temp)
			print result
			
		except SyntaxError:
			print "0"
	else:
		print "0"

#**************************
#Purpose: The purpose of this function is to display the text interface menu
#Parameters: nothing
#Return: nothing
#**************************
def textInterfaceMenu():
   print "1) Press 'f' for file "
   print "2) Press  'm' for manually entering the mathematical equation"
   print "3) Quit"

dictionary = {'sin':'math.sin', 'cos':'math.cos', 'tan':'math.tan', 'pi':'math.pi', 'e':'math.e', 'log':'math.log10', 'sqrt':'math.sqrt', '^':'**', 'factorial':'math.factorial', 'ln':'math.log'}

#####TESTING PLAN######
#All the test cases for testing terminal.py are below and some run automatically, while the failed tests will be commented out.
#######################
def testPlanFunction():

	### Test function "replaceWords" -- Which is used to replace words from the user ###
	print ""
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
	
###Test function "readFile" -- Which is used to read a file ###	
	print "Testing readFile() Function:"
	readingFile = "input"
	readFile(readingFile)				#It accepts the argument, it reads the file because input.txt exists in the directory and prints the file to the text box. PASSED TEST
	print ("PASSED TEST with input file: " + readingFile)
	
	readingFile = "BLAH"
	readFile(readingFile)				#It accepts the argument, throws back an error because the file BLAH does not exist and takes you out of the function. PASSED TEST
	print ("PASSED TEST with input file: " + readingFile)
	
	#readFile(BLAH)					#It accepts the argument, throws an error because it looks for a variable called BLAH that does not exist. FAILED TEST
	#readFile()						#It does no accept no arguments, throws an error and crashes. FAILED TEST
	print ""

### Test function "textInterfaceMenu" -- Which is used to display a menu ###
	print "Testing textInterfaceMnu() Function:"
	textInterfaceMenu()				#It accepts no arguments, prints a menu. PASSED TEST
	print "PASSED TEST printing menu"
	#textInterfaceMenu(BLAH)			#It does not accept the argument, throws an error because it looks for a variable called BLAH that does not exist. FAILED TEST
	#textInterfaceMenu("BLAH")			#It does not accept the argument, throws an error and crashes. FAILED TEST
	print ""		

	print "#####################################"
	print "###Now running the normal program!###"
	print "#####################################"

#######################################
### General Testing of terminal.py ####
#######################################
#Test first menu displayed
		#Input 1 in keyboard and hit enter -> Accepts argument, and calls function to read file. PASSED TEST
		#Input f in keyboard and hit enter -> Accepts argument, and calls function to read file. PASSED TEST
		#Input file in keyboard and hit enter -> Accepts argument, and calls function to read file. PASSED TEST
		#Input 2 in keyboard and hit enter -> Accepts argument, and asks to enter mathematical expression. PASSED TEST
		#Input m in keyboard and hit enter -> Accepts argument, and asks to enter mathematical expression. PASSED TEST
		#Input 3 in keyboard and hit enter -> Accepts argument, quits the program. PASSED TEST
		#Input q in keyboard and hit enter -> Accepts argument, quits the program. PASSED TEST
		#Input sdfsdf in keyboard and hit enter -> Accepts argument, gives an error saying bad input and loops user back to menu options. PASSED TEST
													#Also works for any bad input
#Test option 1 in menu
		#Input 1 in keyboard and hit enter -> Accepts argument, calls the file
		#Input f in keyboard and hit enter -> Accepts argument, calls the file
		#Input file in keyboard and hit enter -> Accepts argument, calls the file	
		#Input random input in keyboard and hit enter -> Accepts argument, says its bad input. PASSED TEST	
	
#Test option 2 in menu
		#Input 1+4 in keyboard and hit enter -> Accepts argument, evaluates the expression and gives result. PASSED TEST
		#Input nothing and hit enter in keyboard -> Gives an error saying bad input. PASSED TEST
		#Input random input into keyboard -> Crashes the program, FAILED TEST
		#Input sin(1) input into keyboard -> Accepts argument, evaluates the expression and gives result. PASSED TEST
		#Input math.sin(1) in keyboard -> Crashes program, FAILED TEST
		#Input 1sin(1) in keyboard -> Gives an error saying bad input. PASSED TEST
	
#Test option 3 in menu
		#Input 3 in keyboard and hit enter -> Accepts argument, quits the program	
		#Input q in keyboard and hit enter -> Accepts argument, quits the program
		#Input quit in keyboard and hit enter -> Accepts argument, quits the program	
		#Input random input in keyboard and hit enter -> Accepts argument, says its bad input. PASSED TEST	


print "Would you like to run the test plan? (Y/N)"
testPlan = raw_input("Enter option (Y/N): ")

if (testPlan == 'y' or testPlan == 'yes' or testPlan == 'YES' or testPlan == 'Y'):
	print "#####################################"
	print "######Now running the Test plan######"
	print "#####################################"
	testPlanFunction()
else:
	print "#####################################"
	print "###Now running the normal program!###"
	print "#####################################"
	

print "" 
print "Welcome to the Text Interface Menu"
print "Please choose from the following:"

   
while True:

	#Call the text interface menu and wait for input from user
	textInterfaceMenu()
	choice = raw_input("Enter option: ")
	
	if (choice == '1' or choice == 'f' or choice == 'file'):
		readFile("input.txt") #Read from file and evaluate the mathematical expression
		break
	elif (choice == '2' or choice == 'm' or choice == 'manual' or choice == 'manually'):
		temp = raw_input("Enter mathematical expression: ")
		if temp:
			try:
				temp = replaceWords(temp, dictionary)
				result = eval(temp)
				print "Your evaluated expression:"
				print result
				print ""
				print "Now exitting the program!"
				print ""
				break
			except SyntaxError: #THIS IS WHY SIN ETC THROWS AN ERROR CUZ IT THINKS IT IS BAD INPUT
				print "Error with input!"
				break
		else:
			print "Error with input!"
			break
		
	elif (choice == '3' or choice == 'q' or choice == 'quit'):
		print ""
		print "Now exitting the program!"
		print ""
		break
	else:
		print "Error please input a menu option: 'f', 'm'"
		print ""

