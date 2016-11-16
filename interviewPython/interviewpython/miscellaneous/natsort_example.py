'''
Created on Nov 15, 2016

@author: songjiguo

'''

a = ['a2', 'a9', 'a1', 'a4', 'a10']
print (sorted(a))

from natsort import natsorted, ns
print (natsorted(a))

a = ['1.2', '1.2rc1', '1.2beta2', '1.2beta1', '1.2alpha', '1.2.1', '1.1', '1.3']
print (natsorted(a))