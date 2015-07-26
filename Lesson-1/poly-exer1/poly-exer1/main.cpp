//
//  main.cpp
//  poly-exer1
//
//  Created by Adi Bangun on 12/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;
class Sieve{
public:
    virtual int nextNumber()=0;

};

class SourceSieve:public Sieve{
public:
    SourceSieve():_i(1){}
    int nextNumber();
private:
    int _i;
};

class Sieve2:public Sieve{
public:
    Sieve2(Sieve &source):_src(source){}
    int nextNumber();
private:
    Sieve & _src;

};

int SourceSieve::nextNumber(){
    if(_i > 100)
        return -1;
    return _i++;
}

int Sieve2::nextNumber(){
    int i;
    do{
        i = _src.nextNumber();
    }while(i%2==0 && i!=-1 && i!=2);
    return i;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    SourceSieve source;
    Sieve2 sieve(source);
    while(true){
        int i = sieve.nextNumber();
        if(i==-1)
            break;
        cout << i << endl;
    }
    return 0;
}
