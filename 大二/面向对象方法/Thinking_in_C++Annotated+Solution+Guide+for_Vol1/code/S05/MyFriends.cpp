//: S05:MyFriends.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class HasStuff;     // Must precede GoodFriend definition

class GoodFriend {  // Must precede HasStuff definition
public:
    void hasAccess(HasStuff* p);
    void hasNoAccess(HasStuff* p) {
        cout << "Cannot access " << p << endl;
    }
};

class HasStuff {
private:
    int x;

    friend class BestFriend;
    friend void GoodFriend::hasAccess(HasStuff*);
};

// Must follow HasStuff definition:
void GoodFriend::hasAccess(HasStuff* p) {
    cout << "From GoodFriend::hasAccess: " << p->x << endl;
}

// All methods of BestFriend have access to HasStuff::x
// This must also follow the HasStuff definition:
class BestFriend {
public:
    void initFriend(HasStuff* p) {
        p->x = 5;
    }
    void queryFriend(HasStuff* p) {
        cout << "From BestFriend: " << p->x << endl;
    }
};

int main() {
    HasStuff h;
    
    BestFriend b;
    b.initFriend(&h);
    b.queryFriend(&h);
    
    GoodFriend g;
    g.hasAccess(&h);
    g.hasNoAccess(&h);
}

/* Output:
From BestFriend: 5
From GoodFriend::hasAccess: 5
Cannot access 0065FE00
*/
///:~
