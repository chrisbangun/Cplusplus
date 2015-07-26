//
//  main.cpp
//  arraysNPointer
//
//  Created by Adi Bangun on 08/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

void reverse_string(string _input,int size){
    string reversed = "";
    for(int i=size;i>=0;i--){
        reversed+=_input[i];
    }
    cout << reversed << endl;
}

void reverse_word(char* str, int size){
    int p1,p2;
    p1 = 0;
    p2 = size - 1;
    while(p1 < p2){
        char temp = str[p2];
        str[p2] = str[p1];
        str[p1] = temp;
        p1++;
        p2--;
    }
    cout << str << endl;
}
void reverse_sentence(char *str, int size){
    reverse_word(str,size);
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string input;
    getline(cin,input);
    //cin >> input;
    char *str = &input;
    reverse_word(str,10);
    return 0;
}
