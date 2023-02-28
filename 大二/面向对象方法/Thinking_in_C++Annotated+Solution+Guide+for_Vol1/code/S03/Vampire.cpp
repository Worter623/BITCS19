//: S03:Vampire.cpp
// From "Thinking in C++, 2nd Edition, Volume 1, Annotated Solutions Guide"
// by Chuck Allison, (c) 2001 MindView, Inc. all rights reserved
// Available at www.BruceEckel.com.
#include<iostream.h>

int main() {
  int num1, num2, product, startDigit[4], 
    productDigit[4], count = 0, vampCount = 0, 
    x, y;
  for(num1 = 10; num1 <= 99; num1++) {
    for(num2 = 10; num2 <= 99; num2++) {
      product = num1 * num2;
      startDigit[0] = num1 / 10;
      startDigit[1] = num1 % 10;
      startDigit[2] = num2 / 10;
      startDigit[3] = num2 % 10;
      productDigit[0] = product / 1000;
      productDigit[1] = (product % 1000) / 100;
      productDigit[2] = product % 1000 % 100/10;
      productDigit[3] = product % 1000 % 100%10;
      count = 0;
      for(x = 0; x < 4; x++) {
        for(y = 0; y < 4; y++) {
          if (productDigit[x] == startDigit[y]) {
            count++;
            productDigit[x] = -1;
            startDigit[y] = -2;
            if (count == 4) {
              vampCount++;
              if (vampCount < 10)
                cout << "Vampire number  " 
                  << vampCount << " is " 
                  << product << "  " << num1 
                  << num2 << endl;
              else
                cout << "Vampire number " 
                  << vampCount << " is " 
                  << product << "  " << num1 
                  << num2 << endl;
            }
          }
        }
      }
    }
  }
} ///:~
