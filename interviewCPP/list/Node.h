/*
 * Node.h
 *
 *  Created on: Nov 6, 2016
 *      Author: songjiguo
 */

#ifndef LIST_NODE_H_
#define LIST_NODE_H_

#include <iostream>

using namespace std;

template <class T>
class ListNode {
public:
	ListNode();
	ListNode(const T &item, ListNode<T> *ptrnetxt = NULL);
	T data;
	// access the next node
	ListNode<T> *NextNode();
	void print_list();

	// modify methods
	void InsertAfter(ListNode<T> *p);
	ListNode<T> *DeleteAfter();
	ListNode<T> * GetNode(const T& item, ListNode<T>* nextptr = NULL);
//private:  // I do not like this to be private
	ListNode<T> *next;
};

#endif /* LIST_NODE_H_ */
