'''
Created on Dec 20, 2016

@author: songjiguo
'''

import collections

class Solution(object):
    '''
    classdocs
    '''

    def __init__(self):
        '''
        Constructor
        '''
    
    def findTheDifference(self, s, t):
        return list((collections.Counter(t) - collections.Counter(s)).keys())[0]