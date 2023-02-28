//: S13:Counted.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class Counted {
    int id;
    static int count;
public:
    Counted() : id(count++) {
        cout << "Creating Counted(" << id << ")\n";
    }
    ~Counted() {
        cout << "Destroying Counted(" << id << ")\n";
    }
};

int Counted::count = 0;

int main() {
    Counted* c = new Counted;
    delete c;
    
    Counted * const a = new Counted[3];
    delete [] a;
}

/* Output:
Creating Counted(0)
Destroying Counted(0)
Creating Counted(1)
Creating Counted(2)
Creating Counted(3)
Destroying Counted(3)
Destroying Counted(2)
Destroying Counted(1)
*/
///:~
