//: S08:ConstReference.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
// Constant reference arg/return

void t(int&) {}

void u(const int& cir) {
    int i = cir;
}

const int& w() {
    static int i;
    return i;
}

int main() {
    int x = 0;
    int& ir = x;
    const int& cir = x;
    
    t(ir);
    //! t(cir);         // Not OK
    
    u(ir);
    u(cir);
    
    //! int& ip2 = w(); // Not OK
    const int& cir2 = w();
    //! w() = 1;        // Not OK
} ///:~
