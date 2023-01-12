// Complex Number = a + ib

#include <iostream>
using namespace std;

struct complex {
    int a;
    int b;
};

int main () {

    struct complex c;     // Initialization

    c = {10, 5};   // Declaration
    
    // Accessing structure members
    c.a = 15;
    c.b = 20;

    printf("Complex number is %d + i%d", c.a, c.b);

    return 0;
}