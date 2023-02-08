// Converting an infix expression (containing round brackets) to a postfix expression
// Infix Expression = a+b*(c^d-e)^(f+g*h)-i and It's Postfix: abcd^e-fgh*+^*+i-

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
    
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^') 
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
    else if (x=='^')
        return 3;
    return 0;
}

char * convert (const char * infix) {

    char * postfix = new char[strlen(infix)];

    int i = 0, j = 0;

    for (i = 0; i < strlen(infix); i++) {

        // When the token is an operand
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i];
        }

        // When the token is left or right paranthesis or an operator
        else {

            // If the token is '('
            if (infix[i] == '(') {
                push(infix[i]);
            }

            // If the token is ')'
            else if (infix[i] == ')') {

                // Repeatedly pop a token from stack and push to postfix exp until'(' is encountered
                while (stackTop() != '(') {
                    postfix[j++] = stackTop();
                    pop();
                }
                pop();
            }

            else{
            // If the token is a regular operator
            while (!isEmpty() && pre(stackTop()) >= pre(infix[i])) {
                postfix[j++] = stackTop();
                pop();
            }
            push(infix[i]);
            }
        }
    }

    while (!isEmpty()) {
        postfix[j++] = stackTop();
        pop();
    }
        postfix[j] = '\0';


    return postfix;
}

int main () {

    const char * infix = "a+b*(c^d-e)^(f+g*h)-i";

    // push('#');  // Important to have a intial element in the stack

    char * postfix = convert(infix);

    // postfix[strlen(infix)] = '\0';  // Replacing '#' with NULL Character
    printf("\n\nPostix Expression: %s", postfix);
}