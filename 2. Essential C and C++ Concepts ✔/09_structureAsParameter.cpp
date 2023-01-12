// Passing of structure as parameter

#include <iostream>
using namespace std;

struct Rectangle {

    int length;
    int breadth;

};

// Call By Value
int Area(struct Rectangle r1) {

    return r1.length * r1.breadth;
}

// Call By Reference
int Area1(struct Rectangle &r1) {

    return r1.length * r1.breadth;
}

// Call By Address
void changeLength(struct Rectangle *p, int l) {

    p->length = l;
}

int main () {

    struct Rectangle r = {10, 5};

    printf("%d ", Area(r));

    changeLength(&r, 20);

    printf("%d", Area1(r));

    return 0;
}