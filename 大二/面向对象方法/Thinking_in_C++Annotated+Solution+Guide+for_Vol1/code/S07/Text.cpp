//: S07:Text.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Text {
    string text;
public:
    Text() {}
    Text(const string& fname) {
        ifstream ifs(fname.c_str());
        string line;
        while (getline(ifs, line))
            text += line + '\n';
    }
    string contents() {
        return text;
    }
};

int main(int argc, char* argv[]) {
    if (argc > 1)
    {
        Text t1;
        Text t2(argv[1]);
        cout << "t1 :\n" << t1.contents() << endl;
        cout << "t2 :\n" << t2.contents() << endl;
    }
}
///:~
