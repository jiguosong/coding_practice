class Solution_permutation(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        tmp = []
        if (len(nums) == 0):
            return res
        visisted = [False]*len(nums)
        self.permutation_helper(nums, 0, visisted, tmp, res)        
        return res
    
    def permutation_helper(self, nums, level, visited, tmp, res):
        if (len(tmp) == len(nums)):
            res.append(tmp[:])
            return
        
        for i in range(0, len(nums)):
            if (visited[i] is True):
                continue;
            
            visited[i] = True
            tmp.append(nums[i])
            self.permutation_helper(nums, i+1, visited, tmp, res)
            visited[i] = False
            tmp.pop()
            
if __name__=="__main__":
    print("PY:permutation")
    solu = Solution_permutation()
    nums = [1,2,3]
    res = solu.permute(nums)

    print(res)
    
    
    