// Pass By Reference - Reference is nothing but an alias to a variable
// This Pass by Reference is a feature in C++

#include <iostream>
using namespace std;

void swap(int &x, int &y)
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

    // Call by Reference
    swap(a, b);
    
    printf("%d %d", a, b);  // Value of a and b is not swapped

    return 0;
}