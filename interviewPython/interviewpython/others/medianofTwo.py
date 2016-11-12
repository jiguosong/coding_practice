class medianofTwo(object):
    def findmedianofTwo(self, a, b):
        if (len(a) == 0 or len(b) == 0):
            return
        
        al = 0
        ah = len(a)-1
        bl = 0
        bh = len(b)-1        
        
        while(al <= ah and bl <= bh):
            am = al + (ah-al)/2
            bm = bl + (bh-bl)/2   
            print(al, ah, am)
            print(bl, bh, bm)
            print(a[am])
            print(b[bm])
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

if __name__=="__main__":
    print("PY:mediantwo")
    solu = medianofTwo()
    a = [1,2,3, 4, 5, 7, 8, 100]
    b = [3,4]
    result = solu.findmedianofTwo(a, b)
    print(result)