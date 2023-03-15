// Iterative traversal
// Logic is to use a Stack (Stack STL in C++) for converting Recursive to Iterative Solution

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int data;
    struct Node *lchild;
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

// Iterative In-Order Traversal
void inorder (struct Node *p) {
    
    stack<struct Node*> st; 
    
    while (p != NULL || !st.empty()) {

        if (p != NULL) {
            st.push(p);
            p = p->lchild;
        }
        else {
            p = st.top();
            st.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}


int main () {

    create();
    // cout << "Pre-order Traversal: ";
    // preorder(root);
    cout << "\nIn-order Traversal: ";
    inorder(root);
    // cout << "\nPost-order Traversal: ";
    // postorder(root);


    return 0;
}