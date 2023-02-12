// Implementation of Queue using 2 Stacks
// For enqueue, we always push the element into stack s1
// For dequeue, we first check if s2 is empty
// If s2 is empty, we tranfer all s1 elements to s2 and then pop the topmost element from s2
// If s2 is not empty (means it already has tranferred elements from s1), so we directly pop out

#include <iostream>
#include <stack>
using namespace std;

// Globally define two stacks
stack<int> s1;
stack<int> s2;

// Enqueue Operation
void enqueue (int x) {

    s1.push(x);
}

// Dequeue Operation
int dequeue () {

    int x = -1;

    // Check if stack s2 is empty
    if (s2.empty()) {

        // Check if stack s1 is empty
        if (s1.empty()) {
            return x;
        }
        else {
            // Tranfer stack s1 content into stack s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

    x = s2.top();
    s2.pop();

    return x;
}

int main () {

    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << dequeue() << " ";
    cout << dequeue() << " ";
    cout << dequeue();

    return 0;
}