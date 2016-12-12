'''
Created on Dec 11, 2016

@author: songjiguo

poly-mltiplicatoin

Usage: 
        import poly
        eq1 = "-yx8+x3-1+y"
        eq2 = "x5y+1+x3"
        x = poly.poly_multi()
        x.product(eq1, eq2)  
 
        print("Output: ")         
        print (x.power_line)       # line1   
        print (x.symbol_line)      # line2

'''

import numpy as np
import collections

'''
Class powerListObj 

This is the class that maintains and operates on the list of {symbol:power}. 
1) hashable, iterable and indexable
2) to add a map into it, use powerListObj.add_map[k] = v
3) self.listmap -- a list of mappings of {symbol:power}. For example, [{'x':2}, {'y':3},...]
    For example "xyz+y2+z+1" has 4 powerListObj objects:
    [{'x':1}, {'y':1}, {'z':1}]
    [{'y':2}]
    [{'z':1}]
    [{'x':0}, {'y':0}, {'z':0}]    Note: for constant, all powers must be zeros
    
'''
class powerListObj(object):
    def __init__(self):
        self.listmap = {}
        self.index = 0
        
    def get_map(self):
        return self.listmap
    
    def add_map(self, k, v):
        self.listmap[k] = v
        
    def __setitem__(self, key, item):
        self.listmap[key] = item        

    def __getitem__(self, key):
        return self.listmap[key]         

    def __iter__(self):
        for x, y in self.listmap.items():
            yield x, y   
    
    def __key(self):
        return tuple(self.listmap)

    def __eq__(x, y):
        return x.__key() == y.__key()

    def __hash__(self):
        h = 5245
        for k, v in self.listmap.items():
            h = h^hash((k, v))
        return hash(h)
    
 
'''
Class poly

This is the main class that does all parsing, computation and formatting output
The main data structure:
  1) self.bigmap = {}  --> {powerListObj:coefficient}
    It maintains the mapping from the powerListObj to the coefficient 
    For example {{{'x':3}, {'y':5}, {'z':0}}: -8}  is for -8x^3y^5
    
  2) self.sort_specs   --> [('x', True), ('y',False), ('z', True), ...]
     This is the specification about in what decreasing/increasing order a symbole should be
     Note: this needs to be specified or by convention
     
  3) symbol_list  --> a list that maintain all symbols, for example ['x', 'y',...]
  
'''   
class poly_multi(object):
    '''
    classdocs: this is the interview question "The Errant Physicist" at Esgestream
    '''
    def __init__(self):
        '''
        Constructor
        '''
        # Note: update this as needed. True: increasing, False: decreasing
        # for now, I just use 4
        self.sort_specs = [('x', True), ('y',False), ('z', True), ('t', False)]
        self.symbol_set = set()  # extrct symbols here
        self.symbol_list = []
                
        # Main data structure. Example: {{{'x':3}, {'y':5}, {'z':0}}: -8}  -> -8x^3y^5 
        self.bigmap = {}   
        
        # output
        self.power_line = ""        # line 1
        self.symbol_line = ""       # line 2
           
    #####################
    # utility functions #
    #####################
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
    
    def expand_digits(self, k):
        if k == 0:
            return
        line1 = ""
        line2 = ""        
        line1 += str(k)
        while k > 0:
            k //= 10
            line2 += " "
        return [line1, line2]    
    
    ######################
    # parse the equation #
    ######################      
    def populate_symbol_set(self, char):
        if char.isalpha():
            self.symbol_set.add(char) 
     
    def parse_single_eq(self, eq):
        res = []
        tmp = {}     
        
        if eq[0] != '-':  # facilitate the computation
            eq = '+' + eq
        
        for i in range(0, len(eq)):
            char = eq[i]
            if self.is_sign(char) != 0:   # '-' or '+'
                if tmp:
                    res.append(tmp)
                    tmp = {}
                if eq[i+1].isdigit():
                    tmp["co"] = self.getnum(eq, i+1)*self.getsign(self.is_sign(char))
                else:
                    tmp["co"] = self.getsign(self.is_sign(char))
            elif char.isalpha():          # symbols like 'x', 'y'
                if i < len(eq)-1 and eq[i+1].isdigit():
                    tmp[char] = self.getnum(eq, i+1)
                else:
                    tmp[char] = 1
                self.populate_symbol_set(char)
            elif char.isdigit():
                continue
            else:
                raise ValueError('Input is invalid')
        
        res.append(tmp)
        return res

    def parse_expression(self, eq_list):       
        res = []
        for eq in eq_list:
            res.append(self.parse_single_eq(eq)) 
        return res    
    
    #######################
    # generate the output #
    #######################       
    
    # depends on the specification, see above self.sort_specs
    def sort_power(self, list, specs):        
        if not specs:
            return list        
        if specs[-1][0] not in self.symbol_set:
            return self.sort_power(list, specs[:-1])
        new_list = sorted(list, key = lambda k : k[specs[-1][0]], reverse = specs[-1][1])
        return self.sort_power(new_list, specs[:-1]) 
     
    def prepare_result(self, map):
        if not map:
            return      
          
        list = []
        for k in map:
            list.append(k)
        newlist = self.sort_power(list, self.sort_specs)  # sort the order according to the specs
        
        first_time = True
        for k in newlist:  
            if map[k] == 0:     # if the coefficient is 0, skip
                continue
            
            # local_map is list of sorted tuple. E.g. [('x', 0), ('y', 1)]
            tmp = k.get_map()
            order = {key: i for i, key in enumerate(self.symbol_list)}
            local_map = sorted(tmp.items(), key=lambda d: order[d[0]])
            
            ####  start processing...   ####          
            # sign            
            if first_time is True:   # special leading sign case
                if map[k] < 0:
                    self.power_line += " "
                    self.symbol_line += "-"
                first_time = False
            else:
                sign = '+' if map[k] > 0 else '-'
                self.power_line += "   ";
                self.symbol_line += " " + sign + " " 
                
            # coefficient or constant
            co = abs(map[k])    
            isConst = True
            for sym in local_map:
                if sym[1] != 0:
                    isConst = False
                    break                                
            if co != 0 and (co != 1 or isConst is True):
                [numinstr, bitspace] = self.expand_digits(co)
                self.symbol_line += numinstr
                self.power_line  += bitspace
                
            # symbols and power
            for sym in local_map:
                pow = sym[1]
                if pow == 0:
                    continue;
                self.symbol_line += sym[0];
                self.power_line += " "
                if pow == 1:                   # do not display the power of 1
                    continue
                [numinstr, bitspace] = self.expand_digits(pow)
                self.symbol_line += bitspace
                self.power_line  += numinstr  
                
         
    def do_computation(self, parsed_eq):
        # sort the symbol order -- x,y,z....
        self.symbol_list = list(self.symbol_set)
        self.symbol_list.sort()        

        # do multiplication 
        for ai in parsed_eq[0]:   # TODO: operator override or sparse matrix
            for bi in parsed_eq[1]:
                new_co = ai['co']*bi['co']             
                power_list = powerListObj()    # powerlist object
                for sym in self.symbol_list:
                    t1 = ai[sym] if sym in ai else 0;
                    t2 = bi[sym] if sym in bi else 0;                
                    power_list[sym] = t1+t2
                if power_list in self.bigmap:
                    self.bigmap[power_list] += ai['co']*bi['co']   
                else:
                    self.bigmap[power_list] = ai['co']*bi['co']
        
        self.prepare_result(self.bigmap)
      
        if not self.symbol_line:     # this is for case of 0
            self.symbol_line = "0"
                
    def product(self, equation1, equation2):
        eq_list = [equation1, equation2]             
        self.do_computation(self.parse_expression(eq_list))