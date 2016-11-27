class solution(object):
    def findLongestNonrepSubstr(self, s):
        if (len(s) == 0):
            return 0
        map = [0]*255;
        left = 0
        ret = 0

        for i in range(0, len(s)):
            idx = ord(s[i]);
            if (map[idx] == 0 or map[idx] < left):
                ret = max(ret, i - left + 1)
            else:
                left = map[idx]
            map[idx] = i + 1
        
        return ret
