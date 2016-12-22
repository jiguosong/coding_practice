import math

class solution(object):
	def isPalindromenumber(self, num):
		k = 0
		p = num
		
		while(p != 0):
			k = k*10 + p%10;
			p = math.floor(p/10);
		
		return (k == num)
	
# if __name__=="__main__":
# 	print("PY:isPalindromenumber")	
# 	solu = solution()
# 	num = 121
# 	if (solu.isPalindromenumber(num)):
# 		print("yes")
# 	else:
# 		print("not")