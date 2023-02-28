//: S11:PointerToMemArray.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <cstddef> // For size_t

class HasArray {
    size_t siz;
public:
    int* a;
    HasArray(size_t siz) {
        a = new int[siz];
        for (size_t i = 0; i < siz; ++i)
            a[i] = i;
        this->siz = siz;
    }
    ~HasArray() {
        delete a;
    }
    size_t size() const {
        return siz;
    }
};

int main() {
    using namespace std;
    HasArray h(5);
    int* HasArray::* pa = &HasArray::a;
    for (size_t i = 0; i < h.size(); ++i)
        cout << (h.*pa)[i] << ' ';
    cout << endl;
}

/* Output:
0 1 2 3 4
*/
///:~
