// Function - Group of instructions that performs a specific task, and is re-usable.
// Monlithic Programming - Writing everything inside the main() function. 
// Modular/Procedural Programming - Breaking down the program into separate functions.
// C language is a Modular Programming Language
// In C++, we can use Object Oriented Programming (in which similar functions can be grouped in a single class) 


#include <iostream>
using namespace std;

// Prototype 
int add(int a, int b) // Parameters passed are Formal Parameters
{
    // Definition
    int c;
    c = a + b;
    return c;

}

int main () {

    int x, y,z;

    x = 10;
    y = 5;

    // Calling the function
    z = add(x, y);  // Parameters passed are Actual Parameters
    
    printf("Sum is %d", z);

    return 0;
}