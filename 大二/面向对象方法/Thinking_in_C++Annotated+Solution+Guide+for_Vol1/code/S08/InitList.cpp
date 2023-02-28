//: S08:InitList.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class HasFloats {
    const float x_;
    float y_;
public:
    HasFloats(float x, float y)
        : x_(x), y_(y)
    {}
    void display() const {
        cout << "x == " << x_ << ", y == " << y_ << endl;
    }
};

int main() {
    HasFloats h(3,4);
    h.display();
}

/* Output:
x == 3, y == 4
*/
///:~
