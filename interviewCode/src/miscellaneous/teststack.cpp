/*
 * stack.cpp
 *
 *  Created on: Oct 31, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>
#include <assert.h>

class LinkedListIterator;
class LinkedList;

class Node {
	friend LinkedList;
	friend LinkedListIterator;
	Node *next_;
	int val_;
};

// goal: for(Node p = list.head; p != null; p++)....
class LinkedListIterator {
public:
	bool operator== (LinkedListIterator i) const;
	bool operator!= (LinkedListIterator i) const;
	void operator++ ();
	int& operator* ();
private:
	LinkedListIterator(Node* p);
	Node* p_;
	friend LinkedList;
};

class LinkedList {
public:
	void append(int val);
	void prepend(int val);
	LinkedListIterator begin();
	LinkedListIterator end();
private:
	Node* first_;
};

inline bool LinkedListIterator::operator== (LinkedListIterator i) const {
	return p_ == i.p_;
}

inline bool LinkedListIterator::operator!= (LinkedListIterator i) const {
	return p_ != i.p_;
}

inline void LinkedListIterator::operator ++() {
	assert(p_ != NULL);
	p_ = p_->next_;
}

inline int& LinkedListIterator::operator *() {
	assert(p_ != NULL);
	return p_->val_;
}

LinkedListIterator::LinkedListIterator(Node* p) : p_(p) {}

LinkedListIterator LinkedList::begin() {return first_;}
LinkedListIterator LinkedList::end() {return NULL;}




