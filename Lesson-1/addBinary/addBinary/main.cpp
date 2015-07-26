//
//  main.cpp
//  addBinary
//
//  Created by Adi Bangun on 08/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char **argv){
    string a,b;
    cin >> a >> b;
    int sizeA = (int) a.length();
    int sizeB = (int) b.length();
    int decimalA = 0;
    int decimalB = 0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<sizeA;i++){
        if(a.at(i)=='1'){
            decimalA += 1<<i;
        }
    }
    
    for(int i=0;i<sizeB;i++){
        if(b.at(i)=='1'){
            decimalB+= 1<<i;
        }
    }
    cout << decimalA << " " << decimalB << endl;
    int sum = decimalA + decimalB;
    int _sum = sum;
    string result = "";
    
    while(sum!=0){
        if(sum%2!=0){
            result+="1";
        }else result+="0";
        sum=sum/2;
    }
    if(!result.empty())
        reverse(result.begin(),result.end());
    else result="0";
    
    cout << "decimal: " << _sum << " binary " << result << endl;
    
    return 0;
}