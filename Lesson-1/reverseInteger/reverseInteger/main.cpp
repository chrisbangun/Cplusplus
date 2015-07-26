//
//  main.cpp
//  reverseInteger
//
//  Created by Adi Bangun on 05/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;
int reverseDigit(int N,int flag){
    int reversed = 0;
    while(N>0){
        int mod = N%10;
        reversed = reversed*10 + mod;
        N = N/10;
    }
    if(flag==1)
        return 0-reversed;
    return reversed;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    int flag = 0;
    cin >> N;
    if(N < 0){
        flag = 1;
        N = N * -1;
    }
    cout<< "reverse: "<< reverseDigit(N,flag) << endl;
    return 0;
}
