//
//  main.cpp
//  bitTwiddling
//
//  Created by Adi Bangun on 23/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    unsigned long long int v;
    cin >> v;
    //finding the largest power of two less than a given number 'v'
    
    //first, determine if the given number is power of two
    bool isPowerOfTwo = true;
    int steps = 1;
    while(v!=1){
        isPowerOfTwo = v && !(v&(v-1));
        if(isPowerOfTwo==true){
            v = v >> 1;
        }
        else{
            unsigned long long int largestPower = v;
            largestPower |= largestPower >> 1;
            largestPower |= largestPower >> 2;
            largestPower |= largestPower >> 4;
            largestPower |= largestPower >> 8;
            largestPower |= largestPower >> 16;
            largestPower |= largestPower >> 32;
            largestPower = (largestPower>>1) + 1;
            v = v - largestPower;
        }
        steps++;
            
    }
    if(steps%2==0)
        cout << "Louise" << endl;
    else
        cout << "Richard" << endl;
    return 0;
}
