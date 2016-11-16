# Factory + Singleton
# Polymorphic factory methods.
from __future__ import generators
import random

class SumFactory:
    factories = {}
    # A Template Method:
    def createSumSolution(name):
        if not name in SumFactory.factories:
            SumFactory.factories[name] = eval(name)
        return SumFactory.factories[name].getInstance()
    createSumSolution = staticmethod(createSumSolution)

class Sum(object): pass

class TwoSum(Sum):
    def run(self): 
        nums = [2, 7, 11, 15]
        target = 17
        inx1, inx2 = twoSum(self, nums, target)
        print('index1 = ', inx1, ', index2 = ', inx2)
        
    _twosum = None
    def getInstance(cls):
        if not isinstance(cls._twosum, cls):
            cls._twosum = cls()
        return cls._twosum

    getInstance = classmethod(getInstance)        


def twoSum(self, nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    map = dict()
    size = len(nums)
    for i in range(size):
        map[nums[i]] = i
    for i in range(size):
        inx1 = i
        inx2 = map.get(target - nums[inx1])
        if inx2 and inx2 != inx1:
            return inx1 + 1, inx2 + 1


class ThreeSum(Sum):
    def run(self): print("ThreeSum.run")
    _threesum = None
    def getInstance(cls):
        if not isinstance(cls._threesum, cls):
            cls._threesum = cls()
        return cls._threesum

    getInstance = classmethod(getInstance)        

# def sumNameGen(n):
#     types = Sum.__subclasses__()
#     for i in range(n):
#         yield random.choice(types).__name__

if __name__ == '__main__':
    
    test = SumFactory.createSumSolution(TwoSum.__name__)
    test.run()
    
    test2 = SumFactory.createSumSolution(ThreeSum.__name__)
    test2.run()
    
    