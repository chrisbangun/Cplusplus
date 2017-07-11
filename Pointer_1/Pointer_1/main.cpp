//
//  main.cpp
//  Pointer_1
//
//  Created by Adi Bangun on 02/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int *i, j[10];
    double *f, g[10];
    int x;
    i = j;
    f = g;
    for(x=0;x<10;x++){
        cout << i+x <<' ' << f+x << "\n";
    }
    return 0;
}
