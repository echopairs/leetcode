#include <iostream>
using namespace std;

struct Node {
    Node(int val): val_(val) {
    }
    Node * next;
    int val_;
};

void reverse(Node* root) {
    Node * current = root;
    Node * prv = nullptr;
    while (current != nullptr) {
	auto next = current->next;
	current->next = prv;
	prv = current;
	current = next;
    }
}

int main() {
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    reverse(n1);
    while (n5 != nullptr) {
	cout << n5->val_ << " ";
	n5 = n5->next;
    }
    cout << endl;
}
