//: S14:BusinessTraveler.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <string>
using namespace std;

class Traveler {
    string str;
public:
    Traveler(const string& s) : str(s) {}
    Traveler(const Traveler& t) : str(t.str) {}
    Traveler& operator=(const Traveler& t) {
        if (this != &t)
            str = t.str;
        return *this;
    }
    string getString() const {
        return str;
    }
};

class Pager {
    string str;
public:
    Pager(const string& s) : str(s) {}
    Pager(const Pager& p) : str(p.str) {}
    Pager& operator=(const Pager& p) {
        if (this != &p)
            str = p.str;
        return *this;
    }
    string getString() const {
        return str;
    }
};

class BusinessTraveler : public Traveler {
    Pager pager;
public:
    BusinessTraveler() : Traveler(""), pager("") {}
    BusinessTraveler(const string& t, const string& p)
        : Traveler(t), pager(p) {}
    BusinessTraveler(const BusinessTraveler& b)
        : Traveler(b), pager(b.pager) {}
    BusinessTraveler& operator=(const BusinessTraveler& b) {
        if (this != &b) {
            Traveler::operator=(b); // Assign base part
            pager = b.pager;        // Assign derived part
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os,
                               const BusinessTraveler& b) {
        return os << "{\"" << b.getString() << "\", \""
                  << b.pager.getString() << "\"}";
    }
};

int main() {
    BusinessTraveler b1("Joe BusinessMan", "Pager 1");
    cout << b1 << endl;
    BusinessTraveler b2("Jane BusinessWoman", "Pager 2");
    cout << b2 << endl;
    BusinessTraveler b3;
    cout << b3 << endl;
    BusinessTraveler b4(b1);
    cout << b4 << endl;
    b3 = b2;
    cout << b3 << endl;
}

/* Output:
{"Joe BusinessMan", "Pager 1"}
{"Jane BusinessWoman", "Pager 2"}
{"", ""}
{"Joe BusinessMan", "Pager 1"}
{"Jane BusinessWoman", "Pager 2"}*/
///:~
