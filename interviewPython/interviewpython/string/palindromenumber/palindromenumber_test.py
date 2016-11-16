'''
Created on Nov 15, 2016

@author: songjiguo
'''
import unittest

import palindromenumber

class Test(unittest.TestCase):

    def testOK(self):
        p = palindromenumber.solution()
        num = 121
        self.assertTrue(p.isPalindromenumber(num))
    
    def testFail(self):
        p = palindromenumber.solution()
        num = 122
        self.assertFalse(p.isPalindromenumber(num))

    def testZero(self):
        p = palindromenumber.solution()
        num = 0
        self.assertTrue(p.isPalindromenumber(num))
        
    #In python, integers have arbitrary precision and therefore we can represent 
    # an arbitrarily large range of integers (only limited by memory available).
    def testOverflow(self):   
        p = palindromenumber.solution()
        num = 2**200
        self.assertFalse(p.isPalindromenumber(num))        
        
if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()