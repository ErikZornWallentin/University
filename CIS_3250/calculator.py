#!/usr/bin/python

import sys, os

	
def menuFunction():

   print "Please choose from the following"
   print "1) Text Interface"
   print "2) Scientific Calculator GUI"
   print "3) Quit"
   

choice = 0
counter = 0
print ""
print "                      CIS*3250 Group Project - Calculator"
print "                 What would you like to run the program on?"
print ""

while True:
	menuFunction()
	choice = raw_input("Enter option: ")
	
	if (choice == '1' or choice == 'terminal' or choice == 'text' or choice == 't'):
		os.system("python terminal.py")
		break
	elif (choice == '2' or choice == 'scientific' or choice == 's' or choice == 'calculator'):
		os.system("python app.py")
		break
	elif (choice == '3' or choice == 'q' or choice == 'quit'):
		print ""
		print "Now exitting the program!"
		print ""
		break
	else:
		print "Error please input a menu option: 1,2,3"
		print ""
	
	


