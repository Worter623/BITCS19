//: S12:BirdHouse.h
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#ifndef BIRDHOUSE_H
#define BIRDHOUSE_H
#include "Bird.h"

class BirdHouse {
    // Feathered friends:
    Bird val;
    Bird* ptr;
    Bird& ref;
    
    // Disallowed ops:
    BirdHouse(const BirdHouse&);
    BirdHouse& operator=(const BirdHouse&);
    
public:
    BirdHouse(const Bird& v, Bird* p, Bird& r)
    : val(v), ref(r) {
        ptr = p;
    }
       
    friend std::ostream& operator<<(std::ostream&,
                                    const BirdHouse&);
};

#endif
///:~
