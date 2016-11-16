'''
Created on Nov 15, 2016

@author: songjiguo
'''
import unittest

import medianofTwo

class Test(unittest.TestCase):

    def testOk1(self):
        p = medianofTwo.solution()
        a = [1,2, 3, 4, 5, 7, 8, 100]
        b = [3,4]
        result = p.findmedianofTwo(a, b)
        
        
    def testOk2(self):
        p = medianofTwo.solution()
        a = [1,2]
        b = [3,4]
        self.assertEqual(p.findmedianofTwo(a, b), 2.5)

    def testOk3(self):
        p = medianofTwo.solution()
        a = [1,3]
        b = [2]
        self.assertEqual(p.findmedianofTwo(a, b), 2.0)
                
if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()