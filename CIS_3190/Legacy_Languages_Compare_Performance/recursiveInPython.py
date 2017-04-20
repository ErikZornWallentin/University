#/************************* recursiveInPython.py ****************************
# Student Name: Erik Zorn - Wallentin  Student Number: 0864583
# Date: Thur, April.2 / 2015           Course Name: CIS*3190 (DE)
# I have exclusive control over this submission via my password.
# By including this statement in this header comment, I certify that:
#  1) I have read and understood the University policy on academic integrity;
#  2) I have completed the Computing with Integrity Tutorial on Moodle; and
#  3) I have achieved at least 80% in the Computing with Integrity Self Test.
# I assert that this work is my own. I have appropriately acknowledged any and all material
# (data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
# Furthermore, I certify that this assignment was prepared by me specifically for this course.
#****************************************************************************/

#This program recursively calls ackermann function to calculate an input (m,n)

import sys, timeit, datetime
import time

def ackermannFunc(m, n):
    if m == 0:
        return n + 1
    elif n == 0:
        return ackermannFunc(m - 1, 1)
    else:
        return ackermannFunc(m - 1, ackermannFunc(m, n - 1))
        

sys.setrecursionlimit(200000)

print ("Ackermann function recursive in Python: Enter two numbers (Below 4 for a quick result)")

#Get the user input and pass to ackermann function (recursion)
firstNum = input("Please enter number 1: ")
secondNum = input("Please enter number 2: ")

start_time = time.time()
print ackermannFunc(firstNum, secondNum)
print("Ackermann Function took %s seconds to complete!" % (time.time() - start_time))
