//
//  main.cpp
//  BaseArithmetic_Bloomberg
//
//  Created by Adi Bangun on 23/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <math.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;

int findBase(string input){
    int max = 0;
    int cX;
    int size = (int) input.length();
    for(int i=0;i<size;i++){
        if(input.at(i) >= 'A' && input.at(i) <='Z'){
            cX = (input.at(i)-'A')+10;
        }
        else
            cX = input.at(i)-'0';
        max = MAX(max,cX);
    }
    return max+1;
}

long long int convertTo10(string input, int base){
    int size = (int)input.length()-1;
    long long int ans =0;
    int c;
    for(int i=size;i>=0;i--){
        if(input.at(i)>='A' && input.at(i)<='Z')
            c = (input.at(i)-'A') + 10;
        else
            c = input.at(i)-'0';
        if(size-i==0)
            ans+= (c*1);
        else{
            long long int kPow = pow(base,size-i);
            ans+= (c*kPow);
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    string X;
    string Y;
    cin >> X >> Y;
    long long int ans;
    int baseX = findBase(X);
    int baseY = findBase(Y);
    ans = convertTo10(X,baseX) + convertTo10(Y,baseY);
    cout << ans << endl;
    return 0;
}
