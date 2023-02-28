//: S04:GetSet.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

struct HasInt {
    int x;
    void setInt(int newX) {
        x = newX;
    }
    int getInt() {
        return x;
    }
};

int main() {
    HasInt h;
    h.setInt(5);
    cout << h.getInt() << endl; // 5
}
///:~
