// Implementing Circular Queue using Array
// The pointers front & rear will move in a circular fashion using mod operation
// rear = (rear + 1) % size
// front = (front + 1) % size

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

void enqueue (struct Queue *q, int x) {

    // Check if queue is full
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue Full\n");
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue (struct Queue *q) {

    int x = -1;
    // Check if queue is empty
    if (q->front == q->rear) {
        printf("Queue Empty\n");
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void display (struct Queue q) {

    // Use do-while loop
    int i = q.front + 1;
    do {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
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
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    display(q);

    return 0;
}