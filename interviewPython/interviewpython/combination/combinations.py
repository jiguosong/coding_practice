class Solution_combination(object):
    def combine(self, n, k):
        res = []
        if (n == 0 or k > n):
            return res
        tmp = []
        self.combine_helper(n, k, 1, tmp, res)
        return res
    
    def combine_helper(self, n, k, level, tmp, res):
        if (len(tmp) == k):
            res.append(tmp[:])  # this is important!!!            
            return
        for i in range(level,n+1):
            tmp.append(i)
            self.combine_helper(n, k, i+1, tmp, res)
            tmp.pop()        
        return
    
if __name__ == "__main__":
    print("PY:combination")
    solu = Solution_combination()
    result = solu.combine(4,2)
    print(result) 