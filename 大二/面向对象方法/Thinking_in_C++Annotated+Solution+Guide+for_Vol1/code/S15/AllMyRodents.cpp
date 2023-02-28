//: S15:AllMyRodents.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <vector>
#include <cstddef> // For size_t
using namespace std;

class Rodent {
public:
    virtual ~Rodent() {cout << "~Rodent\n";}
    virtual void eat() = 0;
    virtual void infest() = 0;
    virtual void squeak() = 0;
};

class Mouse : public Rodent {
public:
    ~Mouse() {cout << "~Mouse\n";}
    void eat() {cout << "Mouse::eat\n";}
    void infest() {cout << "Mouse::infest\n";}
    void squeak() {cout << "Mouse::squeak\n";}
};

class Gerbil : public Rodent {
public:
    ~Gerbil() {cout << "~Gerbil\n";}
    void eat() {cout << "Gerbil::eat\n";}
    void infest() {cout << "Gerbil::infest\n";}
    void squeak() {cout << "Gerbil::squeak\n";}
};

class Hamster : public Rodent {
public:
    ~Hamster() {cout << "~Hamster\n";}
    void eat() {cout << "Hamster::eat\n";}
    void infest() {cout << "Hamster::infest\n";}
    void squeak() {cout << "Hamster::squeak\n";}
};

void doRodentThings(vector<Rodent*>& v) {
    for (size_t i = 0; i < v.size(); ++i)
    {
        v[i]->eat();
        v[i]->infest();
        v[i]->squeak();
    }
}

int main() {
    vector<Rodent*> v;
    v.push_back(new Mouse);
    v.push_back(new Gerbil);
    v.push_back(new Hamster);
    doRodentThings(v);

    // Clean up:
    for (int i = 0; i < v.size(); ++i)
        delete v[i];
}

/* Output:
Mouse::eat
Mouse::infest
Mouse::squeak
Gerbil::eat
Gerbil::infest
Gerbil::squeak
Hamster::eat
Hamster::infest
Hamster::squeak
~Mouse
~Rodent
~Gerbil
~Rodent
~Hamster
~Rodent
*/
///:~
