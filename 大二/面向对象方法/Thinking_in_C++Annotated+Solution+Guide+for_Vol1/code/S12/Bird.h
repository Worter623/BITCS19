//: S12:Bird.h
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#ifndef BIRD_H
#define BIRD_H

#include <iosfwd>
#include <string>

class Bird {
    static int birdNum;
    std::string id;
public:
    Bird();
    friend std::ostream& operator<<(std::ostream&,
                                    const Bird&);
};
#endif
///:~
