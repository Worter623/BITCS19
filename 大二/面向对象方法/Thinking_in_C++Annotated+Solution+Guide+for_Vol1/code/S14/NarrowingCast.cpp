//: S14:NarrowingCast.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//=M @echo Compile NarrowingCast.cpp by hand!

class SpaceShip {
public:
    void fly() {}
};

class Shuttle : public SpaceShip {
public:
    void land() {}
};

int main() {
    Shuttle shut;
    SpaceShip& ship = static_cast<SpaceShip&>(shut);
    ship.land();    // Error!!!
}

/* Output:
Error Line 16: 'land' is not a member of 'SpaceShip' in function main()
*/
///:~
