class Solution(object):
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


if __name__ == '__main__':
    print("PY: sum2 test")
    solu = Solution()
    nums = [2, 7, 11, 15]
    target = 9
    inx1, inx2 = solu.twoSum(nums, target)
    print('index1 = ', inx1, ', index2 = ', inx2)
