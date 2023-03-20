// Inserting, Deleting, Searching

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
} *root = NULL;


// Insert Function
void insert (int key) {
    struct Node *t = root;
    struct Node *r = NULL;

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));

    // Insertion in empty BST
    if (root == NULL) {
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;    
    }

    while (t) {
        r = t;
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

    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data) r->lchild = p;
    else r->rchild = p;
}

// Find the node with min value in a subtree
struct Node *FindMin (struct Node *p) {
    p = p->rchild;
    while (p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

// Delete Function
struct Node *Delete (struct Node *p, int key) {

    // base case
    if (p == NULL)
        return p;

    else if (key < p->data) p->lchild = Delete(p->lchild, key);
    else if (key > p->data) p->rchild = Delete(p->rchild, key);
    else {  // Found the node, Get Ready to be deleted

        // Case 1: No child (leaf node)
        if (p->lchild == NULL && p->rchild == NULL) {
            free(p);
            p = NULL;
        }
        // Case 2: One child
        else if (p->lchild == NULL) {
            struct Node *temp = p;
            p = p->rchild;
            free(temp);
        }
        else if (p->rchild == NULL) {
            struct Node *temp = p;
            p = p->lchild;
            free(temp);
        }
        // Case 3: Two child
        else if (p->lchild != NULL && p->rchild != NULL) {
            struct Node *temp = FindMin (p->rchild);    // Find min in right-subtree
            p->data = temp->data;   // Copy the value in targetted node
            p->rchild = Delete (p->rchild, temp->data);     // Delete duplicate from right-subtree
        }
    }
    return p;
}


// Search Function
void search (struct Node *p, int key) {

    while (p != NULL) {
        if (key == p->data) {
            printf("Item present\n");
            return;
        }
        else if (key < p->data) {
            p = p->lchild;
        }
        else {
            p = p->rchild;
        }
    }
    printf("Item not present\n");
    return;
}

// Counting Nodes in BST
int count (struct Node *p) {
    if (p) {
        int x, y;
        x = count (p->lchild);
        y = count (p->rchild);
        return x + y + 1;
    }
    return 0;   // if no node is present (i.e., root is NULL)
}

// Height Function
int height (struct Node *p) {
    if (p) {
        int x, y;
        x = height (p->lchild);
        y = height (p->rchild);
        return (x > y) ? (x + 1) : (y + 1);
    }
    return -1;  // if 'p' becomes NULL
}

// Tree Traversals
void pre_order (struct Node *p) {
    if (p) {
        printf("%d ", p->data);
        pre_order (p->lchild);
        pre_order (p->rchild);
    }
}

void in_order (struct Node *p) {
    if (p) {
        pre_order (p->lchild);
        printf("%d ", p->data);
        pre_order (p->rchild);
    }
}

void post_order (struct Node *p) {
    if (p) {
        pre_order (p->lchild);
        pre_order (p->rchild);
        printf("%d ", p->data);
    }
}

int main () {

    int ch, item;
    int c, h;
    struct Node *p;

    for (;;) {

        printf("1.Insert  2.Delete  3.Search  4. Count Nodes  5. Height\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: // Insert
                printf("Enter the value to be inserted: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2: // Delete
                printf("Enter the value to be deleted: ");
                scanf("%d", &item);
                root = Delete(root, item);
                break;
            case 3: // Search
                printf("Enter the value to be searched: ");
                scanf("%d", &item);
                search(root, item);
                break;
            case 4: // Count Nodes
                c = count(root);
                printf("Number of Nodes in BST: %d\n", c);
                break;
            case 5: // Height
                h = height(root);
                printf("Height of BST: %d\n", h);
                break;
            default:
                exit(0);   
        }
    }
    return 0;
}