// Passing of array as parameter in a function takes place always through call by address
// Writing A[] denotes a Pointer to an Array

#include <iostream>
using namespace std;

void fun(int A[], int n) {    // Instead of A[], we can also use *A 
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
}

int main () {

    int A[5] = {1, 2, 3, 4, 5};

    fun(A, 5);

    return 0;
}