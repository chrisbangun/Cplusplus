//
//  main.cpp
//  Test1
//
//  Created by Adi Bangun on 25/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <string.h>
#define MIN(a,b) ((a)<(b) ? (a):(b))
using namespace std;
int getMaxLost(int *List,int size){
    if(size==0)
        throw "No data in the list";
    int max = 0;
    int maxIndex = 0;
    for(int i=0;i<size;i++){
        if(List[i] >= max){
            max = List[i];
            maxIndex = i;
        }
    }
    int min = INT_MAX;
    for(int i=maxIndex;i<size;i++){
        min = MIN(min,List[i]);
    }
    return max - min;
}

int main(int argc, const char * argv[]) {
    int L[]={20,3,14,16,7,39,4,15};
    cout << getMaxLost(L,8);
    return 0;
}
