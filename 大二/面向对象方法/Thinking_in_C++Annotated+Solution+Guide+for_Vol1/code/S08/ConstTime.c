//: S08:ConstTime.c
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include <stdio.h>
#include <time.h>

int main() {
    const time_t now = time(0);
    printf("%ld", now);
}

/* Output:
949180534
*/
///:~
