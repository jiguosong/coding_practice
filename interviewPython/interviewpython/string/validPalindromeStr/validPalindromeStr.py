import string
import re

class solution(object):
    def isvalidPalindromeStr(self, s):
        if (len(s) == 0):
            return True

        res = []
        x = ""
        for x in s:
            tmp = x.lower()
            if (tmp.isalnum()):
                res.append(tmp)
        
        return (res == res[::-1])
