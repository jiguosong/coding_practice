'''
Created on Nov 15, 2016

@author: songjiguo
'''
import unittest

import validPalindromeStr

class Test(unittest.TestCase):

    def testOk(self):        
        p = validPalindromeStr.solution()        
        self.assertTrue(p.isvalidPalindromeStr("A man, a plan, a canal: Panama"))        

    def testFail(self):        
        p = validPalindromeStr.solution()        
        self.assertFalse(p.isvalidPalindromeStr("AAAAAASFSDFSDASLJLJLL"))        

    def testZero(self):        
        p = validPalindromeStr.solution()        
        self.assertTrue(p.isvalidPalindromeStr(""))        

if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()