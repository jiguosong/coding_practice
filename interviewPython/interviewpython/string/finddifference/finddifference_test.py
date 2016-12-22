'''
Created on Dec 20, 2016

@author: songjiguo
'''
import unittest

import finddifference

class Test(unittest.TestCase):

    def testName(self):
        p = finddifference.Solution()
        self.assertEquals('f', p.findTheDifference("abd", "abdf"))

    def test2Name(self):
        p = finddifference.Solution()
        self.assertEquals(' ', p.findTheDifference("abd", "abd"))

if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()