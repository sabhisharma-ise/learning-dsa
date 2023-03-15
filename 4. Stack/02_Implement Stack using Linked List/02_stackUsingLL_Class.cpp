// Implementing a C++ Class of a Stack using Linked List

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class Stack {
    private:
        Node *top;
    public:
        Stack(){top = NULL;}
        void push(int x);
        int pop();
        void display();
};

void Stack::push (int x) {
    Node *t = new Node;
    if (t == NULL) printf("Stack is full\n");
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop () {
    int x = -1;
    if (top == NULL) printf("Stack is empty\n");
    else {
        x = top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

void Stack::display () {
    Node *p = top;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main () {

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << " " << st.pop();

    return 0;
}