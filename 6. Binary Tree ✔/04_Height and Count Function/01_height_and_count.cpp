// Implementing Height and Count Functions in a Binary Tree

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

// Function to Count the Number of Nodes of a Binary Tree
int count (struct Node *p) {

    int x, y;
    if (p) {
        x = count(p->lchild);
        y = count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

// Function for Height of a Binary Tree
int height (struct Node *p) {
    int x, y;
    if (p == NULL) {
        return -1;  // for a empty binary tree (i.e. when 'p' reaches NULL) -> Height is -1
    }
    x = height (p->lchild);
    y = height (p->rchild);

    return max(x, y) + 1;
}

int main () {

    create();

    cout <<  "Height of Binary Tree: " << height(root) << "\n";

    cout << "Number of Nodes: " << count(root) << "\n";

    return 0;
}