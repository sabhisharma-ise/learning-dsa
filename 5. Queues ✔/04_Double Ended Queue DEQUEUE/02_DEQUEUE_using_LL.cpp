// Implementation of Double Ended Queue (DEQUEUE) using Doubly Linked List
// In double ended queue, we can use use both the pointers (front anf rear)
// for both the operations (insertion as well as deletion)

#include <iostream>
using namespace std;

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *front, *rear = NULL;

// Function to insert at rear
void insert_rear (int x) {

    struct Node *t = new Node;
    // Check if the heap memory is full
    if (t == NULL) {
        printf("Queue is Full\n");
    } else {
        t->prev = NULL;
        t->data = x;
        t->next = NULL;

        // Check if the node we're inserting is First Node
        if (front == NULL) { front = rear = t; }
        else {
            rear->next = t;
            t->prev = rear;
            rear = t;
        }
    }
}

// Function to delete from rear
int delete_rear (struct Queue *q) {
    
    int x = -1;
    struct Node *p = rear;
    // Check if the queue is empty
    if (front == NULL) {
        printf("Queue is Empty\n");
    } else {
        front = front->next;
        x = p->data;
        delete p;
    }
}

// Function to delete from rear
int delete_front () {

    int x = -1;
    struct Node *p = front;
    // Check if the queue is empty
    if (front == NULL) {
        printf("Queue is Empty\n");
    } else {
        front = front->next;
        x = p->data;
        if (front == NULL) rear = NULL;
        else front->prev = NULL;
        delete p;
    }
    return x;
}

// Function to delete from front
int insert_front (int x) {

    struct Node *t = new Node;
    if (t == NULL) {
        printf("Queue is Full\n");
    } else {
        if (front == NULL) front = rear = t;
        else {
            t->next = front;
            front->prev = t;
            front = t;
        }
    }
}

void display () {

    struct Node *p = front;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}


int main () {

    insert_rear(10);
    insert_rear(20);
    insert_rear(30);

    display();

    printf("\n%d\n", delete_front());

    display();

    

    return 0;
}