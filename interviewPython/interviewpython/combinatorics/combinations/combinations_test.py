'''
Created on Nov 15, 2016

@author: songjiguo
'''
import unittest

import combinations
import itertools

class Test(unittest.TestCase):

    def testOk(self):
        p = combinations.solution()
        res = p.combine(4,2)
        tmp = list(itertools.combinations(range(1,5),2))
        expected = [list(x) for x in tmp]
        self.assertEqual(res, expected)
        
    def testFail(self):
        p = combinations.solution()
        res = p.combine(4,2)
        tmp = list(itertools.combinations(range(1,5),2))
        expected = [list(x) for x in tmp]
        del expected[0]
        self.assertNotEqual(res, expected)

    def testZero(self):
        p = combinations.solution()
        res = p.combine(0,0)
        self.assertEqual(0, len(res))
    
    def testLarge(self):
        p = combinations.solution()
        res = p.combine(50,4)
        tmp = list(itertools.combinations(range(1,51),4))
        expected = [list(x) for x in tmp]
        self.assertEqual(res, expected)
       
if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()