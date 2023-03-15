// Student Information such as name, rollNo, dept, etc

#include <iostream>
using namespace std;

struct studentInfo {
    int rollNo;
    string name;
    string dept;
};

int main () {

    struct studentInfo s;

    s.rollNo = 1;
    s.name = "Sabhi";
    s.dept = "ISE";

    cout << s.rollNo << " ";
    cout << s.name << " ";
    cout << s.dept << " ";

    return 0;
}