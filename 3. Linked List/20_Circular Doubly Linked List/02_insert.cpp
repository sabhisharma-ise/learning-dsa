// Insert

#include <iostream>
using namespace std;

// Structure for a circular doubly linked list
struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *head = NULL;

// https://www.geeksforgeeks.org/convert-array-to-circular-doubly-linked-list/
void create(int arr[], int n, struct Node **start)
{
    // Declare newNode and temporary pointer
    struct Node *newNode,*temp;
    int i;
     
    // Iterate the loop until array length
    for(i=0;i<n;i++)
    {
        // Create new node
        newNode = new Node;
         
        // Assign the array data
        newNode->data = arr[i];
         
        // If it is first element
        // Put that node prev and next as start
        // as it is circular
        if(i==0)
        {
            *start = newNode;
            newNode->prev = *start;
            newNode->next = *start;
        }
        else
        {  
            // Find the last node
            temp = (*start)->prev;
             
            // Add the last node to make them
            // in circular fashion
            temp->next = newNode;
            newNode->next = *start;
            newNode->prev = temp;
            temp = *start;
            temp->prev = newNode;
        }
    }
}

// Display Function
void display (struct Node *p) {

    do {

        printf("%d ", p->data);
        p = p->next;

    } while (p != head);

}

// Count Function
int length (struct Node *p) {

    int l = 0;
    do {
        
        l++;
        p = p->next;
    } while (p != head);

    return l;
}

void insert (struct Node **head, int pos, int x) {

    struct Node *p = *head;
    struct Node *t = new Node;
    struct Node *last = (*head)->prev;

    t->data = x;

    if (pos < 0 || pos > length(*head)) return;

    // Insert before head
    if (pos == 0) {

        t->next = *head;
        t->prev = last;
        last->next = t;
        (*head)->prev = t;
        *head = t;

    } 

    // Insert at any other given position
    else {

        for (int i = 0; i < (pos - 1); i++) {
            p = p->next;
        }

        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
    }


}


int main () {

    int A[] = {2, 3, 4, 5, 6};
    create(A, 5, &head);

    insert (&head, 0, 10);

    // printf("%d\n", length(head));

    display(head);

    return 0;
}