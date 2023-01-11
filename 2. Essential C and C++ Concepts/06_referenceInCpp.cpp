// A reference variable is an alias, that is, another name for an already existing variable.
// Actual use of refernce is Parameter Passing.

#include <iostream>
using namespace std;

int main () {

    int a = 10;
    int &r = a; // Reference to variable 'a'

    cout << a << " ";
    cout << r;

    return 0;
}