from collections import deque

class Solution_add2number(object):
    def add2number(self, a ,b):
        ret = deque();
        if (a is None and b is None):
            return ret       
        if (len(a) == 0 and len(b) == 0):
            return ret
        if (a is None):
            return b
        if (b is None):
            return a
                
        sum = 0
        carry = 0
        digit = 0
        
        while (len(a) !=0 and len(b) !=0):
            sum = a.pop()+b.pop()+carry;
            digit = sum%10;
            carry = sum/10;
            ret.append(digit)
            
        if (len(a) != 0):
            ret.append(a)
        if (len(b) != 0):
            ret.append(b)
        
        return ret
    
if __name__ == '__main__':
    print("PY:add2numbers")
    solu = Solution_add2number()
    
    a = deque([2,4,3])
    b = deque([5,6,4])
    
    res = solu.add2number(a, b)
    for x in res:
        print(x)
    