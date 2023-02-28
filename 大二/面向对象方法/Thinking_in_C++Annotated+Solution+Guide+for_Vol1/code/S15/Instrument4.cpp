//: S15:Instrument4.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// www.BruceEckel.com. See copyright notice in CopyRight.txt.
// Simulate Virtual Functions (sort of)
#include <iostream>
#include <cassert>
using namespace std;

enum note { middleC, Csharp, Cflat }; // Etc.

class Instrument {
public:
  virtual ~Instrument(){}
  void play(note) const;
  const char* what() const;
};

class Wind : public Instrument {
public:
  void play(note) const {
    cout << "Wind::play" << endl;
  }
  const char* what() const { return "Wind"; }
};

class Percussion : public Instrument {
public:
  void play(note) const {
    cout << "Percussion::play" << endl;
  }
  const char* what() const { return "Percussion"; }
};

class Stringed : public Instrument {
public:
  void play(note) const {
    cout << "Stringed::play" << endl;
  }
  const char* what() const { return "Stringed"; }
};

class Brass : public Wind {
public:
  void play(note) const {
    cout << "Brass::play" << endl;
  }
  const char* what() const { return "Brass"; }
};

class Woodwind : public Wind {
public:
  void play(note) const {
    cout << "Woodwind::play" << endl;
  }
  const char* what() const { return "Woodwind"; }
};

void Instrument::play(note n) const {
  if (const Woodwind* pww = 
    dynamic_cast<const Woodwind*>(this))
      pww->play(n);
  else if (const Percussion* pp =
    dynamic_cast<const Percussion*>(this))
      pp->play(n);
  else if (const Stringed* ps =
    dynamic_cast<const Stringed*>(this))
      ps->play(n);
  else if (const Brass* pb = 
    dynamic_cast<const Brass*>(this))
      pb->play(n);
    else if (const Wind* pw = 
      dynamic_cast<const Wind*>(this))
        pw->play(n);
    else
        cout << "Instrument::play" << endl;
}

const char* Instrument::what() const {
  if (const Woodwind* pww = 
    dynamic_cast<const Woodwind*>(this))
      return pww->what();
  else if (const Percussion* pp =
    dynamic_cast<const Percussion*>(this))
      return pp->what();
  else if (const Stringed* ps =
    dynamic_cast<const Stringed*>(this))
      return ps->what();
  else if (const Brass* pb = 
    dynamic_cast<const Brass*>(this))
      return pb->what();
  else if (const Wind* pw = 
    dynamic_cast<const Wind*>(this))
      return pw->what();
  else
    return "Instrument";
}

void play(Instrument& i) {
  cout << "Playing a " << i.what() << "... ";
  i.play(middleC);
}

int main() {
  Wind flute;
  Percussion drum;
  Stringed violin;
  Brass flugelhorn;
  Woodwind recorder;
  play(flute);
  play(drum);
  play(violin);
  play(flugelhorn);
  play(recorder);
}

/* Output:
Playing a Wind... Wind::play
Playing a Percussion... Percussion::play
Playing a Stringed... Stringed::play
Playing a Brass... Brass::play
Playing a Woodwind... Woodwind::play
*/
///:~
