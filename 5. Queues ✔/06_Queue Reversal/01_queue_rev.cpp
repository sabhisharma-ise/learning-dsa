//test

// Reversing a queue using an array and in-built queueu STL

#include <iostream>
#include <queue>

using namespace std;

queue<int> rev (queue<int> q) {

    int c = q.size();
    int A[c];

    for (int i = 0; i < c; i++) {
        A[i] = q.front();
        q.pop();
    }

    for (int i = c - 1; i >= 0; i--) {
        q.push(A[i]);
    }
    
    return q;
}


int main () {

    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);

    queue<int> a = rev(q);
    while (!a.empty()) {
        cout << a.front() << " ";
        a.pop();
    }
    
    return 0;
}