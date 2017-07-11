//
//  main.cpp
//  nextHigherDigit
//
//  Created by Adi Bangun on 18/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int compare (const void * a, const void * b)
{
    char * a_cmp = ((char *)a)+2;
    char * b_cmp = ((char *)b)+2;
    return strcmp(a_cmp, b_cmp);
}
void swap(string &__number, int x, int y){
    int temp = __number[y];
    __number[y] = __number[x];
    __number[x] = temp;
}
void findNextHigher(string &_number){
    int size = (int)_number.length()-1;
    string s;
    //char *p = &_number[size];
    int pivot;
    int lsb = _number[size];
    for(int i=size-1;i>0;i--){
        if(_number.at(i) > lsb)
            lsb = _number.at(i);
        else{
            
            pivot = i;
            swap(_number,pivot,size);
            string temp = _number.substr(pivot+1,size);
            //qsort(tmp,);
            s.append(_number,pivot);
        }
    }
    cout << s << endl;
}
int main(int argc, const char * argv[]) {
    string number;
    cin >> number;
    findNextHigher(number);
    return 0;
}
