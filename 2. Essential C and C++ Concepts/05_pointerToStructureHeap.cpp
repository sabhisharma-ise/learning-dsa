// To create a dynamic object in the Heap

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main () {

    struct Rectangle *p;

    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    p->length = 10;
    p->breadth = 20;

    printf("%d ", p->length);
    printf("%d ", p->breadth);

    return 0;
}