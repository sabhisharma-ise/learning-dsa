// Returning of array from a function
//

#include <iostream>
using namespace std;

int * fun(int n) {

    int *p;
    p = (int *)malloc(n*sizeof(int));
    return (p);

}

int main () {

    int * A;
    
    A = fun(5);

    return 0;
}