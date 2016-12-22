'''
Created on Dec 20, 2016

@author: songjiguo
'''

import numpy as np

class mylistnode(object):
    '''
    list node class
    '''

    def __init__(self, x):
        '''
        Constructor
        '''
        self.val = x
        self.next = None

class mylist(object):
    '''
    list class
    '''
    
    def __init__(self, size, lower, upper):
        '''
        Constructor
        '''
        vals = np.random.randint(lower, upper, size, 'int')
        head = mylistnode(-1)
        p = head
        for i in vals:
            q = mylistnode(i)
            p.next, p = q, q;
            
        return head.next
        
    def printlist(self, head):
        while head:
            print(head.val)
            head = head.next
        