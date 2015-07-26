//
//  main.cpp
//  Error Handling
//
//  Created by Adi Bangun on 13/07/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;
class MyClass{
public:
    void MyFunc(char c){
        if(c > numeric_limits<char>::max())
            throw invalid_argument("MyFunc argument too large");
        else
            cout << c << endl;
    }
    int compare(int a,int b);

};
int MyClass::compare(int a, int b){
    if(a < 0  || b < 0)
        throw invalid_argument("received negative value");
    else
        return a < b ? a:b;
}
int main(int argc, const char * argv[]) {
    MyClass myClass;
    int result;
    try{
        myClass.MyFunc(2);
        result = myClass.compare(-1,3);
    }catch(invalid_argument& e){
        cerr << e.what() << endl;
        return -1;
    }catch(...){cout << "here" << endl;} //ellipsis, will catch any exception no matter what the type of the exception thrown
    return 0;
}
