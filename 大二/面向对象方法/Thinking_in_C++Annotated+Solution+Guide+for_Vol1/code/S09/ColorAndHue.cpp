//: S09:ColorAndHue.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <cassert>

enum Hue {RED, BLUE, YELLOW};

const char* printHue(Hue h) {
    static const char* hues[] = {"red", "blue", "yellow"};
    assert(RED <= h && h <= YELLOW);
    return hues[h];
}
            
class Color {
    Hue hue_;
public:
    Color(Hue h) : hue_(h){}
    Hue hue() const {
        return hue_;
    }
    void hue(Hue h) {
        hue_ = h;
    }
};

int main() {
    using namespace std;
    Color c(BLUE);
    cout << printHue(c.hue()) << endl;
    c.hue(RED);
    cout << printHue(c.hue()) << endl;
}

/* Output:
blue
red
*/
///:~
