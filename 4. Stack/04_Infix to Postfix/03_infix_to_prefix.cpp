// Converting a given infix expression into a prefix expression (Without Parenthesis)
// Using Stack Method
// Infix Expression = a+b*c-d/e, It's Prefix equivalent: -+a*bc/de

#include <iostream>
#include <string.h>
// using namespace std;

struct Node {
    char data;
    struct Node *next;
} *top = NULL;

int isEmpty () {

    if (top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int isFull () {

    struct Node *t = new Node;
    if (t == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to push a new node to the stack at the front
void push (char x) {

    struct Node *t;
    t = new Node;

    if (isFull()) printf("Stack Overflow\n");
    else {
        t->data =x;
        t->next = top;
        top = t;
    }
}

// Function to pop the top most element from the stack
char pop() {

    struct Node *t;
    char x = -1;

    if (isEmpty()) printf("Stack is Empty\n");
    else {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

char stackTop() {

    return top->data;
}

// Function to check if a character is an operand
int isOperand (char x) {
    
    if (x == '+' || x == '-' || x == '*' || x == '/') 
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
    return 0;
}

// Function for converting Infix to Postfix expression
char *convert(char * infix) {

    char *postfix = new char[strlen(infix) + 1]; // In C++
    // char *postfix = (char *) malloc (sizeof(char) * strlen(infix) + 1);  // Creates a string in heap memory

    int i = 0, j = 0;
    while (infix[i] != '\0') {

        if (isOperand(infix[i])) {

            postfix[j++] = infix[i++];
        }
        else {

                if (isEmpty() || pre(infix[i]) >= pre(stackTop()))   // if stack is empty, then push the operator in the stack (Using this, we don't need '#' initially in the stack)
                        push(infix[i++]);
                else 
                    postfix[j++] = pop();
        }
    }

    while (!isEmpty()) {

        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    return postfix;
}

// Function to reverse the infix expression
void reverse (char *infix) {
    int size = strlen(infix);
    int j = size;
    int i = 0;
    char temp[size];

    temp[j--] = '\0';
    while (infix[i] != '\0') {
        temp[j] = infix[i];
        j--;
        i++;
    }
    strcpy (infix, temp);
} 


int main () {

    char infix[] = "a+b*c-d/e";

    // Reverse the infix expression
    reverse (infix);

    // Obtain the postfix expression
    char * prefix = convert(infix);

    // Reverse the postfix expression
    reverse (prefix);

    printf("Prefix Expression: %s", prefix);
    
    return 0;
}