//
//  main.cpp
//  bitSwap
//
//  Created by Adi Bangun on 18/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;
int bitSwap(int _a,int _b){
    unsigned int count = 0;
    unsigned int c = _a^_b;
    cout << c << endl;
    while(c){
        c &= c-1;
        cout << "c here: " << c << endl;
        ++count;
    }
    return count;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a,b;
    cin >> a >> b;
    int step = bitSwap(a,b);
    cout << step << endl;
    return 0;
}
