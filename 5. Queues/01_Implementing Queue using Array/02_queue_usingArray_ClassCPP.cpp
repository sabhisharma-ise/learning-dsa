// C++ Class for a Queue using Array with two pointers (fornt and rear)

#include <iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int size;
        int *Q;
    public:
        Queue() {front = rear = -1; size = 10; Q = new int[size];}
        Queue(int size) {front = rear = -1; this->size = size; Q = new int[this->size];}
        void enqueue(int x);
        int dequeue();
        void display(); 
};

void Queue::enqueue(int x) {
    // Check if queue is full
    if (rear == size-1) {
        printf("Queue is full\n");
    } else {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue() {
    int x = -1;
    // Check if queue is empty
    if (front == rear) {
        printf("Queue is empty\n");
    } else {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::display() {

    for (int i = front + 1; i <= rear; i++) {
        printf("%d ", Q[i]);
    }
}

int main () {

    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    return 0;
}