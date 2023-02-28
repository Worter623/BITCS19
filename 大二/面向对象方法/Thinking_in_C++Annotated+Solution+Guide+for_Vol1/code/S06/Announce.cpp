//: S06:Announce.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class Announce {
    int x;
public:
    Announce(int x) {
        this->x = x;
        cout << "Announce(" << x << ")\n";
    }
    ~Announce() {
        cout << "~Announce(" << x << ")\n";
    }
};

int main() {
    using namespace std;
    Announce a1(1);
    Announce a2(2);
    {
        Announce a3(3);
        Announce a4(4);
        goto jump;
        Announce a5(5);
    }
jump:
    Announce a6(6);
    cout << "After jumping!\n";
}

/* Output:
Announce(1)
Announce(2)
Announce(3)
Announce(4)
~Announce(4)
~Announce(3)
Announce(6)
~Announce(6)
~Announce(2)
~Announce(1)
*/
///:~
