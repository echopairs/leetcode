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
        vector<ListNode*> help;
        ListNode *p = head;
        while(p != nullptr) {
            help.emplace_back(p);
            p = p->next;
        }
        for (int i = m, j = n; i < j;i++,j--) {
            swap(help[i-1]->val, help[j-1]->val);
        }
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