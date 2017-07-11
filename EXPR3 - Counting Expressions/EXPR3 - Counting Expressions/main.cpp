//
//  main.cpp
//  EXPR3 - Counting Expressions
//
//  Created by Adi Bangun on 05/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
    // insert code here...
    int N;
    unsigned long long int a[51];
    cin >> N;
    a[1] = 0;
    a[2] = 2;
    a[3] = 68;
    a[4] = 286;
    a[5] = 6760;
    while(N!=0){
        if(N!=0 && N<=5){
            cout << a[N] << endl;
        }
        else{
            for(int i=6;i<=N;i++){
                a[i] = a[i-1]+(98*a[i-2])-(98*a[i-3])-a[i-4]+a[i-5];
            }
            unsigned long long ans = a[N]%499999999999993;
            cout << ans << endl;
        }
        cin >> N;
    }
    return 0;
}
