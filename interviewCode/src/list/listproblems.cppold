/*
 * listproblems.cpp
 *
 *  Created on: Nov 6, 2016
 *      Author: songjiguo
 */

#include <iostream>
#include <algorithm>
#include "Node.cpp"

using namespace std;

class listproblem {
public:
	virtual void run() = 0;
	virtual ~listproblem(){};
};

/* reverse_list */
class reverse_list : public listproblem {
public:
	void run() override
	{
		cout << "reverse_list\n";
		ListNode<int> *head;
		head = GetNode(1,GetNode(8,GetNode(3, GetNode(4, GetNode(5, GetNode(6))))));
		ListNode<int>* res = reverseList(head);

		res->print_list();
	}

	static reverse_list &instance()
	{
		static reverse_list *p = new reverse_list;
		return *p;
	}

	virtual ~reverse_list(){};
private:
	reverse_list(){};
	reverse_list(const reverse_list &other);
	const reverse_list &operator=(const reverse_list &other);

	ListNode<int>* reverseList(ListNode<int>* head);
};

ListNode<int>* reverse_list::reverseList(ListNode<int>* head)
{
	head->print_list();
	ListNode<int> *prev = NULL;
	ListNode<int> *next = NULL;
	ListNode<int> *curr = head;

	while(curr) {
		next =curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head = prev;
	return head;
}

/* reverse_list2 */

class reverse_list2 : public listproblem {
public:
	void run() override {
		cout << "reverse_list2 from 2 to 4\n";
		ListNode<int> *head;
		head = GetNode(1,GetNode(2,GetNode(3, GetNode(4, GetNode(5, GetNode(6))))));
		int m = 1;
		int n = 4;
		head->print_list();
		ListNode<int> *res = reverseBetween(head, m, n);
		res->print_list();
	}

	~reverse_list2(){};

	static reverse_list2 &instance() {
		static reverse_list2 *p = new reverse_list2;
		return *p;
	}

	ListNode<int> *reverseBetween(ListNode<int> *head, int m, int n);

private:
	reverse_list2(){};
	reverse_list2(const reverse_list2 &other) = delete;
	const reverse_list2 &operator=(const reverse_list2 &other) = delete;
};


ListNode<int> * reverse_list2::reverseBetween(ListNode<int> *head, int m, int n)
{
	if(!head || m >= n) return NULL;

	ListNode<int> *start = head;
	ListNode<int> *before_start = NULL;
	for(int i = 1; i < m; i++) {
		before_start = start;
		start = start->next;
		if(!start) return NULL;
	}

	ListNode<int> *prev = before_start;
	ListNode<int> *curr = start;
	ListNode<int> *next;
	for(int i = m; i <= n; i++) {
		if(!curr) break;
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	if(!before_start) head = prev;
	else before_start->next = prev;

	start->next = curr;

	return head;
}


/* partition_list */

class partition_list : public listproblem {
public:
	void run() override {
		cout << "partition_list by x value 3\n";
		ListNode<int> * head;
		head = GetNode(1,GetNode(4,GetNode(3, GetNode(2, GetNode(5, GetNode(2))))));
		int x = 3;
		head->print_list();
		ListNode<int> *res = partition(head, x);
		res->print_list();
	}

	static partition_list &instance(){
		static partition_list *p = new partition_list;
		return *p;
	}

	~partition_list(){};
private:
	partition_list(){};
	partition_list(const partition_list &other) = delete;
	const partition_list &operator=(const partition_list &other) = delete;
	ListNode<int> *partition(ListNode<int> *head, int x);
};

ListNode<int> * partition_list::partition(ListNode<int> *head, int x)
{
	ListNode<int> *dummy = new ListNode<int>(-1);
	dummy->next = head;
	ListNode<int> *pre = dummy, *cur = head;;
	while (pre->next && pre->next->data < x) pre = pre->next;
	cur = pre;
	while (cur->next) {
		if (cur->next->data < x) {
			ListNode<int> *tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = pre->next;
			pre->next = tmp;
			pre = pre->next;
		} else {
			cur = cur->next;
		}
	}
	return dummy->next;
}

/*reorder list*/
class reorder_list : public listproblem {
public:
	void run() override {
		cout << "reorder a list\n";
		ListNode<int> * head;
		head = GetNode(1,GetNode(4,GetNode(3, GetNode(2, GetNode(5, GetNode(2))))));
		head->print_list();
		reorderList(head);
		head->print_list();
	}

	static reorder_list &instance() {
		static reorder_list *p = new reorder_list;
		return *p;
	}

	~reorder_list(){};
private:
	reorder_list(){};
	reorder_list(const reorder_list &other) = delete;
	const reorder_list &operator=(const reorder_list &other) = delete;
	void reorderList(ListNode<int> *head);
};

void reorder_list::reorderList(ListNode<int> *head)
{
	if(!head) return;
	ListNode<int> *slow = head;
	ListNode<int> *fast = head;

	int mid = 0;
	while(fast && fast->next) {
		++mid;
		slow = slow->next;
		fast = fast->next->next;
	}

	reverse_list2 &t = reverse_list2::instance();
	t.reverseBetween(head, 1, mid);
	head->print_list();

	// TODO: finish this later
}



class list_solution_factory {
public:
	static listproblem *list_solution(const string &name)
	{
		if(name == "reverse list") {
			listproblem &p = reverse_list::instance();
			return &p;
		}

		if(name == "reverse list from m to n") {
			listproblem &p = reverse_list2::instance();
			return &p;
		}

		if(name == "partition a list by value") {
			listproblem &p = partition_list::instance();
			return &p;
		}

		if(name == "reorder a list") {
			listproblem &p = reorder_list::instance();
			return &p;
		}
		return NULL;
	}
};


int main(int argc, char **argv) {
	list_solution_factory solution_list;
	solution_list.list_solution("reverse list")->run();
	solution_list.list_solution("reverse list from m to n")->run();
	solution_list.list_solution("partition a list by value")->run();
	solution_list.list_solution("reorder a list")->run();
}
