//
// Created by pairs on 12/29/19.
//
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA;
        ListNode *pB = headB;
        /*
        1.找到两个链表长度差n后较长的链表先走n步
        2,然后两个指针同时向前走，如果两个指针相等，则该点为交点的入口
        3.如果遍历完指针仍然不相等，则说明无焦点。
         */
        while (pA != nullptr && pB != nullptr) {
            pA = pA->next;
            pB = pB->next;
        }

        while (pA != nullptr) {
            pA = pA->next;
            headA = headA->next;
        }
        while (pB != nullptr) {
            pB = pB->next;
            headB = headB->next;
        }

        while (headA != nullptr && headB != nullptr) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};

int main() {
    Solution slu;
    auto n1 = new ListNode(4);
    auto n2 = new ListNode(1);
    auto n3 = new ListNode(8);
    auto n4 = new ListNode(4);
    auto n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    auto n6 = new ListNode(5);
    auto n7 = new ListNode(0);
    auto n8 = new ListNode(1);

    n6->next = n7;
    n7->next = n8;
    n8->next = n3;

    auto r = slu.getIntersectionNode(n1, n7);
    if (r != nullptr) {
        cout << r->val << endl;
    }
}