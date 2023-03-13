// Searching for a given key in Binary Search Tree, Recursively

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
} *root = NULL;

// Insert Function (Iterative)
void Insert(struct Node *t, int key) {

    struct Node *r = NULL;  // tail pointer

    // New Node
    if (root == NULL) {
        struct Node *p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    
    while (t != NULL) {

        r = t;  // Move 'r' pointer to 't' pointer

        if (key == t->data) {
            return;
        }
        else if (key < t->data) {
            t = t->lchild;
        }
        else {
            t = t->rchild;
        }
    }

    struct Node *p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data) {
        r->lchild = p;
    }
    else {
        r->rchild = p;
    }

}


// Search Function (Recursive)
struct Node *r_search(struct Node *t, int key) {

    if (t == NULL) return t;

    if (key == t->data) {
        return t;
    }
    else if (key < t->data) {
        r_search(t->lchild, key);
    }
    else {
        r_search(t = t->rchild, key);
    }
}

int main () {

    Insert (root, 10);
    Insert (root, 20);
    Insert (root, 5);

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    struct Node *t = r_search (root, key);

    if (t->data == key) {
        cout << "Key is Present\n";
    }
    else {
        cout << "Key is not Present\n";
    }

    return 0;
}