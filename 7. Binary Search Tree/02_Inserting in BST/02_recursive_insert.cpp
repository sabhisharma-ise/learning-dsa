// Inserting a given key in Binary Search Tree, Recursively

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
} *root = NULL;

// Insert Function (Recursive)
struct Node *insert(struct Node *p, int key) {
    struct Node *t = NULL;
    if (p == NULL) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data) {
        p->lchild = insert (p->lchild, key);
    }
    else if (key > p->data) {
        p->rchild = insert (p->rchild, key);
    }   
    return t; 

}

void in_order (struct Node *p) {

    if (p) {
        in_order (p->lchild);
        cout << p->data << " ";
        in_order (p->rchild);
    }
}

int main () {

    root = insert (root, 50);
    insert (root, 10);
    insert (root, 20);
    insert (root, 5);
    insert (root, 30);

    in_order (root);    // Should be in Ascending Order

    return 0;
}