//: S07:MessageWithPrefix.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <string>
using namespace std;

class Message {
    string msg;
public:
    Message(const string& s) : msg(s) {}
    void print() {
        cout << msg << endl;
    }
    void print(const string& prefix) {
        cout << prefix << ": " << msg << endl;
    }
};


int main() {
    Message m("This is a message");
    m.print();
    m.print("Attention");
}

/* Output:
This is a message
Attention: This is a message
*/
///:~
