#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
	if (head->next == nullptr) {
	    return head;
	}        
	auto child = reverseList(head->next);
	auto p = child;
	while (p->next != nullptr) {
	    p = p->next;
	}
	p->next = head;
	head->next = nullptr;
	return child;
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
    auto r = slu.reverseList(n1);
    while (r != nullptr) {
	cout << r->val << " ";
	r = r->next;
    }
}

