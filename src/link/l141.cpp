//
// Created by pairs on 12/29/19.
//
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode *f = head;
        ListNode *s = head;
        while (s->next != nullptr && s->next->next != nullptr) {
            f = f->next;
            s = s->next->next;
            if (f == s) {
                return true;
            }
        }
        return false;
    }
};

int main() {

}