

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *s;
};

// Function to create a new stack
void create (struct stack *st) {
    // Input size of stack
    printf("Enter size of stack: ");
    scanf("%d", &st->size);

    // Create an array in heap
    st->s = (char *)malloc(st->size * sizeof(char));  // C
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

// Function to check if a character is an operand
int isOperand (char x) {
    
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')') 
        return 0;
    else 
        return 1;
}

// Function for returning the precedence of a operator
int pre (char x) {

    if (x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/') 
        return 2;
    else if (x == '^')
        return 3;
    return 0;
}

// Function for converting Infix to Postfix expression
char *convert(char * infix) {

    struct stack st;    
    create(&st);

    // char *postfix = new char[strlen(infix) + 1] // In C++
    char *postfix = (char *) malloc (sizeof(char) * strlen(infix) + 1);  // Creates a string in heap memory

    int i = 0, j = 0;
    while (infix[i] != '\0') {

        if (isOperand(infix[i])) {

            postfix[j++] = infix[i++];
        }
        else {

                if (pre(infix[i]) > pre(stackTop(st)))
                        push(&st, infix[i++]);
                else 
                    postfix[j++] = pop(&st);
        }
    }

    while (!isEmpty(st)) {

        postfix[j++] = pop(&st);
        postfix[j] = '\0';
    }

    return postfix;
}

int main () {

    char * infix = "a+b*c-d/e"; 

    printf("Postix Expression: %s", convert(infix));
    
    return 0;
}