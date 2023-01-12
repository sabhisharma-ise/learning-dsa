// Pass By Address - The Addresses of actual parameters are passed to Formal Parameters and the formal parameters must be pointers.
// So, Call by Address is a suitable mechanism for modifying the actual parameters

#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main () {

    int a, b;

    a = 10;
    b = 20;

    // Call by Address
    swap(&a, &b);
    
    printf("%d %d", a, b);  // Value of a and b is swapped

    return 0;
}
