// Using structre as a paramter to various functions
// This is best way we can write code in C language
// We'll see how to write it in C++ in the next code file

#include <stdio.h>

struct Rectangle {
    int length;
    int breadth;
};

void initialize(struct Rectangle *r, int l, int b) {
    r->length = l;
    r->breadth = b;
}

int area(struct Rectangle r) {
    return r.length * r.breadth;
}

void changeLength(struct Rectangle *r, int l) {
    r->length = l;
}

int main () {

    struct Rectangle r;

    initialize(&r, 10, 5);

    area(r);

    changeLength(&r, 20);

    return 0;
}
