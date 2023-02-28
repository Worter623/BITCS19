//: S13:ClassHeap.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <cstdio>
#include <new>
#include <cstddef> // For size_t
using namespace std;

class OwnHeap {
public:
    OwnHeap() {
        printf("OwnHeap::OwnHeap()\n");
    }
    ~OwnHeap() {
        printf("OwnHeap::~OwnHeap()\n");
    }
    static void* operator new(size_t) throw(bad_alloc);
    static void operator delete(void*, size_t);
    static void* operator new[](size_t sz) throw(bad_alloc);
    static void operator delete[](void* p, size_t);
};

void* OwnHeap::operator new(size_t size) throw(bad_alloc) {
    for (;;) {
        void* block = ::operator new(size);
        
        if (block) {
            printf("OwnHeap::operator new() allocating "
                   "%lu bytes in %p\n",
                   static_cast<unsigned long>(size), block);
            return block;
        }
        
        new_handler globalHandler = set_new_handler(0);
        set_new_handler(globalHandler);
        
        if (globalHandler)
            globalHandler();
        else
            throw bad_alloc();
    }
}

void OwnHeap::operator delete(void* p, size_t size) {
    printf("OwnHeap::operator delete freeing %lu bytes in %p\n",
           static_cast<unsigned long>(size), p);
    ::operator delete(p);
}

void* OwnHeap::operator new[](size_t size) throw(bad_alloc) {
    printf("OwnHeap::operator new[]() calling "
           "OwnHeap::operator new(%lu)\n",
           static_cast<unsigned long>(size));
    return operator new(size);
}

void OwnHeap::operator delete[](void* p, size_t size) {
    printf("OwnHeap::operator delete[]() calling "
           "OwnHeap::operator delete(%p, %lu)\n",
           p, static_cast<unsigned long>(size));
    operator delete(p, size);
}

int main() {
    OwnHeap* p = new OwnHeap;
    OwnHeap* pa = new OwnHeap[2];
    delete p;
    delete [] pa;
}

/* Output (yours may vary):
OwnHeap::operator new() allocating 1 bytes in 0x804a7e8
OwnHeap::OwnHeap()
OwnHeap::operator new[]() calling OwnHeap::operator new(6)
OwnHeap::operator new() allocating 6 bytes in 0x804a7f8
OwnHeap::OwnHeap()
OwnHeap::OwnHeap()
OwnHeap::~OwnHeap()
OwnHeap::operator delete freeing 1 bytes in 0x804a7e8
OwnHeap::~OwnHeap()
OwnHeap::~OwnHeap()
OwnHeap::operator delete[]() calling OwnHeap::operator delete(0x804a7f8, 6)
OwnHeap::operator delete freeing 6 bytes in 0x804a7f8 
*/
///:~
