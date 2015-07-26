//
//  main.cpp
//  MajorityElement
//
//  Created by Adi Bangun on 02/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
using namespace std;
// Majority Element: A majority element in an array A[] of size n
// is an element that appears more than n/2 times (and hence, there is at most one such element)
// this solution is using the Moore's Voting Algorithm

int findMajorityElement(int arr[], int n){
    int count = 0;
    int majorityElement=0;
    for(int i=0;i<n;i++){
        if(count==0)
            majorityElement = arr[i];
        if(arr[i]== majorityElement)
            count++;
        else
            count--;
    }
    count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==majorityElement)
            count++;
    }
    if(count > n/2)
        return majorityElement;
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin >> N;
    int arr[N+1];
    for(int i=0;i<N;i++)
        cin >> arr[i];
    cout << findMajorityElement(arr,N);
    return 0;
}
