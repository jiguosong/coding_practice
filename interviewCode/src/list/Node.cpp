/*
 * Node.cpp
 *
 *  Created on: Nov 6, 2016
 *      Author: songjiguo
 */

#include "Node.h"

template<class T>
ListNode<T>::ListNode()
{}

template<class T>
ListNode<T>::ListNode(const T& item, ListNode<T> *ptrnext)
{
	this->data = item;
	this->next = ptrnext;
}

template<class T>
ListNode<T> *ListNode<T>::NextNode()
{
	return this->next;
}

template<class T>
void ListNode<T>::print_list()
{
	ListNode<int> *tmp = this;
	while(tmp) {
		cout << tmp->data << ' ';
		tmp = tmp->NextNode();
	}
	cout << endl;
}

template<class T>
void ListNode<T>::InsertAfter(ListNode<T> *p) {
	p->next = this->next;
	this->next = p;
}

template<class T>
ListNode<T> *ListNode<T>::DeleteAfter()
{
	ListNode<T> *tmp = next;
	if(next != NULL) next = next->next;
	return tmp;
}

template<class T>
ListNode<T> * GetNode(const T& item, ListNode<T>* nextptr = NULL)
{
	ListNode<T>* newnode; // Local ptr for new node
    newnode = new ListNode<T>(item, nextptr);
    if (newnode == NULL)
    {
        cerr << "Memory allocation failed." << endl;
        exit(1);
    }
    return newnode;
}

