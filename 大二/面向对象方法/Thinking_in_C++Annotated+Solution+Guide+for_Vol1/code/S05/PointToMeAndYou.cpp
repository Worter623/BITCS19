//: S05:PointToMeAndYou.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class You;  // Forward declaration

class Me {
public:
    void ProcessYou(You* p) {
        cout << "Processing You at " << p << endl;
    }
};

class You {
public:
    void ProcessMe(Me* p) {
        cout << "Processing Me at " << p << endl;
    }
};

int main() {
    Me me;
    You you;
    
    me.ProcessYou(&you);
    you.ProcessMe(&me);
}

/* Output:
Processing You at 0065FDF4
Processing Me at 0065FDFC
*/
///:~
