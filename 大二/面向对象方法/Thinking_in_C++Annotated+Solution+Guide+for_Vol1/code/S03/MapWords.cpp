//: S03:MapWords.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//  Maps words to numbers
#include <iostream>
#include <string>
#include <cstdio>

int main() {
    using namespace std;

    string word;
    for (;;) {
        int code;
        cin >> word;
        if (word == "exit" | word == "return")
            break;

        // Map words:
        if (word == "a" || word == "an" || word == "the")
            code = 0;
        else if (word == "after" || word == "before" ||
                 word == "beside" || word == "by" ||
                 word == "for" || word == "from" ||
                 word == "in" || word == "into" ||
                 word == "of" || word == "to")
            code = 1;
        else if (word == "if" || word == "else")
            code = 2;
        else if (word == "who" || word == "what" ||
                 word == "when" || word == "where" ||
                 word == "why")
            code = 3;
        else
            code = 4;

        // Print code description:
        switch (code) {
        case 0:
            puts("article");
            break;
        case 1:
            puts("preposition");
            break;
        case 2:
            puts("conditional");
            break;
        case 3:
            puts ("interrogative");
            break;
        default:
            puts("unmapped word");
            break;
        }
    }
    return 0;
} ///:~
