// Pass By Value - The changes which are done in the function will not affect the main function
// This is not suitable for swap program since it was not able to swap the actual parameters

#include <iostream>
using namespace std;

void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main () {

    int a, b;

    a = 10;
    b = 20;

    // Call by Value
    swap(a, b);
    
    printf("%d %d", a, b);  // Value of a and b is not swapped

    return 0;
}

// So, in pass by value, Actual Parameters will not be modified if any changes are done to Formal Parameters