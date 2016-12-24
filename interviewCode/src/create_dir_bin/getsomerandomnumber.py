#!/home/songjiguo/anaconda3/bin/python

#https://docs.python.org/2/library/random.html

#!/usr/bin/env python
# from scipy.stats import bernoulli,poisson,norm,expon
# import numpy as np

# print(norm.rvs(size=1)[0]*1000)
# print(bernoulli.rvs(.3,size=1))
# print(poisson.rvs(1,2,size=1))
# print(expon.rvs(5,size=1))



import sys
import random
list=sys.argv
start=1
stop=int(list[1])
step=1
num=random.randrange(start, stop, step)
print(num%425)

# print ('Number of arguments:', len(sys.argv), 'arguments.')
# print ('Argument List:', str(sys.argv))
