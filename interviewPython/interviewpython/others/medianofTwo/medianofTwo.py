import math

class solution(object):
    def findmedianofTwo(self, a, b):
        if (len(a) == 0 or len(b) == 0):
            return
        
        al = 0
        ah = len(a)-1
        bl = 0
        bh = len(b)-1        
        
        while(al <= ah and bl <= bh):
            am = al + math.floor((ah-al)/2)
            bm = bl + math.floor((bh-bl)/2)   
            if (al == ah and bl == bh):
                return ((float(a[am]) + float(b[bm]))/2);
            if (a[am] == b[bm]):
                return a[am]
            if (a[am] < b[bm]):       
                al = am + 1
                bh = bm 
            elif (a[am] > b[bm]):
                ah = am 
                bl = bm + 1