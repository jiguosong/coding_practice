'''
Created on Nov 15, 2016

@author: songjiguo
'''
import unittest

import sum
import random
import time
import timeit

class Test(unittest.TestCase):        
    def testOK(self):
        p = sum.sumsolution()
        nums = [2, 7, 11, 15]
        target = 9;
        inx1, inx2 = p.twoSum(nums, target) 
        self.assertEqual(nums[inx1-1]+nums[inx2-1], target, msg="must be equal")
        
    def testFail(self):
        p = sum.sumsolution()
        nums = [2, 7, 11, 15]
        target = 10;
        inx1, inx2 = p.twoSum(nums, target)
        self.assertEqual(inx1, -1)
        self.assertEqual(inx2, -1)

    def testZero(self):
        p = sum.sumsolution()
        nums = []
        target = 10;
        inx1, inx2 = p.twoSum(nums, target) 
        self.assertEqual(inx1, -1)
        self.assertEqual(inx2, -1)
              
    def testRandom(self):
        count = 0
        p = sum.sumsolution()
        for i in range(0, 10):
            with self.subTest(i=i):
                nums = [random.randint(-20,20) for _ in range(10)]
                target = random.randint(5,10);
                inx1, inx2 = p.twoSum(nums, target) 
                if(inx1 == -1 and inx2 == -1):
                    continue
                
                #print (nums)
                #print (inx1, inx2, target)
                self.assertEqual(nums[inx1-1]+nums[inx2-1], target, msg="must be equal")
                count = count+1
        print (count, i)

if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()