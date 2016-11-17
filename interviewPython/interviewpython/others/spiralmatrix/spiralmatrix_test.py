'''
Created on Nov 17, 2016

@author: songjiguo
'''
import unittest

import spiralmatrix

class Test(unittest.TestCase):    

    def testOk(self):
        p = spiralmatrix.solution()
        matrix = [[1,2,3], [4,5,6], [7,8,9]]
        expected_res = [1,2,3,6,9,8,7,4,5]
        self.assertEqual(expected_res, p.spiralOrder(matrix))
        
    def testOk2(self):
        p = spiralmatrix.solution()
        matrix = [[1,2,3], [4,5,6]]
        expected_res = [1,2,3,6,5,4]
        self.assertEqual(expected_res, p.spiralOrder(matrix))

    def testOk3(self):
        p = spiralmatrix.solution()
        matrix = [[1]]
        expected_res = [1]
        self.assertEqual(expected_res, p.spiralOrder(matrix))

    def testOk4(self):
        p = spiralmatrix.solution()
        expected_res = [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]
        self.assertEqual(expected_res, p.generateMatrix(3))


if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()