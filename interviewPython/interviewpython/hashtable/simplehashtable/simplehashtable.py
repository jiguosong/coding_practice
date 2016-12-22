'''
Created on Dec 21, 2016

@author: songjiguo
'''

class HashTable(object):
    '''Rudimentary implemnation of the CPython dictionary object in pure python.

    Supports a relatively dictionary-like API, except its worse in every way!
    The one thing this may do is give you some nice analogies for the CPython
    implementation without having to dig through the source.

    >>> foo = HashTable(bar="baz", boo="doh")
    >>> foo.get("bar")
    "baz"
    >>> foo["addtl"] = "things"
    >>> assert len(foo) == 3
    >>> del foo["addtl"]
    >>> assert len(foo) == 2
    '''

    TOMBSTONE = '<Tombstone>'
    MINSIZE = 8

    def __init__(self, **initial_values):
        self._buckets = [None] * self.MINSIZE

        for k, v in initial_values.items():
            self.insert(k, v)

    def get(self, key):
        ''' Simple getter method to retrieve buckets by key '''

        h = hash(key)
        idx = h & self.mask

        # Do a naive probe, if the bucket at idx is existant but NOT
        # the correct key, use locate to probe randomly.
        bucket = self._buckets[idx]
        if bucket and bucket[1] != key:
            idx = self._locate(key, h)

        return self._buckets[idx][2] if self._buckets[idx] else None

    def insert(self, key, value):
        ''' Simple insert method to insert buckets by key '''

        # If the buckets seem over-utilized, grow and re-index
        if self.utilization >= 0.75:
            self._resize(len(self._buckets) * 4)

        h = hash(key)
        idx = h & self.mask

        # If the initial probe returned a bucket, probe randomly
        # for the next available slot.
        if self._buckets[idx]:
            idx = self._locate(key, h)

        self._buckets[idx] = (h, key, value)

    def delete(self, key):
        ''' Simple delete method to delete buckets by key '''

        h = hash(key)
        idx = h & self.mask

        bucket = self._buckets[idx]
        if bucket and bucket[1] != key:
            idx = self._locate(key, h)

        self._buckets[idx] = self.TOMBSTONE

        # If the buckets seem under-utilized, shrink and re-index
        if 0 < self.utilization <= 0.16 and len(self._buckets) > self.MINSIZE:
            self._resize(len(self._buckets) / 4)

    def _locate(self, key, h):
        ''' Very basic implementation of the CPython lookdict method. This is where
        the magic happens.

        The algoritm itself is described in much greater detail at:
            https://hg.python.org/cpython/file/52f68c95e025/Objects/dictobject.c#l97
        '''

        idx = h & self.mask
        bucket = self._buckets[idx]

        perturb = h
        for _ in range(0, self.mask):
            idx = ((idx >> 2) + idx + perturb + 1) & self.mask
            bucket = self._buckets[idx]

            if not bucket or bucket[1] == key:
                return idx

            perturb >>= 5  # per the cpython impl, 5 is the optimal shift
        raise Exception("something went wrong with {} {}".format(key, idx))

    def _resize(self, size):
        '''Allow the buckets list to be grown or shrunk to a passed size.

        This method recreates the buckets list and reinserts all old records
        at their computed hashes. Also cleans up Tombstones in the process.
        '''

        old_buckets = self._buckets
        self._buckets = [None] * int(size)

        # Make sure the old data gets re-indexed into the new store
        for bucket in [b for b in old_buckets if b and b != self.TOMBSTONE]:
            self.insert(bucket[1], bucket[2])

    @property
    def mask(self):
        '''The length of the buckets list is also applied as the bit mask to hash
        for item indexing.'''

        return len(self._buckets) - 1

    @property
    def utilization(self):
        '''Calculate the number of buckets that are populated or tombstoned'''
        try:
            return float(len(self)) / float(len(self._buckets))
        except ZeroDivisionError:
            return 0

    def __len__(self):
        '''Len should return the number of non-tombstoned and populated records'''
        return len([b for b in self._buckets if b and b != self.TOMBSTONE])

    def __setitem__(self, key, val):
        self.insert(key, val)

    def __getitem__(self, key):
        val = self.get(key)
        if val:
            return val
        else:
            raise KeyError

    def __delitem__(self, key):
        self.delete(key)
