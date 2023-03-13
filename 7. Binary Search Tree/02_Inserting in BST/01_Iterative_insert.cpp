// Inserting a given key in Binary Search Tree, Iteratively

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

void pre_order (struct Node *p) {
    if (p) {
        cout << p->data << " ";
        pre_order (p->lchild);
        pre_order (p->rchild);
    }
}

int main () {

    Insert (root, 10);
    Insert (root, 20);
    Insert (root, 5);

    pre_order (root);

    return 0;
}