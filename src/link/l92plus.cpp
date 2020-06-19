//
// Created by pairs on 12/29/19.
//
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode *first = head;
	for (int i = 1; i < m-1; i++) {
	    first = first->next;
	}
	cout << "first: " << first->val << endl;
	ListNode *left = first->next;
	cout << "left: " << left->val << endl;

	ListNode *pre = nullptr;
	ListNode *current = left;
	int i = 0;
	while (current != nullptr && i<= n-m) {
	    auto next = current->next;
	    current->next = pre;
	    pre = current;
	    current = next;
	    i++;
	}
	left->next = current;
	first->next = pre;
        return head;
    }
};

int main() {
    Solution slu;
    auto n1 = new ListNode(1);
    auto n2 = new ListNode(2);
    auto n3 = new ListNode(3);
    auto n4 = new ListNode(4);
    auto n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
//    auto n1 = new ListNode(3);
//    auto n2 = new ListNode(5);
//    n1->next = n2;
    auto res = slu.reverseBetween(n1, 2, 4);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}
