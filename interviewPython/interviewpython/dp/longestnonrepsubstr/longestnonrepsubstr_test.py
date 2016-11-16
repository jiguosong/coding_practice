'''
Created on Nov 15, 2016

@author: songjiguo
'''
import unittest

import longestnonrepsubstr

class Test(unittest.TestCase):

    def testOK(self):
        p = longestnonrepsubstr.solution()
        s = "abbca"
        expected = 3
        res = p.findLongestNonrepSubstr(s)
        self.assertEqual(res, expected)

    def testFail(self):
        p = longestnonrepsubstr.solution()
        s = "sdlsakf"
        expected = 5
        res = p.findLongestNonrepSubstr(s)
        self.assertNotEqual(res, expected)
        
if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()