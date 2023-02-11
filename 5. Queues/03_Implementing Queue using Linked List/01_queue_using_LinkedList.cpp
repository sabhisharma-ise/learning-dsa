// Implementation of Queue using Linked List
// We'll take two pointers (front and rear)
// Front points on the first node & Rear points on the last node
// Insertion will take place from the rear end (O(1) time)
// Deletion will take place from the front end (O(1) time)

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *front, *rear = NULL;

// Function to insert at the rear end 
void enqueue (int x) {

    struct Node *t = new Node;
    // Check if the heap memory is full
    if (t == NULL) {
        printf("Queue is Full\n");
    } else {
        t->data = x;
        t->next = NULL;

        // Check if the node we're inserting is First Node
        if (front == NULL) { front = rear = t; }
        else {
            rear->next = t;
            rear = t;
        }
    }
}

// Function to delete from the front end
int dequeue () {

    int x = -1;
    struct Node *p = front;
    // Check if the queue is empty
    if (front == NULL) {
        printf("Queue is Empty\n");
    } else {
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

// Function to display the content of the queue
void display() {

    struct Node *p = front;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}


int main () {

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("\n%d\n", dequeue());

    display();

    return 0;
}