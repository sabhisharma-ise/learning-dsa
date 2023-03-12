// Level by Level Traversal in a Binary Tree

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

// Function to create a binary tree
void create () {
    struct Node *p, *t;
    int x;

    // Queue stores the address of nodes
    queue<struct Node *> q;

    cout << "Enter root value: ";
    cin >> x;

    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;

    q.push(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        // If x is -1, we assume the left child is not there
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);  // Insert the new node (address) into the queue
        }

        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        // If x is -1, we assume the right child is not there
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.push(t);  // Insert the new node (address) into the queue
        }
    }
}

// Function to Level Traverse
void level_traversal (struct Node *p) {

    queue<struct Node *> q;
    cout << p->data << " ";
    q.push(p);
    while (!q.empty()) {
        p = q.front();
        q.pop();

        if (p->lchild) {
            cout << p->lchild->data << " ";
            q.push(p->lchild);
        }

        if (p->rchild) {
            cout << p->rchild->data << " ";
            q.push(p->rchild);
        }
    }
}

int main () {

    create();
    level_traversal(root);

    return 0;
}
