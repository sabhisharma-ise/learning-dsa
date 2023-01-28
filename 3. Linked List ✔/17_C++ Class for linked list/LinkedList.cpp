// Using C++ Class for linked list

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
};

class LinkedList {
    private:
    Node *first;

    public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();

    void display();
    void insert(int pos, int x);
    int Delete(int pos);
    int length();
};

LinkedList::LinkedList (int A[], int n) {
    Node *last, *t;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList() {
    Node *p = first;
    while (first) {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::display() {
    Node *p = first;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
}

int LinkedList::length() {
    Node *p = first;
    int l = 0;
    while (p) {
        l++;
        p = p->next;
    }
    return l;
}

void LinkedList::insert(int pos, int x) {
    Node *t, *p = first;

    if (pos < 0 || pos > length()) return;

    t = new Node;
    t->data = x;
    t->next = NULL;

    if (pos == 0) {
        t->next = first;
        first = t;
    } else {
        for (int i = 0; i < (pos - 1); i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::Delete(int pos) {
    Node *p, *q = NULL;
    int x = -1;

    if (pos < 0 || pos > length()) return -1;

    if (pos == 1) {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    } else {
        for (int i = 0; i < (pos - 1); i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main () {

    int A[] = {1, 2, 3, 4, 5};
    LinkedList l(A, 5);

    // cout << l.length() << "\n";

    l.insert(0, 10);

    l.display();

    return 0;
}