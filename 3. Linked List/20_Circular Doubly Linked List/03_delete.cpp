// Delete

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

int Delete (struct Node *head, int pos) {

    struct Node *p = head;
    struct Node *last = head->prev;
    int x = -1;

    if (pos <= 0 || pos > length(head)) return x;

    if (pos == 1) {
        head = head->next;
        int x = p->data;
        delete p;
        if (head) head->prev = last;
        last->next = head;

        // p->prev->next = head;
        // head->prev = p->prev;
        // int x = p->data;
    }

    else {
        for (int i = 0; i < pos - 1; i++) {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        int x = p->data;
        delete p;
    }
    return x;
}


int main () {

    int A[] = {2, 3, 4, 5, 6};
    create(A, 5, &head);

    printf("%d", Delete (head, 3));

    // printf("%d\n", length(head));

    display(head);

    return 0;
}