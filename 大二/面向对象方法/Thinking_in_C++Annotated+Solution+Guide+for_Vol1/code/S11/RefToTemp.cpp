//: S11:RefToTemp.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//=M @echo compile RefToTemp.cpp by hand
#include <iostream>

class Simple {
    int i;
public:
    Simple() : i(1) {}
    int getI() const {
        return i;
    }
    void setI(int n) {
        i = n;
    }
};

Simple f() {
    return Simple();
}

void g(Simple& s) {
    using namespace std;
    cout << "before: " << s.getI() << endl;
    s.setI(2);
    cout << "after: " << s.getI() << endl;
}

int main() {
    g(f());
}
///:~
