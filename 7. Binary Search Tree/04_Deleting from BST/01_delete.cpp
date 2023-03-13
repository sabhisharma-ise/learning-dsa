// Deleting a given key from a Binary Search Tree, Recursively

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
} *root = NULL;

// Function to Create a BST
void create () {
    
}

// Height of a Sub-Tree
int height (struct Node *p) {
    if (p == NULL) return -1;
    int x, y;
    x = height (p->lchild);
    y = height (p->rchild);
    return max(x, y) + 1;
}

// Inorder Predecessor
struct Node *InPre (struct Node *p) {
    while (p && p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

// Inorder Successor
struct Node *InSucc (struct Node *p) {
    while (p && p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

// Delete Function (Recursive)
struct Node *Delete (struct Node *p, int key) {
    struct Node *q;
    if (p == NULL) return NULL;
    if (p->lchild == NULL && p->rchild == NULL) {
        if (p == root) root = NULL;
        delete p;
        return NULL;
    }

    if (key < p->data) p->lchild = Delete (p->lchild, key);
    else if (key > p->data) p->rchild = Delete (p->rchild, key);
    else {
        // Assign the InPre or InSucc, based on which-ever Sub-Tree has greater Height
        if (height (p->lchild) > height(p->rchild)) {
            q = InPre (q->lchild);
            p->data = q->data;
            p->lchild = Delete( p->lchild, q->data);
        }
        else {
            q = InSucc (q->rchild);
            p->data = q->data;
            p->rchild = Delete( p->rchild, q->data);
        }
    }
    return p;
}


int main () {

    create ();

    int key;
    cout << "Enter the key to be deleted: " << "\n";
    cin >> key;

    Delete (root, key);


    return 0;
}