/*
 * add2number.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: songjiguo
 */

using namespace std;

#include <iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
};

class add2number {
public:
	add2number();
	virtual ~add2number();

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	 if (!l1 && !l2) return nullptr;
	 if (l1 && !l2) return l1;
	 if (l2 && !l1) return l2;

	 int sum, digit, carry;
	 carry = 0;
	 ListNode *head = nullptr;
	 ListNode *curr = head;

	 ListNode *p1, *p2;
	 p1 = l1;
	 p2 = l2;

	 while (p1 && p2) {
		 sum = p1->val + p2->val;
		 digit = sum%10 + carry;
		 carry = sum/10;
		 ListNode *tmp = new ListNode(digit);
		 if (!head) {
			 head = tmp;
			 curr = tmp;
		 }  else {
			 curr->next = tmp;
			 curr = curr->next;
		 }
		 p1 = p1->next;
		 p2 = p2->next;
	 }

	 if (p1) curr->next = p1;
	 if (p2) curr->next = p2;

	 return head;
}

int main() {

	cout << "this is another test";
	cout << "CPP:add2nums" << endl;
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	ListNode *tmp = addTwoNumbers(l1, l2);
	while(tmp) {
		cout << tmp->val << endl;
		tmp = tmp->next;
	}

	return 0;
}

