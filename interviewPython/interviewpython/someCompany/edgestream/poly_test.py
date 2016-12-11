'''
Created on Dec 10, 2016

@author: songjiguo
'''
import unittest

import poly

class Test(unittest.TestCase):

    def testName(self):
        eq1 = "-yx8+9x3-1+y"
        eq2 = "x5y+1+x3"
        x = poly.multi()
        x.product(eq1, eq2)


if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()