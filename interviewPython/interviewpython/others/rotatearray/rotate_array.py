
class rotateArray_solution(object):
    def rotateArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        """
        n = len(nums)
        if (n == 0 or k == 0):
            return
        self.reverse(nums, 0, n-k-1)
        self.reverse(nums, n-k, n-1)
        self.reverse(nums, 0, n-1)
        
    def reverse(self, nums, l, r):
        while(l < r):
            tmp     = nums[l]
            nums[l] = nums[r]
            nums[r] = tmp
            l = l + 1
            r = r - 1
