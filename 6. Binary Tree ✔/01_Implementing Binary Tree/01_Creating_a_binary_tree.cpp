// Creating a Binary Tree using Heap
// Linked Binary Tree with the use of Queue STL

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

// Pre-order Traversal
void preorder (struct Node *p) 
{   
    if (p) {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

// In-order Traversal
void inorder (struct Node *p) 
{
    if (p) {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

// Post-order Traversal
void postorder (struct Node *p)
{
    if (p) {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}

int main () {

    create();
    cout << "Pre-order Traversal: ";
    preorder(root);
    cout << "\nIn-order Traversal: ";
    inorder(root);
    cout << "\nPost-order Traversal: ";
    postorder(root);

    return 0;
}