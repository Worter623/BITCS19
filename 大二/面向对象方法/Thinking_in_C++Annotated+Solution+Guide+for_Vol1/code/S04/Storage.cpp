//: S04:Storage.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>

int main() {
    using namespace std;

    int* p_int = new int;
    long* p_long = new long;
    char* p_chars = new char[100];
    float* p_floats = new float[100];
    
    cout << "p_int == " << p_int << endl;
    cout << "p_long == " << p_long << endl;
    cout << "p_chars == " << static_cast<void*>(p_chars) << endl;
    cout << "p_floats == " << p_floats << endl;
    
    delete p_int;
    delete p_long;
    delete [] p_chars;
    delete [] p_floats;
}

/* Output:
// Compiler A:
p_int == 00673384
p_long == 00673394
p_chars == 006733A4
p_floats == 0067340C
// Compiler B:
p_int == 00770950
p_long == 00770940
p_chars == 007708D0
p_floats == 00770630
*/
///:~
