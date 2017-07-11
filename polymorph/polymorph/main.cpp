//
//  main.cpp
//  polymorph
//
//  Created by Adi Bangun on 10/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;
class A {
public:
    virtual void output()=0;
};

class B:public A{
public:
    B(){}
    void output(){
        cout << "this is B" << endl;
    }
};

class C: public A{
public:
    C(){}
    void output(){
        cout << "this is C" << endl;
    }
};

void output(A *a){
    a->output();
}
int main(){

    int arr[2][2];
    B b;
    C c;
    output(&b);
    output(&c);
    return 0;
}

