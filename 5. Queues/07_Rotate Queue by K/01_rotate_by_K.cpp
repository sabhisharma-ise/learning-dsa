// Rotate the elements of the dequeue in a circular fashion side by K steps

// 2 Steps
// Delete element from front
// Push it to the last

#include <iostream>
#include <deque>
using namespace std;

//Function to rotate deque by k places in anti-clockwise direction.
void left_Rotate_Deq_ByK(deque<int> &deq, int n, int k)
{
    // your code here
    for (int i = 0; i < k%n; i++) {
        int var = deq.front();
        deq.pop_front();
        deq.push_back(var);
    }
     
}

//Function to rotate deque by k places in clockwise direction.
void right_Rotate_Deq_ByK(deque<int> &deq, int n, int k)
{
    // your code here
    // int size = deq.size();
    for (int i = 0; i < k%n; i++) {
        int var = deq.back();
        deq.pop_back();
        deq.push_front(var);
    }

}


int main () {

    deque<int> deq;
    deq.push_back(10);
    deq.push_back(20);
    deq.push_back(30);
    deq.push_back(40);

    left_Rotate_Deq_ByK(deq, 4, 2);     // Will give output: 30 40 10 20
    for (auto itr = deq.begin(); itr != deq.end(); itr++) {
        cout << *itr << " ";
    }

    cout << "\n";
    
    right_Rotate_Deq_ByK(deq, 4, 1);    // Will give output: 20 30 40 10
    for (auto itr = deq.begin(); itr != deq.end(); itr++) {
        cout << *itr << " ";
    }

    return 0;
}