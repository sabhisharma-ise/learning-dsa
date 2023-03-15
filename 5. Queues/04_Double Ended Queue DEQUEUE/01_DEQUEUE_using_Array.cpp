// Implementation of Double Ended Queue (DEQUEUE) using an Array
// In double ended queue, we can use use both the pointers (front anf rear)
// for both the operations (insertion as well as deletion)

#include <iostream>
using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void create (struct Queue *q, int size) {

    q->size = size;
    q->front = q->rear = 0;     // In Circular Queue, front and rear should initially point to zero
    q->Q = new int[size];
}

// Function to insert at rear
void insert_rear (struct Queue *q, int x) {

    // Check if the queue is full
    if (q->rear == q->size - 1) printf("Queue is full\n");
    else {
        // Insert at rear
        q->rear++;
        q->Q[q->rear] = x;
    }
}

// Function to delete from rear
int delete_rear (struct Queue *q) {
    
    int x = -1;

    // Check if the queue is empty
    if (q->front == q->rear) printf("Queue is empty\n");
    else {
        // Delete from rear
        x = q->Q[q->rear];
        q->rear--;
    }
    return x;
}

// Function to delete from front
int delete_front (struct Queue *q) {

    int x = -1;

    // Check if the queue is empty
    if (q->front == q->rear) printf("Queue is empty\n");
    else {
        // Delete from front
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

// Function to insert at front
void insert_front (struct Queue *q, int x) {

    // If front does not points to -1, then only we can insert at front
    if (q->front != -1) {
        
        // Check if the queue is full
        if (q->rear == q->size - 1) printf("Queue is full\n");
        else {
            // Insert at front
            q->Q[q->front] = x;
            q->front--;
        }
    }
}


// Function to display the content of a queue
void display (struct Queue q) {

    for (int i = q.front + 1; i <= q.rear; i++) {
        printf("%d ", q.Q[i]);
    }
}

int main () {

    struct Queue q;

    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    
    create(&q, size);

    insert_rear(&q, 30);
    insert_rear(&q, 40);
    insert_rear(&q, 50);

    display(q);

    printf("\n%d\n", delete_front(&q));

    insert_front(&q, 30);
    insert_front(&q, 20);

    display(q);

    printf("\n%d\n", delete_front(&q));

    display(q);

    return 0;
}