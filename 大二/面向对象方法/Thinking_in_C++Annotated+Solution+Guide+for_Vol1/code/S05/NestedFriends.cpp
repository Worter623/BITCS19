//: S05:NestedFriends.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
using namespace std;

class Hen {
public:

    class Nest {
        int x;
        friend class Hen;

    public:

        class Egg {
            int y;
            friend class Nest;

        public:    
            void display() {
                cout << "Hen::Nest::Egg::display: " << y << endl;
            }
        };
        
        void initEgg(Egg* e) {
            e->y = 2;
        }
        void display() {
            cout << "Hen::Nest::display: " << x << endl;
        }
    };

    void initNest(Nest* n) {
        n->x = 1;
    }
    void display() {
        cout << "Hen::display\n";
    }
};

int main() {
    Hen h;
    Hen::Nest n;
    Hen::Nest::Egg e;
    
    h.initNest(&n);
    n.initEgg(&e);
    h.display();
    n.display();
    e.display();
}

/* Output:
Hen::display
Hen::Nest::display: 1
Hen::Nest::Egg::display: 2
*/
///:~
