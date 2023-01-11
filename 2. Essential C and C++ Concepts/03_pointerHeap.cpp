// To access the Heap Memory with the help of pointer
// We have to use malloc function, which is used to allocate the memory dynamically in heap

#include <iostream>
#include <stdlib.h> // for malloc in C
using namespace std;

int main () {

    int *p;

    // It is like there is a block of memory in the heap (an array) and we are using a pointer to hold it (p = address of first element of block)
    // and using the pointer we can access the whole array

    // In C
    p = (int *)malloc(5 * sizeof(int)); // We have type-casted to integer type becuase the first value of malloc will return void pointer
    
    // In C++
    p = new int[5];

    return 0;
}