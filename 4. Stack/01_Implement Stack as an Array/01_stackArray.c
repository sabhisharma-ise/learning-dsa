// Implementation of Stack using an Array in C

#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *s;
};

// Function to create a new stack
void create (struct stack *st) {
    // Input size of stack
    printf("Enter size of stack: ");
    scanf("%d", &st->size);

    // Create an array in heap
    st->s = (int *)malloc(st->size * sizeof(int));  // C
    // st.s = new int[st.size]  // C++


    // Set top variable to -1
    st->top = -1;
}

// Function to display stack content
void display (struct stack st) {    // We are not modifying the stack, so call by value works

    for (int i = st.top; i >= 0; i--) {
        printf("%d ", st.s[i]);
    }
}

// Function to push an element into the stack
void push (struct stack *st, int x) {      // We'll be modifying the stack, so call by reference is required

    // Check if stack is already full
    if (st->top == (st->size - 1)) printf("Stack overflow\n");
    else {
        st->top++;
        st->s[st->top] = x;
    }
}

// Function to pop an element from the stack
int pop (struct stack *st) {

    int x = -1;
    // Check if stack is empty
    if (st->top == -1) printf("Stack underflow\n");
    else {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

// Function to display stack element at given position (Viewed from top)
int peek (struct stack st, int pos) {

    int x = -1;
    if (st.top - pos + 1 < 0) printf("Invalid position");
    else {
        x = st.top - pos + 1;
    }
    return st.s[x];
}

// Function to check if a stack is empty
int isEmpty (struct stack st) {

    if (st.top == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a stack is full
int isFull (struct stack st) {

    if (st.top == st.size - 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to display the stack top value
int stackTop (struct stack st) {

    // Check if stack is empty
    if (!isEmpty) {
        return st.s[st.top];
    } else {
        return -1;
    }
}

int main () {

    struct stack st;

    create (&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    printf("%d\n", peek(st, 2));

    // printf("%d \n", pop(&st));
    // printf("%d \n", pop(&st));
    // printf("%d \n", pop(&st));



    display (st);

    return 0;
}