'''
Created on Dec 11, 2016

@author: songjiguo
'''
import unittest
import poly

class Test(unittest.TestCase):
    
    def testCase1_3d(self):
        eq1 = "xyz+y+z"
        eq2 = "2y4+3y-z"
        print ("Test Case 1 << Input >>")
        print(eq1)
        print(eq2)
 
        x = poly.poly_multi()
        x.product(eq1, eq2)  
 
        print("<< Output >>")         
        print (x.power_line)
        print (x.symbol_line)
 
        expected_line1 = "    2      2       5     2           2     4      5"
        expected_line2 = "-xyz  + 3xy z + 2xy z - z  + 2yz + 3y  + 2y z + 2y "
        self.assertEqual(x.power_line, expected_line1, "must be equal")
        self.assertEqual(x.symbol_line, expected_line2, "must be equal")
        print()    
 
    def testCase1_normal(self):
        eq1 = "-yx8+9x3-1+y"
        eq2 = "x5y+1+x3"
        print ("Test Case 2 << Input >>")        
        print(eq1)
        print(eq2)
         
        x = poly.poly_multi()
        x.product(eq1, eq2) 
         
        print("<< Output >>")   
        print (x.power_line)
        print (x.symbol_line)
         
         
        expected_line1 = "  13 2    11      8      6    5     5 2     3    3         "
        expected_line2 = "-x  y  - x  y + 8x y + 9x  - x y + x y  + 8x  + x y - 1 + y"
        self.assertEqual(x.power_line, expected_line1, "must be equal")
        self.assertEqual(x.symbol_line, expected_line2, "must be equal")
        print()
          
    def testCase1_overflow(self):
        eq1 = "-yx8+9x323238473289476529837465928344975-19845+y"
        eq2 = "x52340975y+11293874+3294875x3"
        print ("Test Case 3 << Input >>")
        print(eq1)
        print(eq2)
 
        x = poly.poly_multi()
        x.product(eq1, eq2)  
 
        print("<< Output >>")         
        print (x.power_line)
        print (x.symbol_line)  
         
         
        expected_line1 = "  323238473289476529837465980685950             323238473289476529837465928344978             323238473289476529837465928344975    52340983 2         52340975     52340975 2           11             8                3           3                            "
        expected_line2 = "9x                                 y + 29653875x                                  + 101644866x                                  - x        y  - 19845x        y + x        y  - 3294875x  y - 11293874x y - 65386794375x  + 3294875x y - 224126929530 + 11293874y"
        self.assertEqual(x.power_line, expected_line1, "must be equal")
        self.assertEqual(x.symbol_line, expected_line2, "must be equal")
        print()
   
   
    def testCase2_cancel(self):
        eq1 = "-yx8+x3-1+y"
        eq2 = "x5y+1+x3"
        print ("Test Case 4 << Input >>")
        print(eq1)
        print(eq2)
 
        x = poly.poly_multi()
        x.product(eq1, eq2)  
 
        print("<< Output >>")         
        print (x.power_line)
        print (x.symbol_line)  
         
        expected_line1 = "  13 2    11     6    5     5 2    3         "
        expected_line2 = "-x  y  - x  y + x  - x y + x y  + x y - 1 + y"
        self.assertEqual(x.power_line, expected_line1, "must be equal")
        self.assertEqual(x.symbol_line, expected_line2, "must be equal")
        print()
  
    def testCase3_largeindex(self):
        eq1 = "-yx888+x3-1+y2+32x19"
        eq2 = "x5y887+1+x320"
        print ("Test Case 5 << Input >>")
        print(eq1)
        print(eq2)
 
        x = poly.poly_multi()
        x.product(eq1, eq2)  
 
        print("<< Output >>")         
        print (x.power_line)
        print (x.symbol_line)  
         
        expected_line1 = "  1208     893 888    888       339    323    320    320 2      24 887      19    8 887    5 887    5 889    3        2"
        expected_line2 = "-x    y - x   y    - x   y + 32x    + x    - x    + x   y  + 32x  y    + 32x   + x y    - x y    + x y    + x  - 1 + y "
        self.assertEqual(x.power_line, expected_line1, "must be equal")
        self.assertEqual(x.symbol_line, expected_line2, "must be equal")
        print()
#                  
    def testCase_const(self):
        eq1 = "1"
        eq2 = "1"
        print ("Test Case 6 << Input >>")
        print(eq1)
        print(eq2)
 
        x = poly.poly_multi()
        x.product(eq1, eq2)  
 
        print("<< Output >>")         
        print (x.power_line)
        print (x.symbol_line) 
                
        expected_line1 = ''
        expected_line2 = "1"           
        self.assertEqual(x.power_line, ' ', "must be equal")
        self.assertEqual(x.symbol_line, expected_line2, "must be equal")
       
    def testCase_zero(self):
        eq1 = "-yx888+x3-1+y2+32x19"
        eq2 = "0"
        print ("Test Case 7 << Input >>")
        print(eq1)
        print(eq2)

        x = poly.poly_multi()
        x.product(eq1, eq2)  

        print("<< Output >>")         
        print (x.power_line)
        print (x.symbol_line)  
                
        expected_line1 = ""
        expected_line2 = "0" 
        self.assertEqual(x.power_line, expected_line1, "must be equal")
        self.assertEqual(x.symbol_line, expected_line2, "must be equal")
        print()
          
    def testCase_multiplyone(self):
        
        eq1 = "-yx888+x3-1+y2+32x19"
        eq2 = "1"
        
        print ("Test Case 8 << Input >>")
        print(eq1)
        print(eq2)
 
        x = poly.poly_multi()
        x.product(eq1, eq2)  
 
        print("<< Output >>")         
        print (x.power_line)
        print (x.symbol_line)         
          
        expected_line1 = "  888       19    3        2"
        expected_line2 = "-x   y + 32x   + x  - 1 + y " 
        self.assertEqual(x.power_line, expected_line1, "must be equal")
        self.assertEqual(x.symbol_line, expected_line2, "must be equal")
        print()  
        
    def testCase_4d(self):
        
        eq1 = "-yxt+xz-1+43t2y2+32x19"
        eq2 = "x5y+1+x3"
        
        print ("Test Case 9 << Input >>")
        print(eq1)
        print(eq2)
 
        x = poly.poly_multi()
        x.product(eq1, eq2)  
 
        print("<< Output >>")         
        print (x.power_line)
        print (x.symbol_line)         
          
        expected_line1 = "   24       22      19    6       6 2    5       2 5 3    4      4     3      2 3 2                     2 2"
        expected_line2 = "32x  y + 32x   + 32x   + x yz - tx y  - x y + 43t x y  + x z - tx y - x  + 43t x y  + xz - txy - 1 + 43t y " 
        self.assertEqual(x.power_line, expected_line1, "must be equal")
        self.assertEqual(x.symbol_line, expected_line2, "must be equal")
        print()   
                 
if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()