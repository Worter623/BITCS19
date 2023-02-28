//: S04:Nested.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>

struct Outer {
    int o;
    void setO(int n) {
        o = n;
    }
    int getO() {
        return o;
    }
    struct Inner {
        int i;
        void setI(int n) {
            i = n;
        }
        int getI() {
            return i;
        }
    };
};

int main() {
    using namespace std;
    
    Outer o;
    o.setO(1);
    cout << o.getO() << endl;
    
    Outer::Inner i;
    i.setI(2);
    cout << i.getI() << endl;
}

/* Output:
1
2
*/
///:~
