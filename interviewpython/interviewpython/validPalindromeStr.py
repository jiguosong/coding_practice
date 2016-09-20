import string
import re

class validPalindromeStr(object):
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

if __name__=="__main__":
    solu = validPalindromeStr()
    if (solu.isvalidPalindromeStr("A man, a plan, a canal: Panama")):
        print("yes")
    else:
        print("no")