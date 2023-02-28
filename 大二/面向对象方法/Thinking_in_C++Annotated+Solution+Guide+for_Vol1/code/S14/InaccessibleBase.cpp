//: S14:InaccessibleBase.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
//=M @echo Compile InaccessibleBase.cpp by hand!
class Base {};
class Private : private Base {};
class Protected : protected Base {};

int main() {
    Private pri;
    Protected pro;
    
    // Both statements are errors:
    Base* b = static_cast<Base*>(&pri);
    b = static_cast<Base*>(&pro);
}

/* Output:
Error Line 12: Cannot cast from 'Private *' to 'Base *' in function main()
Error Line 13: Cannot cast from 'Protected *' to 'Base *' in function main()
*/
///:~
