'''
Created on Dec 20, 2016

@author: songjiguo
'''
import unittest
import reverselist
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
    
    def __init__(self):
        '''
        Constructor
        '''
       
    def creatList(self, size, lower, upper):
        vals = np.random.randint(lower, upper, size, 'int')
        head=mylistnode(-1)
        p=head
        for i in vals:
            q=mylistnode(i)
            p.next , p = q, q
        return head.next

    def printlist(self, head):
        while head:
            print(head.val)
            head = head.next

class Test(unittest.TestCase):

    def testName(self):
        a = mylist()
        head = a.creatList(10, 1, 10)
        a.printlist(head)
        
        b = reverselist.Solution()
        c = b.ReverseList(head)
        
        print()
        while c:
            print(c.val)
            c = c.next


if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()