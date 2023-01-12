// To access structure members using pointer

#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main () {

    struct Rectangle r = {10, 5};     // Structure variable
    struct Rectangle *p = &r;    // Pointer to structure variable 'r'

    // Structure member using normal variable
    r.length = 15;

    // Structure member using pointer (a little complex way)
    (*p).length = 20;

    // Structure member using pointer (a little easy way)
    p->breadth = 25;

    printf("%d", p->breadth);

    return 0;
}