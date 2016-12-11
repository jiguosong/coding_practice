'''
Created on Dec 10, 2016

@author: songjiguo
'''

import numpy as np

class poly(object):
    '''
    classdocs
    '''

    def __init__(self):
        '''
        Constructor
        '''
        ## just use to indicate what data structures we use
        self.highest_power = 15
        self.m1 = np.zeros((self.highest_power, self.highest_power), dtype=np.int32)
        self.m2 = np.zeros((self.highest_power, self.highest_power), dtype=np.int32)
        self.ans = np.zeros((self.highest_power, self.highest_power), dtype=np.int32)
        self.line1 = ""
        self.line2 = ""
        
    def pattern_match(self, str):
        sign_pos = "+"
        sign_neg = "-"
        symbol = "+"
        sign_pos = "+"

    def init_env(self):
        print("intialize data structure")
        self.map_list = dict()
        for item in self.symbol_list:
            print(item)
            self.map_list[item] = []  
     
    def getsign(self, char):
        if char == '+':
            return 1
        elif char == '-':
            return -1
        else:
            return 0
               
    def is_sign(self, char):
        if char == '+' or char == '-':
            return char
        else:
            return 0       
        
    def getnum(self, eq, k):
        ans = 0
        while(k < len(eq) and eq[k].isdigit()):
            ans = ans*10 + int(eq[k])
            k = k + 1
        return ans
        
    def parse_single_eq(self, eq):
        res = []
        tmp = {}       
        
        if eq[0] != '-':    # unify the equation
            eq = '+' + eq
        
        for i in range(0, len(eq)):    ## eq1 = "-yx8+9x3-1+y"
            char = eq[i]
            if self.is_sign(char) != 0:
                if tmp:
                    res.append(tmp)
                    tmp = {}
                #tmp.append(self.getsign(self.is_sign(char)))
                if eq[i+1].isdigit():
                    #tmp.append({"co":self.getnum(eq, i+1)*self.getsign(self.is_sign(char))})
                    tmp["co"] = self.getnum(eq, i+1)*self.getsign(self.is_sign(char))
                    i = i + 1
                else:
                    tmp["co"] = self.getsign(self.is_sign(char))
            elif char.isalpha():
                if i < len(eq)-1 and eq[i+1].isdigit():
                    tmp[char] = self.getnum(eq, i+1)
                    i = i + 1
                else:
                    tmp[char] = 1
        
        res.append(tmp)
        return res

    def parse_expression(self, eq_list):
       
        res = []
        for eq in eq_list:
            res.append(self.parse_single_eq(eq))        
        return res
     
    def fill_matrix(self, eq, matrix): 
        for e in eq:
            if 'x' in e and 'y' in e:
                matrix[e['x']][e['y']] = e['co']
            elif 'x' in e and 'y' not in e:
                matrix[e['x']][0] = e['co']
            elif 'x' not in e and 'y' in e:
                matrix[0][e['y']] = e['co']
            else:
                matrix[0][0] = e['co']
    
    def do_computation(self, parsed_eq):  
        #print (parsed_eq[0])
        #print (parsed_eq[1])
        
        # fill the matrix m1 and m2
        #self.fill_matrix(parsed_eq[0], self.m1)
        #self.fill_matrix(parsed_eq[1], self.m2)
       
        # fill the ans matrix
        for ai in parsed_eq[0]:   # TODO: oiverride operator
            for bi in parsed_eq[1]:
#                 print(ai)
#                 print(bi)
                new_val   = ai['co']*bi['co']
                t1 = ai['x'] if 'x' in ai else 0;
                t2 = bi['x'] if 'x' in bi else 0;
                new_x_idx = t1 + t2
                t1 = ai['y'] if 'y' in ai else 0;
                t2 = bi['y'] if 'y' in bi else 0;
                new_y_idx = t1 + t2
#                 print(new_x_idx)
#                 print(new_y_idx)
#                 print(new_val)
                
                self.ans[new_x_idx][new_y_idx] += new_val

    def print_output(self, stack_power, stack_symbol):
        
        print (stack_power)
        print (stack_symbol)
        
    def final_result(self):
        # walk through the matrix according to the specifications
        # for example, x is decreasing order and y is increasing order for the same x
        #print(self.ans)
        (m, n) = self.ans.shape
              
        # use 2 stacks for formatted print out
        stack_power = []     # for power of x, y
        stack_symbol = []     # for x, y and coefficient
        for row in range(0, m):
             for col in range(n, 0, -1):
                 v = self.ans[row-1][col-1]
                 if(v != 0):
                    # y power
                    k = col-1
                    digits = 0
                    while(k):
                        stack_power.append(k%10)
                        k = k//10
                        digits += 1
                    if digits > 0:
                        stack_power.append(digits)
                    
                    # x power
                    k = row-1
                    digits = 0
                    while(k):
                        stack_power.append(k%10)
                        k = k//10
                        digits += 1
                    if digits > 0:
                        stack_power.append(digits)
                    
                    # y
                    if col-1 != 0:
                        stack_symbol.append('y')
                    else:
                        stack_symbol.append('y#')
                    
                    # x
                    if row-1 != 0:
                        stack_symbol.append('x')
                    else:
                        stack_symbol.append('x#')
                  
                    # absolute coefficient
                    if ((col-1 == 0 and row-1 == 0) or abs(v) != 1):
                        k = abs(v)
                        digits = 0
                        if (k == 1):
                            stack_symbol.append(str(k))
                        else:    # k > 1
                            while(k):
                                stack_symbol.append(str(k%10))
                                k = k//10
                                digits += 1
                    else:
                        stack_symbol.append("v#")
                        
                    # sign
                    if v < 0:
                        sign = " - "
                    else:
                        sign = " + "
                    stack_symbol.append(sign)
        
        self.print_output(stack_power, stack_symbol)
        
    def product(self, equation1, equation2):
        eq_list = [equation1, equation2]
             
        self.do_computation(self.parse_expression(eq_list))
        
if __name__ == '__main__':
    
    eq1 = "-yx8+9x3-1+y"
    eq2 = "x5y+1+x3"
    x = poly()
    print (eq1)
        
    x.product(eq1, eq2)  
    x.final_result()
    

    print (x.line1)
    print (x.line2)
#     
#     eq1 = "12"
#     eq2 = "12"
#     x = poly()
#     x.product(eq1, eq2)  
#     x.final_result()
#     
#     print (x.line1)
#     print (x.line2)
