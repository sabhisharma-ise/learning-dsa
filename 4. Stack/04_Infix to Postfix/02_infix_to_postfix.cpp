

#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

// struct stack {
//     int size;
//     int top;
//     char *s;
// };

// // Function to create a new stack
// void create (struct stack *st) {
//     // Input size of stack
//     printf("Enter size of stack: ");
//     scanf("%d", &st->size);

//     // Create an array in heap
//     st->s = (char *)malloc(st->size * sizeof(char));  // C
//     // st.s = new int[st.size]  // C++


//     // Set top variable to -1
//     st->top = -1;
// }

// // Function to display stack content
// void display (struct stack st) {    // We are not modifying the stack, so call by value works

//     for (int i = st.top; i >= 0; i--) {
//         printf("%d ", st.s[i]);
//     }
// }

// // Function to push an element into the stack
// void push (struct stack *st, int x) {      // We'll be modifying the stack, so call by reference is required

//     // Check if stack is already full
//     if (st->top == (st->size - 1)) printf("Stack overflow\n");
//     else {
//         st->top++;
//         st->s[st->top] = x;
//     }
// }

// // Function to pop an element from the stack
// int pop (struct stack *st) {

//     int x = -1;
//     // Check if stack is empty
//     if (st->top == -1) printf("Stack underflow\n");
//     else {
//         x = st->s[st->top];
//         st->top--;
//     }
//     return x;
// }

// // Function to display stack element at given position (Viewed from top)
// int peek (struct stack st, int pos) {

//     int x = -1;
//     if (st.top - pos + 1 < 0) printf("Invalid position");
//     else {
//         x = st.top - pos + 1;
//     }
//     return st.s[x];
// }

// // Function to check if a stack is empty
// int isEmpty (struct stack st) {

//     if (st.top == -1) {
//         return 1;
//     } else {
//         return 0;
//     }
// }

// // Function to check if a stack is full
// int isFull (struct stack st) {

//     if (st.top == st.size - 1) {
//         return 1;
//     } else {
//         return 0;
//     }
// }

// // Function to display the stack top value
// int stackTop (struct stack st) {

//     // Check if stack is empty
//     if (!isEmpty) {
//         return st.s[st.top];
//     } else {
//         return -1;
//     }
// }

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
    return 0;
}

// Function for converting Infix to Postfix expression
string convert(string s) {

    string postfix ="";

    stack<char> st;

        int i = 0; 
        int j = 0;
        while(i < s.length()) {
            
            if (isOperand(s[i])) {
                
                postfix += s[i++];
            }
            
            else if (s[i] == '(') {
                
                st.push(s[i]);
            }
            
            else if (s[i] == ')') {
                
                while (!st.empty() && st.top()!='(') {
                    postfix += st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    st.pop();
                }
            }
            
            else {
                
                while(!st.empty() && pre(st.top()) >= pre(s[i])) {
                
                // if (pre(s[i] > pre(st.top()))) {
                    
                    postfix += st.top();
                    st.pop();
                    
                }
                    st.push(s[i]);
                // }
                
                // else {
                    
                // }
            }
        }
        
        while (!st.empty()) {
            
           postfix += st.top();
           st.pop();
        }
        
        return postfix;
}

int main () {

    string infix = "a+b*(c^d-e)^(f+g*h)-i"; 

    printf("Postix Expression: %s", convert(infix));
    
    return 0;
}