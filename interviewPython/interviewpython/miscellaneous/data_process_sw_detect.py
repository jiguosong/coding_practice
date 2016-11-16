import sys
if sys.version_info[0] < 3:
    raise "Must be using Python 3"
else:
    print(sys.version_info)
    print()
    
try:
    import numpy
except ImportError:
    print ("numpy is not installed")
else:
    print ("numpy is installed")
    
try:
    import pandas
except ImportError:
    print ("pandas is not installed")
else:
    print ("pandas is installed")

try:
    import scipy
except ImportError:
    print ("scipy is not installed")
else:
    print ("scipy is installed")
    
try:
    import mrjob
except ImportError:
    print ("mrjob is not installed")
else:
    print ("mrjob is installed")
 
try:
    import natsort
except ImportError:
    print ("natsort is not installed")
else:
    print ("natsort is installed")
 
try:
    import tinydb
except ImportError:
    print ("tinydb is not installed")
else:
    print ("tinydb is installed")
 
try:
    import vincent
except ImportError:
    print ("vincent is not installed")
else:
    print ("vincent is installed")
 
try:
    import sklearn
except ImportError:
    print ("sklearn is not installed")
else:
    print ("sklearn is installed")
 