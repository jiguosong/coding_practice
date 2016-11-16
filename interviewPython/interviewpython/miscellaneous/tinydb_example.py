'''
Created on Nov 15, 2016

@author: songjiguo
'''

from tinydb import TinyDB, Query

db = TinyDB('data/db.json')
db.insert({'type': 'apple', 'count': 7})
db.insert({'type': 'peach', 'count': 3})

#print (db.all())

Fruit = Query()
print (db.search(Fruit.type == 'peach'))
print (db.search(Fruit.count > 5))
