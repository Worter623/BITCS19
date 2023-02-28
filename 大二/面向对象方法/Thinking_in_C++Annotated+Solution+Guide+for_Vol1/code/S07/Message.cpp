//: S07:Message.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <string>
using namespace std;

class Message {
    string msg;
public:
    Message(const string& s = "MSG") : msg(s) {}
    void print() {
        cout << msg << endl;
    }
    void print(const string& suffix) {
        cout << msg << ' ' << suffix << endl;
    }
};


int main() {
    Message m1;
    Message m2("Error");
    m1.print();
    m2.print();
    m1.print("hello");
    m2.print("goodbye");
}

/* Output:
MSG
Error
MSG hello
Error goodbye
*/
///:~
