class longestPalindrome(object):
    def findLongestPalindrome(self, s):
        """
        :type s:string
        :rtype string
        """
        if (len(s) == 0 or len(s) == 1):
            return s
        maxlen = [1]
        ret = [1]
        if (s[0] == s[1]):
            maxlen[0] = 2
            ret[0] = s[0:1]
        
        for i in range(1,len(s)):
            self.check(s, i-1, i+1, maxlen, ret)
            if (i < len(s) - 1 and s[i] == s[i+1]):
                self.check(s, i-1, i+2, maxlen, ret)

        return ret[0]
    
    def check(self, s, j, k , maxlen, ret):
        while(j >=0 and k < len(s) and s[j] == s[k]):
            j = j - 1
            k = k + 1 
        tmp_len = k - j + 1 -2
        if (tmp_len > maxlen[0]):
            maxlen[0] = tmp_len
            ret[0] = s[j+1:k]
    
    
if __name__=="__main__":
    print("PY:longestPalindrome")    
    solu = longestPalindrome()
    res = solu.findLongestPalindrome("bananas")
    print(res)