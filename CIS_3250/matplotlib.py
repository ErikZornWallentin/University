#!/usr/bin/python


#import matplotlib.pyplot as plt
#import numpy as np
#import math

import pyglet


def graphingFunction(formula):
 x = np.linspace(14,-14,2000,endpoint = True)
 y = eval(formula)
 plt.plot(x,y)
 plt.show()


#print "Please enter your equation"
#string = raw_input()
#graphingFunction(string)
