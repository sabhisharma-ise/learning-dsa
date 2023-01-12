// Instead of using an intialize function, we can directly create a Constructor in the class Rectangle 
// And at the time of declaration of object we can intialize it directly there.

#include <iostream>
using namespace std;

class Rectangle {

    private:
    int length;
    int breadth;

    public:
    // Constructor for initializing values of rectangle
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    // Member Functions of the class Rectangle
    int area() {
        return length * breadth;
    }

    void changeLength(int l) {
        length = l;
    }
};

int main () {

    Rectangle r(10, 5);    // Declare and Initialize

    r.area();

    r.changeLength(20);

    return 0;
}
