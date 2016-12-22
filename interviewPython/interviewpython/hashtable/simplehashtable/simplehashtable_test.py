'''
Created on Dec 21, 2016

@author: songjiguo
'''
import unittest

from simplehashtable import HashTable

class Test(unittest.TestCase):

    def testName(self):
        h = HashTable(one="one", two="two", three="three", four="four", five="five",
                      six="six", seven="seven", eight="eight", nine="nine")

        print(len(h._buckets))  # 32 - buckets have grown to accomodate items
        
        # Remove a bunch of the keys
        del h['one']
        del h['two']
        del h['three']
        del h['four']
        del h['five']
        del h['six']
        del h['seven']
        del h['eight']
        
        print(len(h._buckets))  # 8 - buckets has now shrunk due to utilization
        h['ten'] = 10
        print(h.get('one'))  # None -
        print(h.get('ten'))  # 10


if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()
