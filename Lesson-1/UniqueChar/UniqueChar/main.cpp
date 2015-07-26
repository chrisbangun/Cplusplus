//
//  main.cpp
//  UniqueChar
//
//  Created by Adi Bangun on 16/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//
#include <iostream>
#include <string.h>
using namespace std;

bool isUnique(string _input){
    int size = (int)_input.length();
    //assume that the string will only consist of ASCII characters
    int Ascii[256];
    memset(Ascii,0,256*sizeof(int));
    for(int i=0;i<size;i++){
        int val = _input.at(i);
        //cout << val << endl;
        if(Ascii[val] > 0){
            //cout << Ascii[val] << " " << val << endl;
            return false;
        }
        Ascii[val]++;
    }
    return true;
}

// A bit array or bit vector can be used to implement a simple set data structure

bool isUniqueBitVector(string _input){


    return true;
}

int main(int argc, char **argv){

    string _input;
    cin >> _input;
    if(_input=="")
        cout << "the string is empty" << endl;
    else{
    if(isUnique(_input))
        cout << "The input string has unique characters" << endl;
    else
        cout << "The string has one or more the duplicate character" << endl;
    }
    return 0;
}