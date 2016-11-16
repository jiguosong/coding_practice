class solution(object):
    def findPartitionpalindrome(self, s):
        res = []
        tmp = []
        if (len(s) == 0):
            return res

        self.findPartitionpalindrome_helper(s, 0, tmp, res)
        return res
    
    def findPartitionpalindrome_helper(self, s, level, tmp, res):
        if (level == len(s)):
            aa = tmp[:]  #need a new copy here
            res.append(aa)        
            return
        
        for i in range(level, len(s)):
            if (self.isPalindrome(s[level:i+1])):
                tmp.append(s[level:i+1])
                self.findPartitionpalindrome_helper(s, i+1, tmp, res)
                tmp.pop()

    def isPalindrome(self,str):
        return str==str[::-1]