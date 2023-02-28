//: S09:LinkError.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//=M @echo compile and link LinkError.cpp by hand
int main() {
    extern void f();
    f();
} ///:~
