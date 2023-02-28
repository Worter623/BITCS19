//: S12:CopyAssign.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <string>
using namespace std;

#define eval(expr) display(#expr, expr)

class HasString {
    string str;
public:
    HasString(const string& s) : str(s) {}
    friend ostream& 
    operator<<(ostream& os, const HasString& hs) {
        return os << hs.str;
    }
};

class HasString2 {
    HasString str2;
public:
    HasString2(const HasString& s2) : str2(s2) {}
    friend ostream& 
    operator<<(ostream& os, const HasString2& hs2) {
        return os << hs2.str2;
    }
};

void display(const char* s, const HasString2& res) {
    using namespace std;
    cout << s << " = " << res << endl;
}

int main() {
    HasString s1("Buzz");
    eval(s1);
    {
        HasString s2(s1);
        eval(s2);
    }
    HasString s2(s1);
    s1 = HasString("Lightyear");
    eval(s1);
    eval(s2);
    cout << endl;
    
    HasString2 t1(HasString("Buzz"));
    eval(t1);
    {
        HasString2 t2(t1);
        eval(t2);
    }
    HasString2 t2(t1);
    t1 = HasString2(HasString("Lightyear"));
    eval(t1);
    eval(t2);
}

/* Output:
s1 = Buzz
s2 = Buzz
s1 = Lightyear
s2 = Buzz

t1 = Buzz
t2 = Buzz
t1 = Lightyear
t2 = Buzz
*/
///:~
