// Collection of dissimilar items

#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main () {

    struct Rectangle r;     // Initialization

    r = {10, 5};   // Declaration
    
    // Accessing structure members
    r.length = 15;
    r.breadth = 20;

    int area = r.length * r.length;

    printf("Area of Rectangle is %d", area);

    return 0;
}