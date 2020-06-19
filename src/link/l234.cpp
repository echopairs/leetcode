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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode *f = head;
        ListNode *s = head;
        while (s->next != nullptr && s->next->next != nullptr) {
            f = f->next;
            s = s->next->next;
        }
        auto right = reverseList(f->next);

        while (right != nullptr) {
            if (right->val != head->val) {
                return false;
            }
            right = right->next;
            head = head->next;
        }
        return true;
    }

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

    ListNode* _reverseList(ListNode* head) {
        if (head->next == nullptr) {
            return head;
        }

        ListNode *p = head;
        while(p->next != nullptr && p->next->next != nullptr) {
            auto temp = p->next->next;
            p->next->next = p;
            p->next = nullptr;
        }
    }
};


int main() {

}