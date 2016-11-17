
import math

class solution(object):
    # @return a list of spiral matrix elements
    def spiralOrder(self, matrix):
        res = []
        m = len(matrix)
        if m == 0:
            return res
        n = len(matrix[0])
        if n == 0:
            return res
    
        round = math.floor((min(m,n) + 1)/2)
        for offset in range(0, round):
            for idx in range(offset, n-offset):
                res.append(matrix[offset][idx])
            for idx in range(offset+1, m-offset-1):
                res.append(matrix[idx][n-offset-1])
            if m - 2*offset > 1:
                for idx in range(n-offset-1, offset-1, -1):
                    res.append(matrix[m-offset-1][idx])
            if n - 2*offset > 1:
                for idx in range(m-offset-2, offset, -1):
                    res.append(matrix[idx][offset])
                
        return res
        
    
    # @return a list of lists of integer (nxn matrix)    
    def generateMatrix(self, n):
        if n <= 0:
           return [] 
        m = n
        count = 1
        matrix = [[0 for x in range(0,n)] for y in range(0, m)]
        round = math.floor((n+1)/2)
        for offset in range(0, round):
            for idx in range(offset, n-offset):
                matrix[offset][idx] = count
                count += 1
            for idx in range(offset+1, m-offset-1):
                matrix[idx][n-offset-1] = count
                count += 1
            if m - 2*offset > 1:
                for idx in range(n-offset-1, offset-1, -1):
                    matrix[m-offset-1][idx] = count
                    count += 1
            if n - 2*offset > 1:
                for idx in range(m-offset-2, offset, -1):
                    matrix[idx][offset] = count
                    count += 1            
            
        return matrix
            
            
            