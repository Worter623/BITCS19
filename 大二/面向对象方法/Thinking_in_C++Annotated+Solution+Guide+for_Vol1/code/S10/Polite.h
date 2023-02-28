//: S10:Polite.h
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#ifndef POLITE_H
#define POLITE_H
#include <iostream>
#include <string>

class Polite {
    std::string data;
public:
    Polite(const std::string& s) : data(s) {}
    void print() {
        std::cout << "data == " << data << std::endl;
    }
};
#endif ///:~
