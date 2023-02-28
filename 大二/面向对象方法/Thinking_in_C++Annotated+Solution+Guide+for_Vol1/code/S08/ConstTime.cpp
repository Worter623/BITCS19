//: S08:ConstTime.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <ctime>
using namespace std;
    
const time_t now = time(0);

int main() {
    cout << static_cast<long>(now) << endl;
//  now = time(0);
//  cout << static_cast<long>(now) << endl;
}

/* Output:
949180534
*/
///:~
