// Implementing a Class 'Rectangle' in C++ from scratch
// We will be defining the member functions of the class outisde using the scope resolution (::)

#include <iostream>
using namespace std;

class Rectangle {

    private:
    int length;
    int breadth;

    public:
    Rectangle() { length = breadth = 1; }
    Rectangle(int l, int b);
    int area();
    int perimeter();
    void setLength(int l) { length = l; }
    int getLength() { return length; }
    ~Rectangle();   // Destructor
};

Rectangle::Rectangle(int l, int b) {
    length = l;
    breadth = b;
}

Rectangle::area() {
    return length * breadth;
}

Rectangle::perimeter() {
    return 2 * (length + breadth);
}

Rectangle::~Rectangle() {

}

int main () {

    Rectangle r(10, 5);

    cout << r.area() << " ";

    cout << r.perimeter() << " ";

    r.setLength(20);

    cout << r.getLength() << " ";

    return 0;
}