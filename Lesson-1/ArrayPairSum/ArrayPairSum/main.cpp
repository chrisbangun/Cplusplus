//
//  main.cpp
//  ArrayPairSum
//
//  Created by Adi Bangun on 09/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[]={1,2,3,4,4,5,6,6,7};
    int target = 8; // {(2,6),(4,4),(1,7),(3,5)}
    int size = sizeof(arr)/sizeof(*arr);
    //base case
    if(size==0)
        cout << "no data in the array" << endl;
    else if(target <= 0)
        cout << "the target can't be zero or negative" << endl;
    else{
        qsort(arr,size,sizeof(int),compare);
        int _pL = 0;
        int _pR = size-1;
        int currentSum = 0;
        while(_pL < _pR){
            currentSum = arr[_pL] + arr[_pR];
            if(currentSum==target){
                cout << arr[_pL] << "," << arr[_pR] << endl;
                _pL++;
            }
            else if(currentSum < target)
                _pL++;
            else _pR--;
                
        }
    }
    return 0;
}
