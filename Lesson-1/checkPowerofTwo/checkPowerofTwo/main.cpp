//
//  main.cpp
//  checkPowerofTwo
//
//  Created by Adi Bangun on 18/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;
    bool yes;
    yes = n && !(n&(n-1));
    int x = !(n&(n-1));
    cout << x << endl;
    if(yes)
        cout << n << " is a power of 2" << endl;
    else
        cout << n << " isn't a power of 2" << endl;
    return 0;
}
