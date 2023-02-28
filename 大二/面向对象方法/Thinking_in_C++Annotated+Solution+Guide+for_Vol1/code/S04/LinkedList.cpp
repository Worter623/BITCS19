//: S04:LinkedList.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <cassert>
using namespace std;

struct Node {
    int val;
    Node* next;
};

void create(Node* head, int howMany) {
    assert(head);
    Node* p1 = head;
    for (int i = 1; i < howMany; ++i) {
        Node* p2 = new Node;
        p2->val = i;
        p1->next = p2;
        p1 = p2;
    }
    p1->next = 0;
}

void display(Node* node) {
    assert(node);
    while (node) {
        cout << node->val << " (at " << node << ")\n";
        node = node->next;
    }
}

void cleanup(Node* node) {
    if (node) {
        cleanup(node->next);
        cout << "deleting Node at " << node << endl;
        delete node;
    }
}

int main() {
    Node* head = new Node;
    head->val = 0;
    create(head, 10);
    display(head);
    cleanup(head);
}

/* Output:
0 (at 00770950)
1 (at 00770940)
2 (at 00770930)
3 (at 00770920)
4 (at 00770910)
5 (at 00770900)
6 (at 007708F0)
7 (at 007708E0)
8 (at 007708D0)
9 (at 007707C0)
deleting Node at 007707C0
deleting Node at 007708D0
deleting Node at 007708E0
deleting Node at 007708F0
deleting Node at 00770900
deleting Node at 00770910
deleting Node at 00770920
deleting Node at 00770930
deleting Node at 00770940
deleting Node at 00770950
*/
///:~
