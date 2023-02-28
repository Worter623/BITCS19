//: S03:struct.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string last;
    string first;
    int age;
} Person;

int main() {
    using namespace std;
    Person p;
    p.last = "Einstein";
    p.first = "Albert";
    p.age = 122;
    cout << p.last << ',' << p.first << ',' << p.age << endl;
    
    Person* pptr = &p;
    pptr->last = "Alger";
    pptr->first = "Horatio";
    pptr->age = 167;
    cout << pptr->last << ',' << pptr->first << ',' << pptr->age
         << endl;
}

/* Output:
Einstein,Albert,122
Alger,Horatio,167
*/
///:~
