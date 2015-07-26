//
//  main.cpp
//  hiding inherited names
//
//  Created by Adi Bangun on 12/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;
class Base{
public:
    virtual void mf1()=0;
    virtual void mf1(int);
    virtual void mf2();
    void mf3();
    void mf3(double);
private:
    int x;
};

class Derived:public Base{
public:
    virtual void mf1();
    void mf3();
    void mf4();

};
int main(int argc, const char * argv[]) {
    Derived derived;
    int x;
    double y;
    derived.mf1();
    derived.mf1(x);
    derived.mf2();
    derived.mf3();
    derived.mf3(y);
    return 0;
}
