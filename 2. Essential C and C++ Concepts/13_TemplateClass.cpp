// If we want to use private data of a class as integer, float, or any other data type we have to define a template class
// Instead of int (say), we will re-write the T (as we want it to be generic class)

#include <iostream>
using namespace std;

template <class T>
class arithmetic {

    private:
        T a;
        T b;
    
    public:
        arithmetic(T a, T b);

        T add();

        T sub();
};

template <class T>
arithmetic<T>::arithmetic(T a, T b) {
    this.a -> a;
    this.b -> b;
}

template <class T>
T arithmetic<T>::add() {
    T c;
    c = a + b;
    return c;
}

template <class T>
T arithmetic<T>::sub() {
    T c;
    c = a - b;
    return c;
}

int main () {

    arithmetic<int> a(10, 5);   // Specify the data type after class name

    cout << a.add() << " ";

    arithmetic<float> a1(1.5, 1.2);

    cout << a1.add() << " ";

    return 0;
}
