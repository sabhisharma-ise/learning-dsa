// Program to check if a given expression has balanced paranthesis or not 
// Say an expression is given as below
// exp = {([a+b]*[c-d])/e}

#include <iostream>
#include <string.h>
using namespace std;

struct stack {
    int top;
    int size;
    char *s;    // Since we'll be pushing characters into the array instead of integers
};

// Function to push an element into the stack
void push (struct stack *st, char x) {      // We'll be modifying the stack, so call by reference is required

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

int isMatchingPair(char character1, char character2) {

    if (character1 == '(' && character2 == ')') 
        return 1;
    else if (character1 == '{' && character2 == '}')    
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

int isBalanced (char *exp) {

    struct stack st;
    st.size = strlen(exp);
    st.top = -1;
    st.s = new char[st.size];

    // main code
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(&st, exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {

            // Check if stack is already empty
            if (isEmpty(st)) {
                return false;
            }
            // if the popped character is the matching with the closing bracket then fine
            else if (!isMatchingPair(pop(&st), exp[i])) {
                return false;
            }
            
        }
    }
    // At the end of exp, the stack should be empty
    if (isEmpty(st)) return true;
    else return false;
}

int main () {

    char *exp = "{([a+b]+[c-d])/e}";

    cout << isBalanced(exp);

    return 0;
}