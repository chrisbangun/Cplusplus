//
//  main.cpp
//  printRCombinations
//
//  Created by Adi Bangun on 25/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;

/*
    start & end : start and end index in arr
    index: current index in data
    r: size of combination to be printed
 */
int compare(const int& a, const int &b){
    return (*(int*)a - *(int*)b);
}
void combinationUtil(int *arr,int *data, int start, int end, int index, int r){
    if(index==r){
        for(int i=0;i<index;i++)
            cout << data[i] << "";
        cout << endl;
        return;
    }
    for(int i=start; i<=end && end-i+1 >= r-index;i++){
        data[index] = arr[i];
        combinationUtil(arr,data,i+1,end,index+1,r);
    }
    
}

void printCombination(int *arr, int n, int r){
    int data[r];
    
    combinationUtil(arr,data,0,n-1,0,r);
}

int main(int argc, const char * argv[]) {
    int arr[] = {1,2,1};
    int size = (int)sizeof(arr)/sizeof(arr[0]);
    int r = 2;
    printCombination(arr,size,r);
    return 0;
}
