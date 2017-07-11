//
//  main.cpp
//  Initializer List
//
//  Created by Adi Bangun on 23/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;
/*
    1. Initializer list must be used for initialization of non-static const data member:
    class Test{
    private:
        const int t; // must be explicitly initialize in the constructor
    };
 
    2. For initialization of reference members
    class Test{
    private:
        int& t;
 
    };
 
    3. For initialization of member objects which do not have default constructor
    4. For initialization of base class members
    5. When constructor's parameter name is same as data member
    6. For perfomance reasons
 */
class Test{
private:
    const int t;
public:
    Test(int _t):t(_t){}
    int getT(){return this->t;}
    
};

class Test2{
private:
    int& n;
public:
    Test2(int &_n):n(_n){}
    int getN(){return this->n;}
};

class Test3{
    int i;
public:
    Test3(int );
};
Test3::Test3(int arg){
    i = arg;
    cout << "Test3's constructor is called: Value of i:" << i << endl;
}
class Test4{
    Test3 test3;
public:
    Test4(int );
};

Test4::Test4(int arg):test3(arg){ //Constructor must explicitly initialize the member 'test3' which doesn't have a default constructor
    
}

template <typename T>
T compare(const T &a, const T &b){
    return (a > b) ? a:b;
}

int main(int argc, const char * argv[]) {
    Test t(10);
    int x = 15;
    Test2 t2(x);
    cout << t.getT() << endl;
    double max = compare(10.0,10.9);
    cout << max << endl;
    return 0;
}
