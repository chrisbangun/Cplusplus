//
//  main.cpp
//  Count0's
//
//  Created by Adi Bangun on 16/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//
#include <iostream>
#include <string.h>
using namespace std;

int count0s(string input, int l, int r){
    if(l>=r){
        if(input.at(l)=='0')
            return l+1;
        return l;
    }
    int mid = (l+r)/2;
    if(input.at(mid)=='0')
          return count0s(input,mid+1,r);
    else
          return count0s(input,l,mid-1);
    
    return l;
}

int main(int argc, char** argv){
    string input;
    cin >> input;
    int size = (int) input.length();
    int result = count0s(input,0,size-1);
    cout << result<< endl;
    
    return 0;
}


