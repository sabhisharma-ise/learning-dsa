// Converting the Previous C code to C++ 
// We'll be using Class in C++
// Inside the class, we'll be having members length and breadth, and along them
// member functions - initialize, area, and changeLength
// And to access these member functions, we can directly use r.function in main()

#include <iostream>
using namespace std;

class Rectangle {

    private:
    int length;
    int breadth;

    public:
    // Member Functions of the class Rectangle
    void initialize(int l, int b) {
        length = l;
        breadth = b;
    }

    int area() {
        return length * breadth;
    }

    void changeLength(int l) {
        length = l;
    }
};

int main () {

    Rectangle r;    // This is a Object

    r.initialize(10, 5);    // Member functions are part of the class, so we use dot operator to call them

    r.area();

    r.changeLength(20);

    return 0;
}
