// Implementation of Queues using an Array
// We require the size of the array (which is fixed)
// And two pointers (say front and rear)
// Initially front = rear = -1 (Indicating Empty Queue)

#include <iostream>
using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

// Function to initialize a Queue
void create(struct Queue *q, int size) {
    q->size=size;
    q->front=q->rear=-1;
    q->Q=new int[q->size];
}

// Function to Insert a new element into the queue
void enqueue (struct Queue *q, int x) {
    // Check if queue is full
    if (q->rear == q->size - 1) {
        printf("Queue is Full");
    } else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

// Function to Delete an element from the queue
int dequeue (struct Queue *q) {
    int x = -1;
    // Check if queue is empty
    if (q->front == q->rear) {
        printf("Queue is Empty");
    } else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
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

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(q); cout << "\n";

    printf("Deleted element is: %d \n", dequeue(&q));
    
    display(q);

    return 0;
}
