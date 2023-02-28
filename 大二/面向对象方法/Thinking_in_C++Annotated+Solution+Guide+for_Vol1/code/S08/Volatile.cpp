//: S08:Volatile.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
class Volatile {
    volatile int x;
public:
    void mod1(int x) {
        this->x = x;
    }
    void mod2(int x) volatile {
        this->x = x;
    }
};

int main() {
    Volatile v1;
    volatile Volatile v2;
    v1.mod1(1);
    v1.mod2(2);
    //! v2.mod1(3);  // Error
    v2.mod2(4);
} ///:~
