//: S04:UsesThis.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

struct HasInt {
    int x;
    void setInt(int x) {
        this->x = x;
    }
    int getInt() {
        return this->x;
    }
    void display() {
        cout << this->getInt() << endl;
    }
};

int main() {
    HasInt h;
    h.setInt(5);
    h.display(); // 5
}
///:~
