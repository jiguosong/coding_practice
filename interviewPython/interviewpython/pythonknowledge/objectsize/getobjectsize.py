'''
Created on Dec 21, 2016

@author: songjiguo
'''

# Bytes  type        empty + scaling notes
# 24     int         NA
# 28     long        NA
# 37     str         + 1 byte per additional character
# 52     unicode     + 4 bytes per additional character
# 56     tuple       + 8 bytes per additional item
# 72     list        + 32 for first, 8 for each additional
# 232    set         sixth item increases to 744; 22nd, 2280; 86th, 8424
# 280    dict        sixth item increases to 1048; 22nd, 3352; 86th, 12568 *
# 64     class inst  has a __dict__ attr, same scaling as dict above
# 16     __slots__   class with slots has no dict, seems to store in 
#                    mutable tuple-like structure.
# 120    func def    doesn't include default args and other attrs
# 904    class def   has a proxy __dict__ structure for class attrs
# 104    old class   makes sense, less stuff, has real dict though.

import sys
from numbers import Number
from collections import Set, Mapping, deque

try: # Python 2
    zero_depth_bases = (basestring, Number, xrange, bytearray)
    iteritems = 'iteritems'
except NameError: # Python 3
    zero_depth_bases = (str, bytes, Number, range, bytearray)
    iteritems = 'items'

def getsize(obj_0):
    """Recursively iterate to sum size of object & members."""
    def inner(obj, _seen_ids = set()):
        obj_id = id(obj)
        if obj_id in _seen_ids:
            return 0
        _seen_ids.add(obj_id)
        size = sys.getsizeof(obj)
        if isinstance(obj, zero_depth_bases):
            pass # bypass remaining control flow and return
        elif isinstance(obj, (tuple, list, Set, deque)):
            size += sum(inner(i) for i in obj)
        elif isinstance(obj, Mapping) or hasattr(obj, iteritems):
            size += sum(inner(k) + inner(v) for k, v in getattr(obj, iteritems)())
        # Check for custom object instances - may subclass above too
        if hasattr(obj, '__dict__'):
            size += inner(vars(obj))
        if hasattr(obj, '__slots__'): # can have __slots__ with __dict__
            size += sum(inner(getattr(obj, s)) for s in obj.__slots__ if hasattr(obj, s))
        return size
    return inner(obj_0)

if __name__ == '__main__':
    print(getsize({'foo': 'bar', 'baz': 'bar'}))
    print(getsize(2))